#include "TollgateMapLayer.h"
#include "SimpleAudioEngine.h"
#include "HeroManager.h"
#include "MonsterManager.h"
#include "Monster.h"
#include "MonsterPos.h"
#include "cocos-ext.h"
#include "editor-support\cocostudio\CCSGUIReader.h"
#include "ui\CocosGUI.h"
#include "GlobalDefine.h"
#include "GlobalClient.h"
USING_NS_CC_EXT;
using namespace cocos2d::ui;
using namespace cocostudio;

#define HOME_LAYER_LVL 3			//堡垒层
#define HERO_LAYER_LVL 10			//英雄层
#define MONSTER_LAYER_LVL 15	//怪物层
#define BULLET_LAYER_LVL 20		//子弹层

TollgateMapLayer::TollgateMapLayer()
{
	m_iCurLevel = GlobalClient::getInstance()->getiCurTollgateLevel();
}

TollgateMapLayer::~TollgateMapLayer()
{
}

bool TollgateMapLayer::init()
{
	/*读取关卡配置*/
	loadConfig();
		
	/*创建英雄管理器*/
	m_heroMgr = HeroManager::createWithLevel(m_iCurLevel);
	this->addChild(m_heroMgr, HERO_LAYER_LVL);
	/*创建怪物管理器*/
	m_monsterMgr = MonsterManager::createWithLevel(m_iCurLevel);
	this->addChild(m_monsterMgr, MONSTER_LAYER_LVL);
	/*创建起始点*/
	createStartPoint();
	/*创建终点*/
	createEndPoint();
	this->schedule(schedule_selector(TollgateMapLayer::logic));
	return true;
}

void TollgateMapLayer::initData()
{
	int iTowerSoulNum = 5;
	int iMonsterNum = m_monsterMgr->getNotShowMonsterCount();
	int iMagicNum = 100;

	NOTIFY->postNotification("TowerSoulChange", (Ref*)iTowerSoulNum);
	NOTIFY->postNotification("MonsterNumChange", (Ref*)iMonsterNum);
	NOTIFY->postNotification("MagicChange", (Ref*)iMagicNum);
}

void TollgateMapLayer::logic(float dt)
{
	m_heroMgr->logic(dt, m_monsterMgr->getMonsterList());
}

void TollgateMapLayer::loadConfig()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	/*加载背景音乐*/
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(
		StringUtils::format("music/tollgate_%d.mp3", m_iCurLevel).c_str(), true);

	/*加载地图背景*/
	std::string sBG = StringUtils::format("tollgate/level_%d.jpg", m_iCurLevel);
	Sprite* map = Sprite::create(sBG.c_str());
	map->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(map, 1);
}


void TollgateMapLayer::createStartPoint()
{
	MonsterPos* pos = m_monsterMgr->getMonsterStartPos();

	Sprite* startSp = Sprite::create("sprite/start.png");
	startSp->setPosition(pos->getPos());

	auto rotateBy = RotateBy::create(15.0f, 360, 360);
	auto repeat = RepeatForever::create(rotateBy);
	startSp->runAction(repeat);

	this->addChild(startSp, HOME_LAYER_LVL);
}

void TollgateMapLayer::createEndPoint()
{
	MonsterPos* pos = m_monsterMgr->getMonsterEndPos();

	Sprite* home = Sprite::create("sprite/end.png");
	home->setPosition(pos->getPos());

	auto rotateBy = RotateBy::create(15.0f, 360, 360);
	auto repeat = RepeatForever::create(rotateBy);
	home->runAction(repeat);

	this->addChild(home, HOME_LAYER_LVL);
}