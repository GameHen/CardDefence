#include "TowerPosEditorOperatorLayer.h"

TowerPosEditorOperatorLayer::TowerPosEditorOperatorLayer()
{
}

TowerPosEditorOperatorLayer::~TowerPosEditorOperatorLayer()
{
}

TowerPosEditorOperatorLayer* TowerPosEditorOperatorLayer::create(TowerPosEditorLayer* layer)
{
	auto oprLayer = new TowerPosEditorOperatorLayer();
	if (oprLayer&&oprLayer->init(layer))
		oprLayer->autorelease();
	else
		CC_SAFE_DELETE(oprLayer);
	return oprLayer;
}

bool TowerPosEditorOperatorLayer::init(TowerPosEditorLayer *layer)
{
	if (!Layer::init()) return false;

	this->m_editorLayer = layer;
	/************加载UI*************/
	auto UI = cocostudio::GUIReader::getInstance()->
		widgetFromJsonFile("EditorOperate/EditorOperate_1.ExportJson");
	this->addChild(UI);

	UI->setTouchEnabled(false);
	//获取控件对象
	auto outputBtn = (ui::Button *)ui::Helper::seekWidgetByName(UI, "outputBtn");
	auto changeModeBtn = (Button *)Helper::seekWidgetByName(UI, "changeModeBtn");
	auto nexLvBtn = (Button *)Helper::seekWidgetByName(UI, "nexLvBtn");
	auto preLvBtn = (Button *)Helper::seekWidgetByName(UI, "preLvBtn");
	/*****************************添加单击监听***************************/
	/*监听输出文件按钮*/
	outputBtn->addTouchEventListener(this,
		toucheventselector(TowerPosEditorOperatorLayer::outputBtnOnClick));
	/*监听切换模式按钮*/
	changeModeBtn->addTouchEventListener(this,
		toucheventselector(TowerPosEditorOperatorLayer::changeModeOnClick));
	/*监听下一关卡按钮*/
	nexLvBtn->addTouchEventListener(this,
		toucheventselector(TowerPosEditorOperatorLayer::nextLevelOnClick));
	/*监听上一关卡按钮*/
	preLvBtn->addTouchEventListener(this,
		toucheventselector(TowerPosEditorOperatorLayer::preLevelOnClick));
	return true;
}

void TowerPosEditorOperatorLayer::outputBtnOnClick(Ref *, ui::TouchEventType type)
{
	if (type == TouchEventType::TOUCH_EVENT_ENDED)
		m_editorLayer->outputPosToPlistFile();
}

void TowerPosEditorOperatorLayer::changeModeOnClick(Ref *, ui::TouchEventType  type)
{
	if (type == TouchEventType::TOUCH_EVENT_ENDED)
		m_editorLayer->changeMode();
}

void TowerPosEditorOperatorLayer::preLevelOnClick(Ref *, ui::TouchEventType  type)
{
	if (type == TouchEventType::TOUCH_EVENT_ENDED)
		m_editorLayer->preLevel();
}
void TowerPosEditorOperatorLayer::nextLevelOnClick(Ref *, ui::TouchEventType  type)
{
	if (type == TouchEventType::TOUCH_EVENT_ENDED)
		m_editorLayer->nextLevel();
}

void TowerPosEditorOperatorLayer::draw(Renderer* renderer, const kmMat4 &transform, bool transformUpdated)
{
	_customCommand.init(_globalZOrder);
	_customCommand.func = CC_CALLBACK_0(
		TowerPosEditorOperatorLayer::onDraw, this, transform, transformUpdated);

	renderer->addCommand(&_customCommand);
}
void TowerPosEditorOperatorLayer::onDraw(const kmMat4 &transform, bool transformUpdated)
{
	kmGLPushMatrix();
	kmGLLoadMatrix(&transform);

	Vector<PosBase*> m_monsterPosList = m_editorLayer->getMonsterPosList();
	PosBase *prePos = NULL;
	for (auto posBase : m_monsterPosList)
	{
		if (prePos != NULL)
			DrawPrimitives::drawLine(prePos->getPos(), posBase->getPos());
		prePos = posBase;
	}

	kmGLPopMatrix();//结束绘制
}