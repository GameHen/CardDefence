#ifndef _TowerPos_H__
#define _TowerPos_H__
#include "PosBase.h"
using namespace cocos2d;


class TowerPos:public PosBase
{
public:
	TowerPos();
	~TowerPos();

	static TowerPos* create(Point pos);
	static TowerPos* create(Point pos,bool isDebug);
	bool init(Point pos);
	bool init(Point pos, bool isDebug);

	virtual bool isClickMe(Point pos) override;
	void draw(Renderer* renderer, const kmMat4 &transform, bool transformUpdated);
private:
	void onDraw(const kmMat4 &transform, bool transformUpdated);
	CustomCommand _customCommand;
};
#endif//_TowerPos_H__