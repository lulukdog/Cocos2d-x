#include "ModalLayer.h"

USING_NS_CC;

namespace util
{
	 
    bool ModalLayer::init()
    {
        return initWithColor(Color4B(0x00, 0x00, 0x00, 0xFF * 0.58f));
    }
    
    bool ModalLayer::initWithColor(const Color4B &color)
    {
        Size oSize = Director::getInstance()->getWinSize();
        return initWithColor(color, oSize.width, oSize.height);
    }
    
    bool ModalLayer::initWithColor(const Color4B &color, GLfloat width, GLfloat height)
    {
        LayerColor::initWithColor(color, width, height);
        auto pEventToucher = EventListenerTouchOneByOne::create();
        pEventToucher->setSwallowTouches(true);
        pEventToucher->onTouchBegan = CC_CALLBACK_2(ModalLayer::onTouchBegan, this);
        pEventToucher->onTouchEnded = CC_CALLBACK_2(ModalLayer::onTouchEnded, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(pEventToucher, this);
        return true;
    }
    
    void ModalLayer::onEnter()
    {
        LayerColor::onEnter();
    }
    
    bool ModalLayer::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
    {
        return true;
    }
    
    void ModalLayer::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
    {
    }
    
    void ModalLayer::onExit()
    {
        LayerColor::onExit();
    }
    
}
