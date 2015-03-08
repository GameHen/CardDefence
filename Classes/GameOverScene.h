#ifndef _GameOverScene_H_
#define _GameOverScene_H_

#include "cocos2d.h"
USING_NS_CC;

class GameOverScene : public Layer {
public:
    static Scene* createScene();
	CREATE_FUNC(GameOverScene);
	virtual bool init();

private:
	void backToTollgateSelectScene(float dt);
};

#endif