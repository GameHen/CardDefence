#ifndef _Monster_H_
#define _Monster_H_
#include "Entity.h"
#include "GlobalDefine.h"
#define MONSTER_SPEED_INIT 1
#include "editor-support\cocostudio\CCSGUIReader.h"
#include "cocos-ext.h"
#include "ui\CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;
USING_NS_CC;

class ControllerSimpleMove;
class PosBase;
class Monster:public Entity
{
public:
	Monster();
	~Monster();
	CREATE_FUNC(Monster);
	virtual bool init();

	/*��������ID���������ļ��ж�ȡ��������*/
	static Monster* createFromCsvFileByID(int iMonsterID);
	bool initFromCsvFileByID(int iMonsterID);
public:
	/*���ո����������ƶ�*/
	void moveByPosList(Vector<PosBase*>posList);
protected:
	virtual void onDead() override;
	virtual void onBindSprite() override;
	virtual void onHurt(int iHurtValue) override;
private:
	LoadingBar* m_hpBar;
	int m_iMaxHp;
	ControllerSimpleMove* m_moveController;					//�ƶ�������
	CC_SYNTHESIZE(int, m_iLevel, iLevel);							//�ȼ�
	CC_SYNTHESIZE(float, m_fShowTime, fShowTime);		//�����������
	CC_CC_SYNTHESIZE_BOOL(m_isMoveEnd, MoveEnd);
};

#endif//_Monster_H_