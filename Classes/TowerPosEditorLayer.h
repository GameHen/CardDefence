#ifndef _TowerPosEditorLayer_H__
#define _TowerPosEditorLayer_H__
#include "cocos2d.h"
#include "PosBase.h"
#include "TowerPos.h"
#include "MonsterPos.h"
#include "EnumPosType.h"

using namespace cocos2d;
class TowerPosEditorLayer :public Layer
{
public:
	TowerPosEditorLayer();
	~TowerPosEditorLayer();

	CREATE_FUNC(TowerPosEditorLayer);
	virtual bool init();

	/* ����������������ɵ�plist�����ļ� */
	void outputPosToPlistFile();
	
	/* ��ȡplist�����ļ� */
	void loadConfigFile();

	/*ģʽ�任*/
	void changeMode();

	/*�ؿ��任*/
	int nextLevel();
	int preLevel();

	/*���������б�ӿ�*/
	Vector<PosBase*> getMonsterPosList();
private:
	//��ǰ�ؿ�
	int m_iCurLevel;
	//��ǰģʽ
	EnumPosType m_enMode;
	//�������λ���ļ�
	void outputPosToPlistFile(Vector<PosBase*> posList, const char* sFilePath);
	//ɾ�������������
	void deleteAllPos();
private:
	Vector <PosBase*> m_towerPosList;

	void editTowerPos(Point pos);//�༭������
	PosBase* findExistTowerPos(Point pos);//���������ҵ��Ѵ��ڵ����������
	void createTowerPos(Point pos);//������������������
	void deleteTowerPos(PosBase* existPos);//��������ɾ��������
private:
	Vector <PosBase*> m_monsterPosList;

	void editMonsterPos(Point pos);//�༭��������
	PosBase* findExistMonsterPos(Point pos);//���������ҵ��Ѵ��ڵĹ����������
	void createMonsterPos(Point pos);//�����������ɹ������
	void deleteMonsterPos(PosBase* existPos);//��������ɾ���������
};


#endif//_TowerPosEditorLayer_H__