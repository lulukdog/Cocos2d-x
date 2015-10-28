#include "SpriteUtil.h"
#include "MacroUtil.h"

USING_NS_CC;

namespace util
{
    
    Sprite* GetSpriteFromFile(const char* file_name)
    {
        return Sprite::create(file_name);
    }
    
    Sprite* GetSpriteFromPlist(const char* plist_name)
    {
        SpriteFrame *frame = GetFrameFromPlist(plist_name);
        if (!frame)
        {
            return NULL;
        }
        return Sprite::createWithSpriteFrame(frame);
    }
    
    SpriteFrame *GetFrameFromFile(const char* file_name)
    {
        Sprite *sprite = GetSpriteFromFile(file_name);
        if (!sprite)
        {
            return NULL;
        }
        return sprite->displayFrame();
    }
    
    SpriteFrame *GetFrameFromPlist(const char* plist_name)
    {
        return SpriteFrameCache::getInstance()->getSpriteFrameByName(plist_name);
    }
    
    Label* GetLabel(float size, const char* label_str)
    {
        auto label = Label::createWithSystemFont(label_str, "ºÚÌå", size);
        label->setHorizontalAlignment(TextHAlignment::CENTER);
        label->setColor(Color3B::WHITE);
        return label;
    }
    
    Sprite* GetLabelSpriteFromFile(const char* label_str, float size, const char* file_name, float offset)
    {
        Sprite* sprite = GetSpriteFromFile(file_name);
        return GetLabelSpriteFromSprite(label_str, size, sprite, offset);;
    }
    
    Sprite* GetLabelSpriteFromPlist(const char* label_str, float size, const char* plist_name, float offset)
    {
        Sprite* sprite = GetSpriteFromPlist(plist_name);
        return GetLabelSpriteFromSprite(label_str, size, sprite, offset);
    }
    
    Sprite *GetLabelSpriteFromSprite(const char* label_str, float size, Sprite* sprite, float offset)
    {
        Label* label = GetLabel(size, label_str);
        label->setPosition(Vec2(sprite->getContentSize().width / 2,
                               sprite->getContentSize().height / 2 + offset));
        sprite->addChild(label);
        return sprite;
    }
    
    Rect GetNodeWorldRect(Node* pNode, const Size &size)
    {
        Vec2 screenPos = pNode->convertToWorldSpace(Vec2::ZERO);
        
        float scaleX = 1;
        float scaleY = 1;
        
        for (Node *p = pNode; p != NULL; p = p->getParent())
        {
            scaleX *= p->getScaleX();
            scaleY *= p->getScaleY();
        }
        
        // Support negative scaling. Not doing so causes intersectsRect calls
        // (eg: to check if the touch was within the bounds) to return false.
        // Note, CCNode::getScale will assert if X and Y scales are different.
        if (scaleX < 0.f)
        {
            screenPos.x += size.width * scaleX;
            scaleX = -scaleX;
        }
        if (scaleY<0.f)
        {
            screenPos.y += size.height * scaleY;
            scaleY = -scaleY;
        }
        
        return Rect(screenPos.x, screenPos.y, size.width * scaleX, size.height * scaleY);
    }
}
