/*******************************************************************************
 ���ļ��еķ�������ȡ����׼������CCSprite��CCSpriteFrame�ķ�����
 1. is_use_plist����Ĭ������£���get_sprite��GetFrameFromFile������boool�������Ǹ��������Ƿ�
 ʹ��plist������CCCSprite��CCCSpriteFrame
 2. get_sprite��������CCSprite
 3. GetFrameFromFile��������CCCSpriteFrame
 *******************************************************************************/

#pragma once

#include "cocos2d.h"

namespace util
{
    
    // ��ȡSprite������ȫ�ֱ���is_use_plist()�����Ƿ��plist�л�ȡ
    cocos2d::Sprite* GetSpriteFromFile(const char* file_name);
    
    // ��ȡSprite�����ݲ���use_plist�����Ƿ��plist�л�ȡ
    cocos2d::Sprite* GetSpriteFromPlist(const char* plist_name);
    
    // ��ȡSpriteFrame������ȫ�ֱ���is_use_plist()�����Ƿ��plist�л�ȡ
    cocos2d::SpriteFrame* GetFrameFromFile(const char* file_name);
    
    // ��ȡSpriteFrame�����ݲ���use_plist�����Ƿ��plist�л�ȡ
    cocos2d::SpriteFrame* GetFrameFromPlist(const char* plist_name);
    
    // ��ȡLabel
    cocos2d::Label* GetLabel(float size, const char* label_str);
    
    // �������󣬻�ȡ����Label��Sprite�����ļ��л�ȡ
    cocos2d::Sprite* GetLabelSpriteFromFile(const char* label_str,
                                              float size,
                                              const char* file_name,
                                              float offset = 0);
    // �������󣬻�ȡ����Label��sprite����plist�л�ȡ
    cocos2d::Sprite* GetLabelSpriteFromPlist(const char* label_str,
                                               float size,
                                               const char* plist_name,
                                               float offset = 0);
    // ��������
    cocos2d::Sprite* GetLabelSpriteFromSprite(const char* label_str,
                                                float size,
                                                cocos2d::Sprite* sprite,
                                                float offset = 0);
    
    // ��ȡnode���������
    // �˷�����scrollview��getViewRect copy
    cocos2d::Rect GetNodeWorldRect(cocos2d::Node* pNode, const cocos2d::Size &size);
}
