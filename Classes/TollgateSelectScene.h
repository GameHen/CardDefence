#ifndef _TollgateSelectScene_H_
#define _TollgateSelectScene_H_
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC_EXT;
USING_NS_CC;

#include "editor-support/cocostudio/CCSGUIReader.h"
#include "cocos-ext.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;
USING_NS_CC_EXT;
class TollgateSelectScene :public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TollgateSelectScene);
private:
	void level_1(Ref* target, TouchEventType type);
	void level_2(Ref* target, TouchEventType type);
	void level_3(Ref* target, TouchEventType type);
};
#endif