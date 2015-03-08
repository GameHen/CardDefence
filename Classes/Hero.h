#ifndef _Hero_H_
#define _Hero_H_
#include "Entity.h"
class Monster;
class BulletManager;
class Hero :public Entity
{
public:
	Hero();
	~Hero();

	static Hero* create(Sprite* sprite);
	bool init(Sprite* sprite);

	/*给定英雄ID，从配置文件读取英雄的数据*/
	static Hero* createFromCsvFileByID(int iHeroID);
	bool initFromCsvFileByID(int iHeroID);

	CC_SYNTHESIZE(int, m_iBaseAtk, iBaseAtk);
	CC_SYNTHESIZE(int, m_iCurAtk, iCurAtk);
	CC_SYNTHESIZE(int, m_iAtkSpeed, iAtkSpeed);
	CC_SYNTHESIZE(int, m_iAtkRange, iAtkRange);
	CC_SYNTHESIZE(int, m_iUpgradeCostBase, iUpgradeCostBase);
	CC_SYNTHESIZE(int, m_fUpgradeAtkBase, fUpgradeAtkBase);

	/*升级英雄*/
	void upgrade();
	/*一次攻击流程*/
	void checkAtkMonster(float ft, Vector<Monster*> monsterList);
private:
	/* 攻击是否冷却 */
	bool m_isAtkCoolDown;
	/* 当前锁定的怪物 */
	Monster* m_atkMonster;
	/* 检测并选择进入攻击范围的怪物，或者攻击已进入范围的怪物 */
	void checkAtkMonster(float ft);
	/*子弹管理类*/
	BulletManager* m_bulletMgr;

	void chooseAim(Vector<Monster*> monsterList);
	/*锁定要攻击的怪物*/
	void chooseAtkMonster(Monster* monster);
	/*判断坐标是否在攻击范围内*/
	bool isInAtkRange(Point pos);

	void atk();
	void atkCollDownEnd(float dt);

	void checkAimIsOutOfRange(Vector<Monster*> monsterList);
	void missAtkMonster();
};


#endif//_Hero_H_