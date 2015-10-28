#include "EventWrapper.h"

USING_NS_CC;
using namespace std;

EventWrapper::EventWrapper()
:
m_pEventDispatcher(nullptr)
{
	m_pEventDispatcher = Director::getInstance()->getEventDispatcher();
	CC_SAFE_RETAIN(m_pEventDispatcher);
}

EventWrapper::~EventWrapper()
{
	removeAllEventListeners();
	CC_SAFE_RELEASE_NULL(m_pEventDispatcher);
}

void EventWrapper::dispatchEvent(const string &sEventName, void *pUserData)
{
	m_pEventDispatcher->dispatchCustomEvent(sEventName, pUserData);
}

void EventWrapper::addEventListener(const string &sEventName, const function<void (EventCustom *)> &fnEventCallback)
{
	removeEventListener(sEventName);

	auto pListener = m_pEventDispatcher->addCustomEventListener(sEventName, fnEventCallback);
	m_obListenerMap.insert(sEventName, pListener);
}

void EventWrapper::removeEventListener(const string &sEventName)
{
	auto iter = m_obListenerMap.find(sEventName);
	if (iter != m_obListenerMap.end())
	{
		m_pEventDispatcher->removeEventListener(iter->second);
		m_obListenerMap.erase(iter);
	}

}

void EventWrapper::removeAllEventListeners()
{
	auto vKeys = m_obListenerMap.keys();
	for (auto i = 0; i < vKeys.size(); i++)
	{
		removeEventListener(vKeys[i]);
	}
}