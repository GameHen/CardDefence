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
		en_TollgateScene,					/*�ؿ�����*/
		en_TollgateEditorScene,			/*�ؿ��༭������*/
		en_WinScene,							/*ʤ������*/
		en_GameOverScene,				/*��Ϸ��������*/
		en_TollgateSelectScene,			/*ѡ��ؿ�����*/
	};

	static SceneManager* getInstance();
	virtual bool init();
	/*�л�����*/
	void changeScene(EnumSceneType enScenType);
private:
	/*�����������*/
	static SceneManager* mSceneManager;
};
#endif//_SceneManager_H__
