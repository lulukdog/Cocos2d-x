/*
 *author by mtt
 */
#ifndef Event_EventWrapper_h
#define Event_EventWrapper_h

#include "cocos2d.h"

#define ADD_OBSERVER(_FUNC_, _NAME_, ...)\
	addEventListener(_NAME_, CC_CALLBACK_1(_FUNC_, this, ##__VA_ARGS__))

#define REMOVE_OBSERVER(_NAME_)\
	removeEventListener(_NAME_)

class EventWrapper
{
public:
	EventWrapper();
	virtual ~EventWrapper();

protected:
	void dispatchEvent(const std::string &sEventName, void *pUserData = nullptr);
	void addEventListener(const std::string &sEventName, const std::function<void(cocos2d::EventCustom*)> &fnEventCallback);
	void removeEventListener(const std::string &sEventName);
	void removeAllEventListeners();

protected:
	cocos2d::EventDispatcher                            *m_pEventDispatcher;
	cocos2d::Map<std::string, cocos2d::EventListener*>   m_obListenerMap;
};
#endif