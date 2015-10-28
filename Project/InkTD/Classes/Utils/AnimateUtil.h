/*******************************************************************************
���ļ��еķ����������ɶ����������������ַ�ʽ�Ķ�����
1. ����ͼƬ���й���ǰ׺��ͼƬ������ÿ֡����ʱ������һ������������
   ����fire0.png, fire1.png, fire2.png, fire3.png��ÿ��ͼƬ����0.05�룬�������µ��ã�
   GetAnimationFromFile("fire", 4, 0.05f);
2. ����ͼƬ���й���ǰ׺��ͼƬ������ÿ֡����ʱ�䣬�Լ��ӵڼ�֡��ʼ��������һ������������
   ���簴��fire2.png, fire3.png, fire0.png, fire1.png˳�򲥷ţ��������µ��ã�
   GetAnimationFromFile("fire", 4, 0.05f, 2);
����������������������һ�����ذ汾�����һ������Ϊboool���ͣ���ʾ�Ƿ��plist�л�ȡCCSpriteFrame
*******************************************************************************/

#pragma once

#include "cocos2d.h"

namespace util
{

// �ӵ����ļ������ɶ���
// prefix_name: ����ͼƬ�Ĺ���ǰ׺
// frame_count: �ܹ�����ͼƬ
// delay: ÿ��������ͼƬ֮���ʱ����
cocos2d::Animation* GetAnimationFromFile(const char *pPrefixName,
                                           int nFrameCount,
                                           float fDelay);

// �ӵ����ļ������ɶ���
// prefix_name: ����ͼƬ�Ĺ���ǰ׺
// frame_count: �ܹ�����ͼƬ
// delay: ÿ��������ͼƬ֮���ʱ����
// start_index: �ӵڼ��ſ�ʼѭ�����䷶Χ��[0, frame_count-1]
cocos2d::Animation* GetAnimationFromFile(const char *pPrefixName,
                                           int nFrameCount,
                                           float fDelay,
                                           int nStartIndex);

// ��plist�����ɶ���
// prefix_name: ����ͼƬ�Ĺ���ǰ׺
// frame_count: �ܹ�����ͼƬ
// delay: ÿ��������ͼƬ֮���ʱ����
cocos2d::Animation* GetAnimationFromPlist(const char *pPrefixName,
                                            int frame_count,
                                            float fDelay);

// ��plist�����ɶ���
// prefix_name: ����ͼƬ�Ĺ���ǰ׺
// frame_count: �ܹ�����ͼƬ
// delay: ÿ��������ͼƬ֮���ʱ����
// start_index: �ӵڼ��ſ�ʼѭ�����䷶Χ��[0, frame_count-1]
cocos2d::Animation* GetAnimationFromPlist(const char *pPrefixName,
                                            int nFrameCount,
                                            float fDelay,
                                            int nStartIndex);

}
