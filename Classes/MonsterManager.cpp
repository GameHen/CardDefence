#include "MonsterManager.h"
#include "PosLoadUtil.h"
#include "MonsterPos.h"
#include "PosBase.h"
#include"Monster.h"
#include "GlobalDefine.h"
MonsterManager::MonsterManager()
{
	m_fShowTimeCount = 0;
	
}

MonsterManager::~MonsterManager()
{
}

void MonsterManager::logic(float dt)
{
	Vector<Monster*> monsterWantToDelete;
	for (auto monster : m_monsterList)
	{
		if (monster->isMoveEnd() == true)
			monsterWantToDelete.pushBack(monster);
		else if (monster->isDead() == true)
			monsterWantToDelete.pushBack(monster);
	}

	for (auto monster : monsterWantToDelete)
	{
		monster->removeFromParent();
		m_monsterList.eraseObject(monster);
	}
	if (m_monsterList.size() == 0)
		NOTIFY->postNotification("AllMonsterDead");
}

MonsterManager* MonsterManager::createWithLevel(int iCurLevel)
{
	MonsterManager* monsterMgr = new MonsterManager();
	if (monsterMgr&&monsterMgr->initWithLevel(iCurLevel))
	{
		monsterMgr->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(monsterMgr);
	}
	return monsterMgr;
}
bool MonsterManager::initWithLevel(int iCurLevel)
{
	/*创建怪物*/
	createMonsters(iCurLevel);

	return true;
}


int MonsterManager::getNotShowMonsterCount()
{
	return m_notShowMonsterList.size();
}
MonsterPos* MonsterManager::getMonsterStartPos()
{
	return (MonsterPos*)m_monsterPosList.at(0);
}
MonsterPos* MonsterManager::getMonsterEndPos()
{
	return (MonsterPos*)m_monsterPosList.at(m_monsterPosList.size() - 1);
}

Vector<Monster*> MonsterManager::getMonsterList()
{
	return m_monsterList;
}

void MonsterManager::showMonster(float dt)
{
	int iNotShowMonsterCount = m_notShowMonsterList.size();
	if (iNotShowMonsterCount > 0)
	{
		m_fShowTimeCount += dt;
	}
	/*获取怪物的第一个坐标点*/
	auto monsterFirstPos = getMonsterStartPos();
	Vector<Monster*>monsterWantToDelete;
	for (auto monster : m_notShowMonsterList)
	{
		/*时间达到怪物的出场时间，让怪物出场*/
		if (m_fShowTimeCount >= monster->getfShowTime())
		{
			/*添加怪物到删除列表，出场后的怪物要从未出场列表中删除*/
			monsterWantToDelete.pushBack(monster);

			monster->setPosition(monsterFirstPos->getPos());
			monster->setVisible(true);

			/*让怪物按照指定坐标走*/
			monster->moveByPosList(m_monsterPosList);
		}
	}
	for (auto monster : monsterWantToDelete)
	{
		m_notShowMonsterList.eraseObject(monster);
	}
	int iMonsterNumChange = -monsterWantToDelete.size();
	NOTIFY->postNotification("MonsterNumChange", (Ref*)iMonsterNumChange);
}

void MonsterManager::createMonsters(int iCurLevel)
{
	/*加载怪物坐标文件*/
	std::string sMonsterPosPath = StringUtils::format("tollgate/monsterPos_level_%d.plist", iCurLevel);
	auto posList = PosLoadUtil::getInstance()->loadPosWithFile(sMonsterPosPath.c_str(), enMonsterPos, this, 10, false);
	m_monsterPosList.pushBack(posList);

	/*读取配置文件*/
	std::string sMonsterConfPath = StringUtils::format("tollgate/monster_level_%d.plist", iCurLevel);

	ValueMap fileDataMap = FileUtils::getInstance()->getValueMapFromFile(sMonsterConfPath.c_str());
	
	int size = fileDataMap.size();
	for (int i = 1; i <= size; i++)
	{
		Value value = fileDataMap.at(StringUtils::toString(i));
		ValueMap data = value.asValueMap();

		/*从怪物出场配置文件读取怪物ID和出场时间，保存所有怪物到未出场列表*/
		int id = data["id"].asInt();
		float fShowTime = data["showTime"].asFloat();

		auto monster = Monster::createFromCsvFileByID(id);
		monster->setfShowTime(fShowTime);
		monster->setVisible(false);

		/*设置怪物精灵*/
		std::string spPath = StringUtils::format("sprite/monster/monster_%d.png", monster->getiModeID());
		monster->bindSprite(Sprite::create(spPath.c_str()));
		/*保存怪物对象到怪物列表*/
		m_monsterList.pushBack(monster);
		/*保存怪物对象到未出场怪物列表*/
		m_notShowMonsterList.pushBack(monster);

		this->addChild(monster);
	}
	this->schedule(schedule_selector(MonsterManager::showMonster));
	this->schedule(schedule_selector(MonsterManager::logic));
}