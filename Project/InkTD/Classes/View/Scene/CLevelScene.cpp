#include "CLevelScene.h"
#include "Utils/Utils.h"
#include "Core/AppEvent.h"
#include "Core/AppDef.h"
#include "AppDelegate.h"
#include "Core/AppRes.h"

USING_NS_CC;
using namespace util;

enum 
{
	TYPE_EXIT = 0
};

CLevelSelectView::CLevelSelectView()
{

}

CLevelSelectView::~CLevelSelectView()
{
}

Scene* CLevelSelectView::createScene()
{
	auto pScene = Scene::create();
	auto pLayer = CLevelSelectView::create();
	pScene->addChild(pLayer);
	return pScene;
}

bool CLevelSelectView::init()
{
	if (!Layer::init())
	{
		return false;
	}
	initMediator();
	return true;
}

void CLevelSelectView::initMediator()
{
// 	auto pLevelSelect = Label::createWithTTF("SELECT LEVEL", ARIAL_BLACK, 45);
// 	pLevelSelect->setPosition(DEVICE_W / 2, DEVICE_H - 70);
// 	pLevelSelect->setColor(Color3B::BLACK);
// 	this->addChild(pLevelSelect);
// 
// 	auto pBtnExit = ButtonUtil::createScaleBtn(MAINSCENE_BTN_BACK,CC_CALLBACK_1(CLevelSelectView::onMenuCallBack, this, TYPE_EXIT));
// 	pBtnExit->setPosition(Vec2(30, DEVICE_H - 30));
// 	pBtnExit->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
// 	pBtnExit->setScale(0.4f);
// 	auto pMenu = Menu::create(pBtnExit, nullptr);
// 	pMenu->setPosition(Vec2::ZERO);
// 	this->addChild(pMenu);

}

void CLevelSelectView::onEnter()
{
	Layer::onEnter();
}

void CLevelSelectView::onExit()
{
	Layer::onExit();
}

void CLevelSelectView::onMenuCallBack(cocos2d::Ref* pSender, int nType)
{
	Value oData;
	switch (nType)
	{
		case TYPE_EXIT:
			oData = TYPE_LEVEL_TO_HOME;
			dispatchEvent(EVT_SCENE_REPLACE, &oData);
			break;
		default:
			break;
	}
}
