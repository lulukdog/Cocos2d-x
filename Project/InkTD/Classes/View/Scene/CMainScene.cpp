#include "CMainScene.h"
#include "Utils/Utils.h" 
#include "Core/AppRes.h"
#include "Core/AppEvent.h"
#include "Core/AppDef.h"

USING_NS_CC;
using namespace util;

enum 
{
	KTag_Menu_Play = 1,
	kTag_Menu_Edit,
	kTag_Menu_Help,
	kTag_Menu_HighScore
};

CMainView::CMainView()
{

	m_pMenuPlay      = nullptr;
	m_pMenuEdit      = nullptr;
	m_pMenuHighScore = nullptr;
	m_pMenuHelp      = nullptr;
}

CMainView::~CMainView()
{
	m_pMenuPlay      = nullptr;
	m_pMenuEdit      = nullptr;
	m_pMenuHighScore = nullptr;
	m_pMenuHelp      = nullptr;
}

Scene* CMainView::createScene()
{
	auto pScene = Scene::create();
	auto pLayer = CMainView::create();
	pScene->addChild(pLayer);
	return pScene;
}

bool CMainView::init()
{
	if (!Layer::init())
	{
		return false;
	}
	initMediator();
	return true;
}

void CMainView::initMediator()
{
// 	m_pMenuPlay = ButtonUtil::createScaleBtn(MAINSCENE_BTN_PLAY_UP, CC_CALLBACK_1(CMainView::onMenuCallBack, this));
// 	m_pMenuEdit = ButtonUtil::createScaleBtn(MENU_EDITOR, CC_CALLBACK_1(CMainView::onMenuCallBack, this));
// 	m_pMenuPlay->setPosition(Vec2(DESIGN_W / 2, DESIGN_H / 2 - 80));
// 	m_pMenuPlay->setScale(1.5);
// 	m_pMenuPlay->setTag(KTag_Menu_Play);
// 
// 	m_pMenuEdit->setPosition(Vec2(DESIGN_W / 2, DESIGN_H / 2 - 150));
// 	m_pMenuEdit->setScale(1.3);
// 	m_pMenuEdit->setTag(kTag_Menu_Edit);
// 	auto pMenu = Menu::create(m_pMenuPlay, m_pMenuEdit, nullptr);
// 	pMenu->setPosition(Vec2::ZERO);
// 	this->addChild(pMenu);

}

void CMainView::onMenuCallBack(cocos2d::Ref *pSender)
{
	MenuItem *pItem = static_cast<MenuItem*>(pSender);
	auto nTag = pItem->getTag();
	switch (nTag)
	{
		case KTag_Menu_Play:
			playGame();
			break;
		case kTag_Menu_Edit:
			break;
		case kTag_Menu_Help:
			toHelp();
			break;
		case kTag_Menu_HighScore:
			break;
		default:
			log("CMainView::onMenuCallBack +++++ the menu tag is error!");
			break;
	}
}

void CMainView::playGame()
{
	Value oData(TYPE_HOME_TO_LEVEL);
	dispatchEvent(EVT_SCENE_REPLACE, &oData);
}

void CMainView::toHelp()
{
}

void CMainView::toHighScore()
{
}


