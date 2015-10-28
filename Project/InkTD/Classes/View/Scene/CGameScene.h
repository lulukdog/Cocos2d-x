#pragma  once
#include "cocos2d.h"
#include "Event/EventWrapper.h"
class CMainGameView : public cocos2d::Layer, public EventWrapper
{
public:
	CMainGameView();
	~CMainGameView();
	static cocos2d::Scene* createScene();
	virtual bool init();  
	virtual void onEnter();
	virtual void onExit();
	CREATE_FUNC(CMainGameView);

private:
	void onGameOver(cocos2d::EventCustom* pEvent);

public:
	void initMediator();
 
private:
	int           m_nCurLevel;
};

 
