#ifndef _HeroManager_H_
#define _HeroManager_H_
#include "cocos2d.h"
#include "PosBase.h"
USING_NS_CC;

#define TOWER_POS_LAYER_LVL 5
#define TOWER_BORDER_LAYER_LVL 8
#define TOWER_LAYER_LVL     10

class TowerBorder;
class Monster;
class HeroManager :public Node
{
public:
	HeroManager();
	~HeroManager();
	static HeroManager* createWithLevel(int iCurLevel);
	bool initWithLevel(int iCurLevel);
	void logic(float dt, Vector<Monster*>  MonsterList);
private:
	Vector<PosBase *> m_towerPosList;
	Vector<TowerBorder*> m_towerBorderList;
	void createTowerBorder(int iCurLevel);
	void createTowerPos(Point pos);
	/*找到被单击的炮台对象*/
	TowerBorder* findClickTowerBorder(Point pos);

};

#endif//_HeroManager_H_