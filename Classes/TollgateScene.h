#ifndef _TollgateScene_H__
#define _TollgateScene_H__
#include "cocos2d.h"
USING_NS_CC;
#define TAG_MAP_LAYER 1		//关卡地图图层TAG
#define TAG_DATA_LAYER 2		//关卡数据图层TAG
class TollgateScene:public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TollgateScene);
};
#endif//_TollgateScene_H__