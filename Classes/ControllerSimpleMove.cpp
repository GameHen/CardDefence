#include "ControllerSimpleMove.h"
ControllerSimpleMove::ControllerSimpleMove()
{
	m_fMoveTimeCount = 0;
	m_MoveSpan = 0;
}

ControllerSimpleMove::~ControllerSimpleMove()
{
	CC_SAFE_RELEASE(m_curDestPos);
}

ControllerSimpleMove* ControllerSimpleMove::create(Entity* entity)
{
	ControllerSimpleMove* ctrlSimpleMove = new ControllerSimpleMove();
	if (ctrlSimpleMove&&ctrlSimpleMove->init(entity))
	{
		ctrlSimpleMove->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ctrlSimpleMove);
	}
	return ctrlSimpleMove;
}

bool ControllerSimpleMove::init(Entity* entity)
{
	this->m_entity = entity;
	this->schedule(schedule_selector(ControllerSimpleMove::checkMoveUpdate));
	return true;
}

void ControllerSimpleMove::checkMoveUpdate(float delta)
{
	if (m_isMoving)
	{
		m_fMoveTimeCount += delta * 1000;
		if (m_fMoveTimeCount >= m_MoveSpan)
		{
			m_fMoveTimeCount = 0;
			moveOneStep();
		}
	}
}

void ControllerSimpleMove::moveByPosList(Vector<PosBase*>posList)
{
	if (posList.size() < 1)
		return;
	this->m_movePosList.clear();
	this->m_movePosList.pushBack(posList);

	nextMovePos();

	this->m_isMoving = true;
}

void ControllerSimpleMove::moveByPosList(Vector<PosBase*>posList, int iSpeed)
{
	this->m_iSpeed = iSpeed;
	moveByPosList(posList);
}

void ControllerSimpleMove::moveByPosList(Vector<PosBase*>posList, int iSpeed, int iSpanTime)
{
	m_MoveSpan = iSpanTime;
	moveByPosList(posList, iSpeed);
}

void ControllerSimpleMove::moveByPos(PosBase* pos)
{
	if (m_isMoving == false && pos != NULL)
	{
		Vector<PosBase*> posList;
		posList.pushBack(pos);
		moveByPosList(posList);
	}
}

void ControllerSimpleMove::moveOneStep()
{
	Sprite* sprite = m_entity->getSprite();
	if (sprite != NULL)
	{
		Point entityPos = m_entity->getPosition();
		Point curDestPos = m_curDestPos->getPos();
		/*取得下一个移动坐标点*/
		entityPos = getNextPos(entityPos, curDestPos);

		/*移动实体*/
		m_entity->setPosition(entityPos);

		/*到达当前目的地，开始下一个目的地*/
		if (entityPos.x == curDestPos.x&&entityPos.y == curDestPos.y)
		{
			if (m_movePosList.size() > 0)
				nextMovePos();
			else
			{
				if (m_moveEndFunc)
				{
					m_moveEndFunc();
					m_moveEndFunc = nullptr;
				}
			}
		}
	}
}
void ControllerSimpleMove::nextMovePos()
{
	if (m_movePosList.size() < 1) 
		return;
	m_curDestPos = m_movePosList.at(0);

	m_movePosList.erase(0);
}