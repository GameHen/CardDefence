#ifndef _BulletBase_H_
#define _BulletBase_H_
#include "Entity.h"
/* 子弹速度 */
#define SPEED_DEFAULT 10
#define SPEED_NORMAL 5

class BulletBase:public Entity
{
public:
	BulletBase();
	~BulletBase();

	void lockAim(Entity* entity);			/*锁定攻击目标*/
	void unLockAim();							/*解锁攻击目标*/
	Entity* getAim();								/*获取攻击目标*/
	bool isArrive();								/*是否击中*/

	void setUsed(bool isUsed);			/*是否正在使用*/
	bool isUsed();
protected:
	/*锁定攻击目标时调用，留给子类处理*/
	virtual void onLockAim(Entity* aim) = 0;
	/*是否攻中目标*/
	bool m_isArrive;
private:
	bool m_isUsed;	//标记是否已经使用中
	Entity* m_aim;		//攻击目标

	CC_SYNTHESIZE(int, m_iAtkValue, iAtkValue);//攻击值
	CC_SYNTHESIZE(int, m_iSpeed, iSpeed);//速度
};
#endif//_BulletBase_H_