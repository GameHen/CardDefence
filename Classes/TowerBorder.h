#ifndef _TowerBorder_H_
#define _TowerBorder_H_

#include "Hero.h"
#include "editor-support\cocostudio\CCSGUIReader.h"
#include "cocos-ext.h"
#include "ui\CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;
USING_NS_CC_EXT;

class TowerBorder:public Entity
{
public:
	TowerBorder();
	~TowerBorder();

	CREATE_FUNC(TowerBorder);
	virtual bool init();

	void upgrade();
	/*�ж������Ƿ���뷶Χ*/
	bool isClickMe(Point pos);
	/*��Ӣ�۶���*/
	void bindHero(Hero* hero);
	/*��ȡӢ�۶���*/
	Hero* getHero();
	/*ɾ��Ӣ�۶���*/
	void deleteHero();
	/*��ʾ������ť*/
	void showTowerOprBtns();
	/*ɾ��������ť*/
	void deleteOprBtns();
private:
	/*����*/
	Hero* m_hero;

	bool m_isOprBtnsShow;

	/*������ťUI*/
	Button* m_cancelBtn;
	Button* m_deleteBtn;
	Button* m_upgradeBtn;
	/*�ָ�������ť��Ĭ��λ��*/
	void resetOprBtn();

	void cancelClick(Ref* target, TouchEventType type);
	void deleteClick(Ref* target, TouchEventType type);
	void upgradeClick(Ref* target, TouchEventType type);
};
#endif//_TowerBorder_H_