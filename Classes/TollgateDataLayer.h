#ifndef _TollgateDataLayer_H_
#define _TollgateDataLayer_H_
#include "cocos2d.h"
#include "editor-support\cocostudio\CCSGUIReader.h"
#include "ui\CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;
USING_NS_CC;
class TollgateDataLayer:public Layer
{
public:
	TollgateDataLayer();
	~TollgateDataLayer();

	CREATE_FUNC(TollgateDataLayer);
	virtual bool init();

	int getiTowerSoulNum();
	int getiMagicNum();
private:
	void recvRefreshTowerSoulNum(Ref* pData);
	void recvRefreshMonsterNum(Ref* pData);
	void recvRefreshMagicNum(Ref* pData);
	void recvAllMonsterDead(Ref* pData);

	int m_iTowerSoulNum;
	int m_iMonsterNum;
	int m_iMagicNum;

	Text* m_towerSoulLab;
	Text* m_monsterLab;
	Text* m_magicLab;
};
#endif//_TollgateDataLayer_H_