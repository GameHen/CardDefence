#include "BulletManager.h"
#include "BulletNormal.h"
BulletManager::BulletManager()
{
}
BulletManager::~BulletManager()
{
}

BulletManager* BulletManager::create()
{
	BulletManager* bulletMgr = new BulletManager();
	if (bulletMgr&&bulletMgr->init())
	{
		bulletMgr->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(bulletMgr);
	}
	return bulletMgr;
}

bool BulletManager::init()
{
	/*创建子弹的对象*/
	createBullets();
	/*循环检查子弹逻辑*/
	this->schedule(schedule_selector(BulletManager::bulletLogicCheck));
	return true;
}

void BulletManager::createBullets()
{
	BulletBase* bullet = NULL;
	for (int i = 0; i < BULLET_MAX_CACHE_NUM; i++)
	{
		bullet = BulletNormal::create();

		bullet->setUsed(false);
		m_bulletList.pushBack(bullet);

		this->addChild(bullet);
	}
}

void BulletManager::bulletLogicCheck(float dt)
{
	for (auto bullet : m_bulletList)
	{
		auto aim = bullet->getAim();

		if (aim != NULL)
		{
			/*判断子弹是击中目标，如是，则伤害目标*/
			if (bullet->isArrive())
			{
				aim->hurtMe(bullet->getiAtkValue());
				if (aim->isDead())
					bullet->unLockAim();
				/*子弹攻击目标后，重置为未使用状态*/
				bullet->setUsed(false);
			}
		}
	}
}
BulletBase* BulletManager::getAnyUnUsedBullet()
{
	for (auto bullet : m_bulletList)
	{
		if (bullet->isUsed() == false)
		{
			bullet->setUsed(true);
			return bullet;
		}
	}

	return NULL;
}