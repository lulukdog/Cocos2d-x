/*******************************************************************************
 此文件中的方法用于取代标准的生成CCSprite和CCSpriteFrame的方法。
 1. is_use_plist返回默认情况下（即get_sprite和GetFrameFromFile不带有boool参数的那个函数）是否
 使用plist来生成CCCSprite和CCCSpriteFrame
 2. get_sprite用于生成CCSprite
 3. GetFrameFromFile用于生成CCCSpriteFrame
 *******************************************************************************/

#pragma once

#include "cocos2d.h"

namespace util
{
    
    // 获取Sprite，根据全局变量is_use_plist()决定是否从plist中获取
    cocos2d::Sprite* GetSpriteFromFile(const char* file_name);
    
    // 获取Sprite，根据参数use_plist决定是否从plist中获取
    cocos2d::Sprite* GetSpriteFromPlist(const char* plist_name);
    
    // 获取SpriteFrame，根据全局变量is_use_plist()决定是否从plist中获取
    cocos2d::SpriteFrame* GetFrameFromFile(const char* file_name);
    
    // 获取SpriteFrame，根据参数use_plist决定是否从plist中获取
    cocos2d::SpriteFrame* GetFrameFromPlist(const char* plist_name);
    
    // 获取Label
    cocos2d::Label* GetLabel(float size, const char* label_str);
    
    // 个人需求，获取带有Label是Sprite，从文件中获取
    cocos2d::Sprite* GetLabelSpriteFromFile(const char* label_str,
                                              float size,
                                              const char* file_name,
                                              float offset = 0);
    // 个人需求，获取带有Label是sprite，从plist中获取
    cocos2d::Sprite* GetLabelSpriteFromPlist(const char* label_str,
                                               float size,
                                               const char* plist_name,
                                               float offset = 0);
    // 用于重载
    cocos2d::Sprite* GetLabelSpriteFromSprite(const char* label_str,
                                                float size,
                                                cocos2d::Sprite* sprite,
                                                float offset = 0);
    
    // 获取node的世界矩形
    // 此方法从scrollview的getViewRect copy
    cocos2d::Rect GetNodeWorldRect(cocos2d::Node* pNode, const cocos2d::Size &size);
}
