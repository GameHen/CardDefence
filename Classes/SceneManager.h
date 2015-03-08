#ifndef _SceneManager_H__
#define _SceneManager_H__
#include "cocos2d.h"
USING_NS_CC;

class SceneManager:public Ref
{
public:
	SceneManager();
	~SceneManager();

	enum EnumSceneType{
		en_TollgateScene,					/*关卡场景*/
		en_TollgateEditorScene,			/*关卡编辑器场景*/
		en_WinScene,							/*胜利场景*/
		en_GameOverScene,				/*游戏结束场景*/
		en_TollgateSelectScene,			/*选择关卡场景*/
	};

	static SceneManager* getInstance();
	virtual bool init();
	/*切换场景*/
	void changeScene(EnumSceneType enScenType);
private:
	/*场景管理对象*/
	static SceneManager* mSceneManager;
};
#endif//_SceneManager_H__
