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

	virtual bool isClickMe(Point pos);//判断坐标是否进入范围
	void setDebug(bool isDebug);//开启或关闭调试模式
protected:
	bool m_isDebug;
};

#endif//_PosBase_H__