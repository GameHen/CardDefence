#ifndef _TollgateMapLayer_H_
#define _TollgateMapLayer_H_
#include "cocos2d.h"
USING_NS_CC;

class HeroManager;
class MonsterManager;
class TollgateMapLayer:public Layer
{
public:
	TollgateMapLayer();
	~TollgateMapLayer();

	CREATE_FUNC(TollgateMapLayer);

	virtual bool init();
	/*创建起始点*/
	void createStartPoint();
	/*创建终点*/
	void createEndPoint();
	
	void initData();
private:
	/*当前关卡*/
	int m_iCurLevel;
	/*读取关卡配置*/
	void loadConfig();

	HeroManager* m_heroMgr;
	MonsterManager* m_monsterMgr;
	void logic(float dt);
};


#endif//_TollgateMapLayer_H_