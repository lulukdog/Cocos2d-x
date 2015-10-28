#include "CSenceController.h"
#include "AppDelegate.h"
#include "Core/AppEvent.h"
#include "Core/AppDef.h"
#include "View/Scene/CLevelScene.h"
#include "View/Scene/CMainScene.h"
#include "View/Scene/CGameScene.h"
 
using namespace std;
USING_NS_CC;

CSenceController::CSenceController()
{
	 
}

CSenceController::~CSenceController()
{
	removeEvents();
}

void CSenceController::initialize()
{ 
	registerEvents();
}


void CSenceController::registerEvents()
{
	ADD_OBSERVER(CSenceController::onDealwithSenceReplace, EVT_SCENE_REPLACE);
}

void CSenceController::removeEvents()
{
	REMOVE_OBSERVER(EVT_SCENE_REPLACE);
}

void CSenceController::onDealwithSenceReplace(cocos2d::EventCustom* pEvent)
{
	Value* pData = static_cast<Value*>(pEvent->getUserData());
	int nType = pData->asInt();
	switch (nType)
	{
	case TYPE_HOME_TO_LEVEL:
		Director::getInstance()->replaceScene(TransitionSlideInR::create(REPLACE_SCENE_TIME, CLevelSelectView::createScene()));
		break;
	case TYPE_LEVEL_TO_HOME:
		Director::getInstance()->replaceScene(TransitionSlideInL::create(REPLACE_SCENE_TIME, CMainView::createScene()));
		break;
	case TYPE_LEVEL_TO_GAME:
		Director::getInstance()->replaceScene(TransitionSlideInR::create(REPLACE_SCENE_TIME, CMainGameView::createScene()));
		break;
	case TYPE_GAME_TO_LEVEL:
		Director::getInstance()->replaceScene(TransitionSlideInL::create(REPLACE_SCENE_TIME, CLevelSelectView::createScene()));
		break;
	case TYPE_GAME_TO_NEXT_LEVEL:
		Director::getInstance()->replaceScene(TransitionSlideInR::create(REPLACE_SCENE_TIME, CMainGameView::createScene()));
		break;
	case TYPE_GAME_REPLAY:
		Director::getInstance()->replaceScene(TransitionFade::create(REPLACE_SCENE_TIME, CMainGameView::createScene()));
		break;
	default:
		break;
	}
}


