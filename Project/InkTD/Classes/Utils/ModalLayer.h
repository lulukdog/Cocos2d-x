#ifndef UTIL_MODALLAYER_H_
#define UTIL_MODALLAYER_H_

#include "cocos2d.h"

/*
 *用来屏蔽下层按钮
 */
namespace util
{
    class ModalLayer : public cocos2d::LayerColor
    {
    public:
        virtual bool init();
        
        virtual bool initWithColor(const cocos2d::Color4B& color);
        
        virtual bool initWithColor(const cocos2d::Color4B& color, GLfloat width, GLfloat height);
        
        virtual void onEnter();
        
        virtual void onExit();
        
        virtual bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
        
        virtual void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
    };
}

#endif