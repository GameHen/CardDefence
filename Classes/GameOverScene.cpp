#include "GameOverScene.h"
#include "GlobalPath.h"
#include "GlobalParam.h"
#include "SceneManager.h"

Scene* GameOverScene::createScene() {
    auto scene = Scene::create();

    GameOverScene* layer = GameOverScene::create();
    scene->addChild(layer);
    return scene;

    return scene;
}

bool GameOverScene::init() {
    if (!Layer::init()){
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();

    /* ���һ����ǩ */
    Label* winLab = Label::create("GameOver!", PATH_FONT_PUBLIC, GlobalParam::PublicFontSizeLarge);
    winLab->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(winLab);

    /* 3��󷵻عؿ�ѡ�񳡾� */
    this->schedule(schedule_selector(GameOverScene::backToTollgateSelectScene), 3.0f);

    return true;
}

void GameOverScene::backToTollgateSelectScene( float dt ) {
	SceneManager::getInstance()->changeScene(SceneManager::en_TollgateSelectScene);
}
