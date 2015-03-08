#include "PosBase.h"
PosBase::PosBase()
{
	m_pos = Point(0, 0);
	m_isDebug = false;
}

PosBase::~PosBase()
{
}

PosBase *PosBase::create(Point pos)
{
	PosBase *tPos = new PosBase();
	if (tPos&&tPos->init(pos))
		tPos->autorelease();
	else
		CC_SAFE_DELETE(tPos);
	return tPos;
}

PosBase *PosBase::create(Point pos,bool isDebug)
{
	PosBase *tPos = new PosBase();
	if (tPos&&tPos->init(pos, isDebug))
		tPos->autorelease();
	else
		CC_SAFE_DELETE(tPos);
	return tPos;
}

bool PosBase::init(Point pos)
{
	bool Ret = false;
	do{
		setPos(pos);
		Ret = true;
	} while (0);
	return Ret;
}

bool PosBase::init(Point pos, bool isDebug)
{
	bool Ret = false;
	do{
		CC_BREAK_IF(!init(pos));

		Ret = true;
	} while (0);
	return Ret;
}

bool PosBase::isClickMe(Point pos)
{
	return false;
}

void PosBase::setDebug(bool isDebug)
{
	this->m_isDebug = isDebug;
}