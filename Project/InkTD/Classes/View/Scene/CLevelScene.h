#pragma  once
#include "cocos2d.h"
#include "Event/EventWrapper.h"


class CLevelSelectView : public cocos2d::Layer, public EventWrapper
{
public:
	CLevelSelectView();
	~CLevelSelectView();
	static cocos2d::Scene* createScene();
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	CREATE_FUNC(CLevelSelectView);

private:
	void onMenuCallBack(cocos2d::Ref* pSender, int nType);

public:
	void initMediator();

};


