#include "ControllerMoveBase.h"

ControllerMoveBase::ControllerMoveBase()
{
	m_isMoving = false;
	m_isXLeft = false;
	m_isYUp = false;
	m_iSpeed = SPEED;
	m_iCheckMoveSpeed = CHECK_MOVE_SPEED_LVL2;
	m_entity = NULL;
}
ControllerMoveBase::~ControllerMoveBase()
{
}

Point ControllerMoveBase::getNextPos(Point curPos, Point destPos)
{
	if (curPos.x > destPos.x)
	{
		m_isXLeft = true;
	}
	else
	{
		m_isXLeft = false;
	}

	if (curPos.y < destPos.y)
	{
		m_isYUp = true;
	}
	else
	{
		m_isYUp = false;
	}

	/*根据移动方向和速度值改变当前坐标*/
	if (curPos.x < destPos.x&&m_isXLeft == false)
	{
		curPos.x += m_iSpeed;
		if (curPos.x>destPos.x)
		{
			curPos.x = destPos.x;
		}
	}
	else if (curPos.x>destPos.x&&m_isXLeft == true)
	{
		curPos.x -= m_iSpeed;
		if (curPos.x<destPos.x)
		{
			curPos.x = destPos.x;
		}
	}

	if (curPos.y < destPos.y&&m_isYUp == true)
	{
		curPos.y += m_iSpeed;
		if (curPos.y >destPos.y)
		{
			curPos.y = destPos.y;
		}
	}
	else if (curPos.y>destPos.y&&m_isYUp == false)
	{
		curPos.y -= m_iSpeed;
		if (curPos.y <destPos.y)
		{
			curPos.y = destPos.y;
		}
	}
	return curPos;
}

void ControllerMoveBase::bindMoveEndFunc(std::function<void()>moveEndFunc)
{
	m_moveEndFunc = moveEndFunc;
}