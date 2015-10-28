#include "CGameScene.h"
#include "Utils/WindowUtil.h"
#include "Core/AppEvent.h"
#include "AppDelegate.h"

USING_NS_CC;
using namespace util;
CMainGameView::CMainGameView()
{
	m_nCurLevel = 0;
}

CMainGameView::~CMainGameView()
{
	m_nCurLevel   = 0;
}

Scene* CMainGameView::createScene()
{
	auto pScene = Scene::create();
	auto pLayer = CMainGameView::create();
	pScene->addChild(pLayer);
	return pScene;
}

bool CMainGameView::init()
{
	if (!Layer::init())
	{
		return false;
	}
	m_nCurLevel = theApp->m_pLevelController->getCurLevel();
	initMediator(); 
	return true;
}

void CMainGameView::initMediator()
{

}

void CMainGameView::onEnter()
{
	Layer::onEnter();
	ADD_OBSERVER(CMainGameView::onGameOver, EVT_GAME_OVER);
}

void CMainGameView::onExit()
{
	REMOVE_OBSERVER(EVT_GAME_OVER);
	Layer::onExit();
}

void CMainGameView::onGameOver(EventCustom* pEvent)
{
	Value *pData = static_cast<Value*>(pEvent->getUserData());
	int nType = pData->asInt();
	switch (nType)
	{
		case GAMEOVER::NOBULLET:
			break;
		case GAMEOVER::MAINCHARDIED:
			break;
		case GAMEOVER::SUCCESS:
			break;
		default:
			break;
	}
}
