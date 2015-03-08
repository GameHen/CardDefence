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

	/*����Ӣ��ID���������ļ���ȡӢ�۵�����*/
	static Hero* createFromCsvFileByID(int iHeroID);
	bool initFromCsvFileByID(int iHeroID);

	CC_SYNTHESIZE(int, m_iBaseAtk, iBaseAtk);
	CC_SYNTHESIZE(int, m_iCurAtk, iCurAtk);
	CC_SYNTHESIZE(int, m_iAtkSpeed, iAtkSpeed);
	CC_SYNTHESIZE(int, m_iAtkRange, iAtkRange);
	CC_SYNTHESIZE(int, m_iUpgradeCostBase, iUpgradeCostBase);
	CC_SYNTHESIZE(int, m_fUpgradeAtkBase, fUpgradeAtkBase);

	/*����Ӣ��*/
	void upgrade();
	/*һ�ι�������*/
	void checkAtkMonster(float ft, Vector<Monster*> monsterList);
private:
	/* �����Ƿ���ȴ */
	bool m_isAtkCoolDown;
	/* ��ǰ�����Ĺ��� */
	Monster* m_atkMonster;
	/* ��Ⲣѡ����빥����Χ�Ĺ�����߹����ѽ��뷶Χ�Ĺ��� */
	void checkAtkMonster(float ft);
	/*�ӵ�������*/
	BulletManager* m_bulletMgr;

	void chooseAim(Vector<Monster*> monsterList);
	/*����Ҫ�����Ĺ���*/
	void chooseAtkMonster(Monster* monster);
	/*�ж������Ƿ��ڹ�����Χ��*/
	bool isInAtkRange(Point pos);

	void atk();
	void atkCollDownEnd(float dt);

	void checkAimIsOutOfRange(Vector<Monster*> monsterList);
	void missAtkMonster();
};


#endif//_Hero_H_