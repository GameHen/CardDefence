#include "SceneManager.h"
#include "TowerPosEditorScene.h"
#include "TollgateScene.h"
#include "TollgateSelectScene.h"
#include "WinScene.h"
#include "GameOverScene.h"
SceneManager* SceneManager::mSceneManager = NULL;

SceneManager::SceneManager()
{
}
SceneManager::~SceneManager()
{
}

SceneManager * SceneManager::getInstance()
{
	if (mSceneManager == NULL)
	{
		mSceneManager = new SceneManager();
		if (mSceneManager&&mSceneManager->init())
		{
			mSceneManager->autorelease();
			mSceneManager->retain();
		}
		else
		{
			CC_SAFE_DELETE(mSceneManager);
			mSceneManager = NULL;
		}
	}
	return mSceneManager;
}

bool SceneManager::init()
{
	return true;
}

void SceneManager::changeScene(EnumSceneType enSceneType)
{
	Scene* pScene = NULL;
	switch (enSceneType)
	{
	case en_TollgateScene:				/*�ؿ�����*/
		pScene = TollgateScene::createScene();
		break;
	case en_TollgateEditorScene:		/*�༭����*/
		pScene = TowerPosEditorScene::createScene();
		break;
	case en_WinScene:						/*ʤ������*/
		pScene = WinScene::createScene();
		break;
	case en_GameOverScene:			/*��������*/
		pScene = GameOverScene::createScene();
		break;
	case en_TollgateSelectScene:
		pScene = TollgateSelectScene::createScene();
	}
	if (pScene == NULL)
		return;

	Director *pDirector = Director::getInstance();
	Scene* curScene = pDirector->getRunningScene();
	if (curScene == NULL)
		pDirector->runWithScene(pScene);
	else
		pDirector->replaceScene(pScene);
}