#include "TollgateSelectScene.h"
#include "SceneManager.h"
#include "GlobalClient.h"

Scene* TollgateSelectScene::createScene()
{
	auto scene = Scene::create();

	TollgateSelectScene* layer = TollgateSelectScene::create();
	scene->addChild(layer);
	return scene;
}
bool  TollgateSelectScene::init()
{
	bool bRet = false;
	do{
		CC_BREAK_IF(!Layer::init());
		/*¼ÓÔØUI*/
		auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("TgSelectUI/TgSelectUI_1.ExportJson");
		this->addChild(UI);

		Button* tgSelect1Btn = (Button*)Helper::seekWidgetByName(UI, "tgSelect1Btn");
		Button* tgSelect2Btn = (Button*)Helper::seekWidgetByName(UI, "tgSelect2Btn");
		Button* tgSelect3Btn = (Button*)Helper::seekWidgetByName(UI, "tgSelect3Btn");

		tgSelect1Btn->addTouchEventListener(this, toucheventselector(TollgateSelectScene::level_1));
		tgSelect2Btn->addTouchEventListener(this, toucheventselector(TollgateSelectScene::level_2));
		tgSelect3Btn->addTouchEventListener(this, toucheventselector(TollgateSelectScene::level_3));

		bRet = true;
	} while (0);
	return bRet;
}


void TollgateSelectScene::level_1(Ref* target, TouchEventType type)
{
	if (type != TouchEventType::TOUCH_EVENT_ENDED){
		return;
	}
	GlobalClient::getInstance()->setiCurTollgateLevel(1);
	SceneManager::getInstance()->changeScene(SceneManager::en_TollgateScene);
}

void TollgateSelectScene::level_2(Ref* target, TouchEventType type)
{
	if (type != TouchEventType::TOUCH_EVENT_ENDED){
		return;
	}
	GlobalClient::getInstance()->setiCurTollgateLevel(2);
	SceneManager::getInstance()->changeScene(SceneManager::en_TollgateScene);
}

void TollgateSelectScene::level_3(Ref* target, TouchEventType type)
{
	if (type != TouchEventType::TOUCH_EVENT_ENDED){
		return;
	}
	GlobalClient::getInstance()->setiCurTollgateLevel(3);
	SceneManager::getInstance()->changeScene(SceneManager::en_TollgateScene);
}