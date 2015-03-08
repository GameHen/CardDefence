#include "TowerPos.h"
#define RADIUS 32
TowerPos::TowerPos()
{
	m_pos = Point(0, 0);
	m_isDebug = false;
}

TowerPos::~TowerPos()
{
}

TowerPos* TowerPos::create(Point pos)
{
	TowerPos *tPos = new TowerPos();
	if (tPos&&tPos->init(pos))
		tPos->autorelease();
	else
		CC_SAFE_DELETE(tPos);
	return tPos;
}
TowerPos* TowerPos::create(Point pos, bool isDebug)
{
	TowerPos *tPos = new TowerPos();
	if (tPos&&tPos->init(pos, isDebug))
		tPos->autorelease();
	else
		CC_SAFE_DELETE(tPos);
	return tPos;
}
bool TowerPos::init(Point pos)
{
	bool Ret = false;
	do{
		CC_BREAK_IF(!PosBase::init(pos));

		Ret = true;
	} while (0);
	return Ret;
}
bool TowerPos::init(Point pos, bool isDebug)
{
	bool Ret = false;
	do{
		CC_BREAK_IF(!PosBase::init(pos, isDebug));
		m_isDebug = isDebug;
		Ret = true;
	} while (0);
	return Ret;
}

void TowerPos::draw(Renderer* renderer, const kmMat4 &transform, bool transformUpdated)
{
	if (m_isDebug)
	{
		_customCommand.init(_globalZOrder);
		_customCommand.func = CC_CALLBACK_0(TowerPos::onDraw,
			this, transform, transformUpdated);
		renderer->addCommand(&_customCommand);
	}
}

void TowerPos::onDraw(const kmMat4 &transform, bool transformUpdated)
{
	kmGLPushMatrix();
	kmGLLoadMatrix(&transform);
	//…Ë÷√ª≠± ¥÷œ∏
	glLineWidth(5.0f);
	//ªÊ÷∆æÿ–Œ
	Point srcPos = Point(m_pos.x - RADIUS,m_pos.y+RADIUS);
	Point destPos = Point(m_pos.x + RADIUS, m_pos.y - RADIUS);
	DrawPrimitives::drawRect(srcPos, destPos);
	//ª÷∏¥ª≠± ¥÷œ∏
	glLineWidth(1);
	kmGLPopMatrix();
}

bool TowerPos::isClickMe(Point pos)
{
	Point srcPos = Point(m_pos.x - RADIUS, m_pos.y + RADIUS);
	Point destPos = Point(m_pos.x + RADIUS, m_pos.y - RADIUS);

	if (srcPos.x <= pos.x&&pos.x <= destPos.x&&destPos.y <= pos.y&&pos.y <= srcPos.y)
		return true;

	return false;
}