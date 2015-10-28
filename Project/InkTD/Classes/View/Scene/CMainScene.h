#pragma  once
#include "cocos2d.h"
#include "Event/EventWrapper.h"

class CMainView : public cocos2d::Layer, public EventWrapper
{
public:
	CMainView();
	~CMainView();
	virtual bool init();
	CREATE_FUNC(CMainView);

	static cocos2d::Scene* createScene();

public:
	void initMediator();
	void playGame();
	void toHelp();
	void toHighScore();

private:
	void onMenuCallBack(cocos2d::Ref *pSender);

private:
	cocos2d::MenuItem	   *m_pMenuPlay;
	cocos2d::MenuItem	   *m_pMenuEdit;
	cocos2d::MenuItem	   *m_pMenuHighScore;
	cocos2d::MenuItem      *m_pMenuHelp;
};


