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

	void hurtMe(int iHurtValue);					/*被攻击*/
	bool isDead();											/*是否死亡*/
protected:
	virtual void onDead();								/*实体死亡时调用*/
	virtual void onBindSprite();						/*绑定精灵对象时调用*/
	virtual void onHurt(int iHurtValue);		/*受伤时调用*/
private:
	Sprite* m_sprite;
	bool m_isDead;//标记是否死亡

	CC_SYNTHESIZE(int, m_ID, ID);								/*实体ID*/
	CC_SYNTHESIZE(int, m_iModeID, iModeID);			/*模型ID*/
	CC_SYNTHESIZE(std::string, m_sName, sName);	/*名字*/
	CC_SYNTHESIZE(int, m_iHP, iHP);							/*血量值*/
	CC_SYNTHESIZE(int, m_iDefense, iDefense);			/*防御力*/
	CC_SYNTHESIZE(int, m_iSpeed, iSpeed);				/*速度值*/
	CC_SYNTHESIZE(int, m_iLevel, iLevel);					/*等级*/
};

#endif//_Entity_H_