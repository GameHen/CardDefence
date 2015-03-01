#ifndef _MonsterPos_H__
#define _MonsterPos_H__
#include "cocos2d.h"
#include "PosBase.h"
USING_NS_CC;

class Monster;
class MonsterPos :public PosBase
{
public:
	MonsterPos();
	~MonsterPos();

	static MonsterPos* create(Point pos);
	static MonsterPos* create(Point pos,bool isDebug);
	virtual bool init(Point pos);
	virtual bool init(Point pos, bool isDebug);

	virtual bool isClickMe(Point pos, bool isDebug);
	void draw(Renderer* renderer, const kmMat4 &transform, bool transformUpdated);
private:
	void onDraw(const kmMat4 &transform, bool transformUpdated);
	CustomCommand _customCommand;

	Monster* m_monster;
};


#endif//_MonsterPos_H__