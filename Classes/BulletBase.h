#ifndef _BulletBase_H_
#define _BulletBase_H_
#include "Entity.h"
/* �ӵ��ٶ� */
#define SPEED_DEFAULT 10
#define SPEED_NORMAL 5

class BulletBase:public Entity
{
public:
	BulletBase();
	~BulletBase();

	void lockAim(Entity* entity);			/*��������Ŀ��*/
	void unLockAim();							/*��������Ŀ��*/
	Entity* getAim();								/*��ȡ����Ŀ��*/
	bool isArrive();								/*�Ƿ����*/

	void setUsed(bool isUsed);			/*�Ƿ�����ʹ��*/
	bool isUsed();
protected:
	/*��������Ŀ��ʱ���ã��������ദ��*/
	virtual void onLockAim(Entity* aim) = 0;
	/*�Ƿ���Ŀ��*/
	bool m_isArrive;
private:
	bool m_isUsed;	//����Ƿ��Ѿ�ʹ����
	Entity* m_aim;		//����Ŀ��

	CC_SYNTHESIZE(int, m_iAtkValue, iAtkValue);//����ֵ
	CC_SYNTHESIZE(int, m_iSpeed, iSpeed);//�ٶ�
};
#endif//_BulletBase_H_