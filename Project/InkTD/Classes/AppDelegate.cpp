#include "AppDelegate.h"
#include "View/Scene/CMainScene.h"
#include "Utils/Utils.h"
#include "Controller/CSoundController.h"

USING_NS_CC;
using namespace util;


AppDelegate *theApp = nullptr;

AppDelegate::AppDelegate() 
{
	theApp = this;
	m_pLocalModel      = nullptr;
	m_pLevelController = nullptr;
	m_pSceneController = nullptr;
}

AppDelegate::~AppDelegate() 
{
	CC_SAFE_DELETE(m_pLocalModel);
	CC_SAFE_DELETE(m_pLevelController);
	CC_SAFE_DELETE(m_pSceneController);
}

bool AppDelegate::applicationDidFinishLaunching()
{
    auto pDirector = Director::getInstance();
	auto pGLView = pDirector->getOpenGLView();
    if(!pGLView) 
	{
		pGLView = GLViewImpl::create("My_Game");
		pGLView->setFrameSize(800, 480);
		//6
		//pGLView->setFrameSize(1334, 750);
		//5
		pGLView->setFrameSize(1136, 640);
        pDirector->setOpenGLView(pGLView);
    }
	//picture-frequency adjustment
	pDirector->setAnimationInterval(1.0 / 60);
	//pDirector->setDisplayStats(true);
	if (this->getTargetPlatform() == Application::Platform::OS_IPAD)
	{
		pGLView->setDesignResolutionSize(960, 640, ResolutionPolicy::SHOW_ALL);
	}
	else
	{
		Size viewSize = pGLView->getFrameSize();
		float fRate = viewSize.width / viewSize.height;
		if (fRate < 1.5)
		{
			pGLView->setDesignResolutionSize(960, 640, ResolutionPolicy::SHOW_ALL);
		}
		else
		{
			pGLView->setDesignResolutionSize(960, 640, ResolutionPolicy::FIXED_HEIGHT);
		}
	}
	this->init();
    auto pScene = CMainView::createScene();
    pDirector->runWithScene(pScene);
    return true;
}

void AppDelegate::init()
{
	WindowUtil::initialize();
	CSoundController::initialize();
	//init data
	m_pLocalModel = new CLocalModel();
	m_pLocalModel->initialize();
	//init Controller
	m_pLevelController = new CLevelController();
	m_pLevelController->initialize();
	m_pSceneController = new CSenceController();
	m_pSceneController->initialize();
	CSoundController::playSndBackground();
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() 
{
    Director::getInstance()->startAnimation();
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
