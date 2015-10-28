// #pragma once
// 
// #include "cocos2d.h"
// #include "View/Layer/CGameBgView.h"
// 
// class LoadingLayer : public cocos2d::Layer 
// {
// public:
//     LoadingLayer();
//     virtual ~LoadingLayer();
//     CREATE_FUNC(LoadingLayer);
//     virtual bool init();
//     void onEnter();
//     void onExit();
//     void initBaseView();
//     void startLoading();
//     void showLoadingProgress(float fPercent);
//     void onLoadNextRes();
//     void onResLoadedCallBack(cocos2d::Texture2D* pTexture);
//     void finishLoading();
//     void startGameCallBack(cocos2d::Ref* pSender);
// private:
//     
//     int                 m_nPlistNum;            
//     int                 m_nImageNum;            
//     int                 m_nTotalNum;            
//     int                 m_nLoadedNum;    
// 
// 
// 	CGameBgView*        m_pGameBgView;
//     cocos2d::Label*     m_pLabelProgress;                     
// };
// 
