#include "SceneManager.h"
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
	case en_TollgateScene:
		break;
	case en_TollgateEditorScene:
		break;
	case en_WinScene:
		break;
	case en_GameOverScene:
		break;
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