//  
// #include "CLoadingScene.h"
// #include "Utils/Utils.h"
// #include "Core/AppRes.h"
// 
// using namespace util;
// USING_NS_CC;
// 
// static const char* ACTION_PLIST[] =
// {
//    
// };
// 
// static const char* IMG_LIST[] =
// {
//    
// };
// 
// static const char* LOADING_TEXT_FORMAT = "正在加载中%0.0f%%...";
// 
// LoadingLayer::LoadingLayer()
// {
//     m_nImageNum  = 0;
//     m_nPlistNum  = 0;
//     m_nTotalNum  = 0;
//     m_nLoadedNum = 0;
// }
// 
// LoadingLayer::~LoadingLayer()
// {
//     
// }
// 
// bool LoadingLayer::init()
// {
//     if (!Layer::init())
//     {
//         return false;
//     }
//     initBaseView();
//     return true;
// }
// 
// void LoadingLayer::initBaseView()
// {
// 	m_pGameBgView = CGameBgView::create();
// 	this->addChild(m_pGameBgView);
//     //加载文字
//     m_pLabelProgress = Label::createWithSystemFont(" ", "黑体", 30);
//     m_pLabelProgress->setPosition(Vec2(DEVICE_W / 2 + 350 * SCALE_X,  50 * SCALE_Y));
//     m_pLabelProgress->setColor(Color3B::BLACK);
//     m_pLabelProgress->setScale(SCALE_FIT);
//     this->addChild(m_pLabelProgress);
// }
// 
// void LoadingLayer::onEnter()
// {
//     Layer::onEnter();
//     startLoading();
// }
// 
// void LoadingLayer::onExit()
// {
//     Layer::onExit();
// }
// 
// void LoadingLayer::startLoading()
// {
//     m_nPlistNum = sizeof(ACTION_PLIST) / sizeof(ACTION_PLIST[0]);
//     m_nImageNum = sizeof(IMG_LIST) / sizeof(IMG_LIST[0]);
//     m_nTotalNum = m_nPlistNum + m_nImageNum;
//     onLoadNextRes();
//     showLoadingProgress(0.0f);
// }
// 
// void LoadingLayer::onLoadNextRes()
// {
//     const char* pszName = nullptr;
//     if (m_nLoadedNum < m_nPlistNum)
//     {
//         pszName = str_format("%s.png", ACTION_PLIST[m_nLoadedNum]);
//     } else
//     {
//         pszName = IMG_LIST[m_nLoadedNum - m_nPlistNum];
//     }
//     log("Splash::onLoadNextRes ++++++ %s", pszName);
//     Director::getInstance()->getTextureCache()->addImageAsync(pszName,
//                                                 CC_CALLBACK_1(LoadingLayer::onResLoadedCallBack, this));
// }
// 
// void LoadingLayer::onResLoadedCallBack(cocos2d::Texture2D *pTexture)
// {
//     if (m_nLoadedNum < m_nPlistNum)
//     {
//         const char* pPlistPath = str_format("%s.plist", ACTION_PLIST[m_nLoadedNum]);
//         SpriteFrameCache::getInstance()->addSpriteFramesWithFile(pPlistPath, pTexture);
//     }
//     m_nLoadedNum++;
//     showLoadingProgress(100.0f * m_nLoadedNum / m_nTotalNum);
//     if( m_nLoadedNum == m_nTotalNum)
//     {
//         finishLoading();
//     }else
//     {
//         onLoadNextRes();
//     }
// }
// 
// void LoadingLayer::showLoadingProgress(float fPercent)
// {
//     m_pLabelProgress->setString(str_format(LOADING_TEXT_FORMAT, fPercent));
// }
// 
// void LoadingLayer::finishLoading()
// {
//     m_pLabelProgress->setVisible(false);
//     
// //     auto pStartMenuItem = ButtonUtil::createClickedGrayButton(LS_BTN_START, CC_CALLBACK_1(LoadingLayer::startGameCallBack, this));
// //     pStartMenuItem->setPosition(Vec2(DEVICE_W / 2, DEVICE_H / 2 - 100 * SCALE_Y));
// //     auto pMenu = Menu::create(pStartMenuItem, nullptr);
// //     pMenu->setPosition(Vec2::ZERO);
// //     this->addChild(pMenu);
//  }
// 
// void LoadingLayer::startGameCallBack(cocos2d::Ref *pSender)
// {
//      ;
// }
// 
