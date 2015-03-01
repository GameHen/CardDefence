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

	/* 把所有坐标对象生成到plist配置文件 */
	void outputPosToPlistFile();
	
	/* 读取plist配置文件 */
	void loadConfigFile();

	/*模式变换*/
	void changeMode();

	/*关卡变换*/
	int nextLevel();
	int preLevel();

	/*怪物坐标列表接口*/
	Vector<PosBase*> getMonsterPosList();
private:
	//当前关卡
	int m_iCurLevel;
	//当前模式
	EnumPosType m_enMode;
	//输出坐标位置文件
	void outputPosToPlistFile(Vector<PosBase*> posList, const char* sFilePath);
	//删除所有坐标对象
	void deleteAllPos();
private:
	Vector <PosBase*> m_towerPosList;

	void editTowerPos(Point pos);//编辑塔坐标
	PosBase* findExistTowerPos(Point pos);//根据坐标找到已存在的塔坐标对象
	void createTowerPos(Point pos);//根据坐标生成塔对象
	void deleteTowerPos(PosBase* existPos);//根据坐标删除塔对象
private:
	Vector <PosBase*> m_monsterPosList;

	void editMonsterPos(Point pos);//编辑怪物坐标
	PosBase* findExistMonsterPos(Point pos);//根据坐标找到已存在的怪物坐标对象
	void createMonsterPos(Point pos);//根据坐标生成怪物对象
	void deleteMonsterPos(PosBase* existPos);//根据坐标删除怪物对象
};


#endif//_TowerPosEditorLayer_H__