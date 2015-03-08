#ifndef _Entity_H_
#define _Entity_H_
#include "cocos2d.h"
USING_NS_CC;
class Entity:public Node
{
public:
	Entity();
	~Entity();

	void  bindSprite(Sprite *sprite);
	Sprite* getSprite();

	void hurtMe(int iHurtValue);					/*������*/
	bool isDead();											/*�Ƿ�����*/
protected:
	virtual void onDead();								/*ʵ������ʱ����*/
	virtual void onBindSprite();						/*�󶨾������ʱ����*/
	virtual void onHurt(int iHurtValue);		/*����ʱ����*/
private:
	Sprite* m_sprite;
	bool m_isDead;//����Ƿ�����

	CC_SYNTHESIZE(int, m_ID, ID);								/*ʵ��ID*/
	CC_SYNTHESIZE(int, m_iModeID, iModeID);			/*ģ��ID*/
	CC_SYNTHESIZE(std::string, m_sName, sName);	/*����*/
	CC_SYNTHESIZE(int, m_iHP, iHP);							/*Ѫ��ֵ*/
	CC_SYNTHESIZE(int, m_iDefense, iDefense);			/*������*/
	CC_SYNTHESIZE(int, m_iSpeed, iSpeed);				/*�ٶ�ֵ*/
	CC_SYNTHESIZE(int, m_iLevel, iLevel);					/*�ȼ�*/
};

#endif//_Entity_H_