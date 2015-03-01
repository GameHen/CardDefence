#include "TowerPosEditorLayer.h"
#include "PosLoadUtil.h"
TowerPosEditorLayer::TowerPosEditorLayer()
{
	m_iCurLevel = 1;
	//m_enMode = enTowerPos//默认炮台模式
	m_enMode = enMonsterPos;
}

TowerPosEditorLayer::~TowerPosEditorLayer()
{
}

bool TowerPosEditorLayer::init()
{
	if (!Layer::init()) return false;

	//监听触摸事件
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [](Touch *touch, Event *event){
		return true;
	};
	listener->onTouchEnded = [&](Touch *touch, Event *event){
		Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());
		
		switch (m_enMode)
		{
		case enTowerPos:
			editTowerPos(pos);
			break;
		case enMonsterPos:
			editMonsterPos(pos);
			break;
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//读取配置文件
	this->loadConfigFile();
	return true;
}


void TowerPosEditorLayer::editTowerPos(Point pos)
{
	PosBase* existPos = findExistTowerPos(pos);
	if (existPos != NULL)
		deleteTowerPos(existPos);
	else
		createTowerPos(pos);
}
void TowerPosEditorLayer::editMonsterPos(Point pos)
{
	PosBase* existPos = findExistMonsterPos(pos);
	if (existPos != NULL)
		deleteMonsterPos(existPos);
	else
		createMonsterPos(pos);
}


PosBase* TowerPosEditorLayer::findExistTowerPos(Point pos)
{
	for (auto basePos : m_towerPosList)
	{
		if (basePos->isClickMe(pos))
			return basePos;
	}
	return NULL;
}
PosBase* TowerPosEditorLayer::findExistMonsterPos(Point pos)
{
	for (auto basePos : m_monsterPosList)
	{
		if (basePos->isClickMe(pos))
			return basePos;
	}
	return NULL;
}


void TowerPosEditorLayer::createTowerPos(Point pos)
{
	TowerPos *tPos = TowerPos::create(pos,true);
	this->addChild(tPos);
	m_towerPosList.pushBack(tPos);
}
void TowerPosEditorLayer::createMonsterPos(Point pos)
{
	MonsterPos *mPos = MonsterPos::create(pos, true);
	this->addChild(mPos,10);
	m_monsterPosList.pushBack(mPos);
}


void TowerPosEditorLayer::deleteTowerPos(PosBase* existPos)
{
	this->removeChild(existPos);
	m_towerPosList.eraseObject(existPos);
}
void TowerPosEditorLayer::deleteMonsterPos(PosBase* existPos)
{
	this->removeChild(existPos);
	m_monsterPosList.eraseObject(existPos);
}


void TowerPosEditorLayer::deleteAllPos()
{
	this->removeAllChildrenWithCleanup(true);
	m_towerPosList.clear();
	m_monsterPosList.clear();
}

void TowerPosEditorLayer::outputPosToPlistFile(Vector<PosBase*> posList, const char* sFilePath)
{
	ValueMap fileDataMap;
	int index = 1;
	for (auto posBase : posList)
	{
		ValueMap data;
		data["x"] = posBase->getPos().x;
		data["y"] = posBase->getPos().y;

		fileDataMap[StringUtils::toString(index)] = Value(data);
		index++;
	}
	FileUtils::getInstance()->writeToFile(fileDataMap, sFilePath);
}

void TowerPosEditorLayer::outputPosToPlistFile() {
	/* 输出炮台坐标配置文件 */
	std::string sTowerPosPath = StringUtils::format("tollgate/towerPos_level_%d.plist", m_iCurLevel);
	outputPosToPlistFile(m_towerPosList, sTowerPosPath.c_str());

	/* 输出怪物坐标配置文件 */
	std::string sMonsterPosPath = StringUtils::format("tollgate/monsterPos_level_%d.plist", m_iCurLevel);
	outputPosToPlistFile(m_monsterPosList, sMonsterPosPath.c_str());
}
void TowerPosEditorLayer::loadConfigFile()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//添加地图背景
	std::string sBG = StringUtils::format("tollgate/level_%d.jpg", m_iCurLevel);
	Sprite* map = Sprite::create(sBG.c_str());
	map->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(map, 0);
	/***************加载塔坐标对象****************/
	std::string sTowerPosPath = StringUtils::format("tollgate/towerPos_level_%d.plist", m_iCurLevel);
	Vector<PosBase*>posList = PosLoadUtil::getInstance()->loadPosWithFile(sTowerPosPath.c_str(), enTowerPos, this, 10, true);
	m_towerPosList.pushBack(posList);
	/***************加载怪物坐标对象**************/
	std::string sMonstPosPath = StringUtils::format("tollgate/MonsterPos_level_%d.plist", m_iCurLevel);
	posList = PosLoadUtil::getInstance()->loadPosWithFile(sMonstPosPath.c_str(), enMonsterPos, this, 10, true);
	m_monsterPosList.pushBack(posList);
}

void TowerPosEditorLayer::changeMode()
{
	if (m_enMode == enMonsterPos)
		m_enMode = enTowerPos;
	else
		m_enMode = enMonsterPos;
}

int TowerPosEditorLayer::nextLevel()
{
	deleteAllPos();
	m_iCurLevel++;
	loadConfigFile();

	return m_iCurLevel;
}

int TowerPosEditorLayer::preLevel()
{
	deleteAllPos();
	m_iCurLevel--;
	loadConfigFile();

	return m_iCurLevel;
}

Vector<PosBase*> TowerPosEditorLayer::getMonsterPosList()
{
	return m_monsterPosList;
}