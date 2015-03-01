#ifndef _TowerPosEditorOperatorLayer_H__
#define _TowerPosEditorOperatorLayer_H__
#include "cocos2d.h"
#include "TowerPosEditorLayer.h"
#include "cocos-ext.h"
#include "editor-support\cocostudio\CCSGUIReader.h"
#include "ui\CocosGUI.h"
USING_NS_CC_EXT;
using namespace cocos2d;
using namespace cocos2d::ui;
using namespace cocostudio;

class TowerPosEditorOperatorLayer :public Layer
{
public:
	TowerPosEditorOperatorLayer();
	~TowerPosEditorOperatorLayer();

	static TowerPosEditorOperatorLayer* create(TowerPosEditorLayer* layer);
	virtual bool init(TowerPosEditorLayer* layer);

	void draw(Renderer* renderer, const kmMat4 &transform, bool transformUpdated);
private:
	TowerPosEditorLayer* m_editorLayer;//±à¼­²ã
	void outputBtnOnClick(Ref *, ui::TouchEventType  type);
	void changeModeOnClick(Ref *, ui::TouchEventType  type);
	void preLevelOnClick(Ref *, ui::TouchEventType  type);
	void nextLevelOnClick(Ref *, ui::TouchEventType  type);

private:
	void onDraw(const kmMat4 &transform, bool transformUpdated);
	CustomCommand _customCommand;
};

#endif//