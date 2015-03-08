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
	/*������ʼ��*/
	void createStartPoint();
	/*�����յ�*/
	void createEndPoint();
	
	void initData();
private:
	/*��ǰ�ؿ�*/
	int m_iCurLevel;
	/*��ȡ�ؿ�����*/
	void loadConfig();

	HeroManager* m_heroMgr;
	MonsterManager* m_monsterMgr;
	void logic(float dt);
};


#endif//_TollgateMapLayer_H_