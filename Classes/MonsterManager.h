#ifndef _MonsterManager_H_
#define _MonsterManager_H_
#include "cocos2d.h"
USING_NS_CC;
class MonsterPos;
class Monster;
class PosBase;
class MonsterManager:public Node
{
public:
	MonsterManager();
	~MonsterManager();
	static MonsterManager* createWithLevel(int iCurLevel);
	bool initWithLevel(int iCurLevel);

	void createMonsters(int iCurLevel);					/*��ȡ�����ļ���������*/
	int getNotShowMonsterCount();						/*��ȡ��û�г����Ĺ�������*/
	MonsterPos* getMonsterStartPos();					/*��ȡ�����������*/
	MonsterPos* getMonsterEndPos();					/*��ȡ�����յ�����*/
	Vector<Monster*> getMonsterList();				/*��ȡ�����б�*/
private:
	Vector<Monster*> m_monsterList;					/*�����б�*/
	Vector<Monster*> m_notShowMonsterList;		/*δ�����Ĺ����б�*/
	Vector<PosBase*> m_monsterPosList;				/*������й�����������*/
	float m_fShowTimeCount;									/*���ڼ���������ʱ��*/
	void showMonster(float dt);								/*����Ƿ����¹������*/
	void logic(float dt);												 /* �������Ƿ���Ҫɾ�� */
};

#endif//_MonsterManager_H_