#include "TollgateDataLayer.h"
#include "GlobalDefine.h"
#include "SceneManager.h"
TollgateDataLayer::TollgateDataLayer()
{
	m_iTowerSoulNum = 0;
	m_iMonsterNum = 0;
	m_iMagicNum = 0;
}

TollgateDataLayer::~TollgateDataLayer()
{
	NOTIFY->removeAllObservers(this);
}

bool TollgateDataLayer::init()
{
	if (!Layer::init())
		return false;
	/*加载UI*/
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("TollgateUI/TollgateUI_1.ExportJson");
	this->addChild(UI);
	UI->setTouchEnabled(false);

	/*塔魂标签*/
	m_towerSoulLab = (Text*)Helper::seekWidgetByName(UI, "towerSoulLab");
	/*怪物标签*/
	m_monsterLab = (Text*)Helper::seekWidgetByName(UI, "monsterNumLab");
	/*魔力标签*/
	m_magicLab = (Text*)Helper::seekWidgetByName(UI, "magicLab");

	/*****************订阅消息******************/
	NOTIFY->addObserver(
		this, callfuncO_selector(TollgateDataLayer::recvRefreshTowerSoulNum), "TowerSoulChange", NULL);
	NOTIFY->addObserver(
		this, callfuncO_selector(TollgateDataLayer::recvRefreshMonsterNum), "MonsterNumChange", NULL);
	NOTIFY->addObserver(
		this, callfuncO_selector(TollgateDataLayer::recvRefreshMagicNum), "MagicChange", NULL);
	NOTIFY->addObserver(
		this, callfuncO_selector(TollgateDataLayer::recvAllMonsterDead), "AllMonsterDead", NULL);
	return true;
}

void TollgateDataLayer::recvRefreshTowerSoulNum(Ref* pData)
{
	int iAltValue = (int)pData;
	m_iTowerSoulNum += iAltValue;
	m_towerSoulLab->setText(StringUtils::toString(m_iTowerSoulNum));
}
void TollgateDataLayer::recvRefreshMonsterNum(Ref* pData)
{
	int iAltValue = (int)pData;
	m_iMonsterNum += iAltValue;
	m_monsterLab->setText(StringUtils::toString(m_iMonsterNum));
}
void TollgateDataLayer::recvRefreshMagicNum(Ref* pData)
{
	int iAltValue = (int)pData;
	m_iMagicNum += iAltValue;
	m_magicLab->setText(StringUtils::toString(m_iMagicNum));

	if (m_iMagicNum <= 0)
	{
		SceneManager::getInstance()->changeScene(SceneManager::en_GameOverScene);
	}
}

int TollgateDataLayer::getiTowerSoulNum()
{
	return m_iTowerSoulNum;
}
int TollgateDataLayer::getiMagicNum()
{
	return m_iMagicNum;
}

void TollgateDataLayer::recvAllMonsterDead(Ref* pData)
{
	if (m_iMagicNum > 0)
		SceneManager::getInstance()->changeScene(SceneManager::en_WinScene);
}