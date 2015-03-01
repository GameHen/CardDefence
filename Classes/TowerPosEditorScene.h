#ifndef _TowerPosEditorScene_H__
#define _TowerPosEditorScene_H__
#include "cocos2d.h"
using namespace cocos2d;

class TowerPosEditorScene:public Layer
{
public:
	TowerPosEditorScene();
	~TowerPosEditorScene();

	static Scene * createScene();
	virtual bool init();
	CREATE_FUNC(TowerPosEditorScene);
private:

};


#endif//_TowerPosEditorScene_H__