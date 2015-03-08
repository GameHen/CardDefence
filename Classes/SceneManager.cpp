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
	case en_TollgateScene:				/*关卡场景*/
		pScene = TollgateScene::createScene();
		break;
	case en_TollgateEditorScene:		/*编辑场景*/
		pScene = TowerPosEditorScene::createScene();
		break;
	case en_WinScene:						/*胜利场景*/
		pScene = WinScene::createScene();
		break;
	case en_GameOverScene:			/*结束场景*/
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