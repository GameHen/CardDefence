#ifndef _PosBase_H__
#define _PosBase_H__
#include "cocos2d.h"
using namespace cocos2d;

class PosBase:public Layer
{
public:
	PosBase();
	~PosBase();

	static PosBase * create(Point pos);
	static PosBase * create(Point pos, bool isDebug);
	bool init(Point pos);
	bool init(Point pos, bool isDebug);

	CC_SYNTHESIZE(Point, m_pos, Pos);

	virtual bool isClickMe(Point pos);//�ж������Ƿ���뷶Χ
	void setDebug(bool isDebug);//������رյ���ģʽ
protected:
	bool m_isDebug;
};

#endif//_PosBase_H__