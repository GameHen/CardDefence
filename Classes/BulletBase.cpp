#include "BulletBase.h"

BulletBase::BulletBase()
{
	m_isUsed = false;
	m_aim = NULL;
	m_iSpeed = SPEED_DEFAULT;
	m_iAtkValue = 1;
}

BulletBase::~BulletBase()
{
}

void BulletBase::setUsed(bool isUsed)
{
	this->m_isUsed = isUsed;
	setVisible(isUsed);
}

bool BulletBase::isUsed()
{
	return this->m_isUsed;
}

void BulletBase::lockAim(Entity* entity)
{
	if (entity != NULL)
	{
		m_aim = entity;
		onLockAim(m_aim);
	}
}

void BulletBase::unLockAim()
{
	m_aim = NULL;
}


Entity* BulletBase::getAim()
{
	return this->m_aim;
}

bool BulletBase::isArrive()
{
	return m_isArrive;
}