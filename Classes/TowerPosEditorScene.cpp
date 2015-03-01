#include "TowerPosEditorScene.h"
#include "TowerPosEditorLayer.h"
#include "TowerPosEditorOperatorLayer.h"
#include "TowerPos.h"
#include "I18N.h"
TowerPosEditorScene::TowerPosEditorScene()
{
}

TowerPosEditorScene::~TowerPosEditorScene()
{
}

Scene * TowerPosEditorScene::createScene()
{
	auto scene = Scene::create();
	//auto layer = TowerPosEditorScene::create();
	//scene->addChild(layer, 1);

	auto editorLayer = TowerPosEditorLayer::create();
	scene->addChild(editorLayer, 1);
	auto oprLayer = TowerPosEditorOperatorLayer::create(editorLayer);
	scene->addChild(oprLayer, 2);

	log("I18N Test:%s", I18N::getInstance()->getcString(en_StrKey_Public_Confirm));
	return scene;
}

bool TowerPosEditorScene::init()
{
	if (!Layer::init())
		return false;
	return true;
}