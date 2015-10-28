/*******************************************************************************
此文件中的方法用于生成动画，可以生成两种方式的动画：
1. 根据图片序列公共前缀，图片数量，每帧持续时间生成一个动画并返回
   比如fire0.png, fire1.png, fire2.png, fire3.png，每张图片持续0.05秒，可以如下调用：
   GetAnimationFromFile("fire", 4, 0.05f);
2. 根据图片序列公共前缀，图片数量，每帧持续时间，以及从第几帧开始播放生成一个动画并返回
   比如按照fire2.png, fire3.png, fire0.png, fire1.png顺序播放，可以如下调用：
   GetAnimationFromFile("fire", 4, 0.05f, 2);
对于上述两个函数，各有一个重载版本，其第一个参数为boool类型，表示是否从plist中获取CCSpriteFrame
*******************************************************************************/

#pragma once

#include "cocos2d.h"

namespace util
{

// 从单个文件中生成动画
// prefix_name: 序列图片的公共前缀
// frame_count: 总共几张图片
// delay: 每相邻两张图片之间的时间间隔
cocos2d::Animation* GetAnimationFromFile(const char *pPrefixName,
                                           int nFrameCount,
                                           float fDelay);

// 从单个文件中生成动画
// prefix_name: 序列图片的公共前缀
// frame_count: 总共几张图片
// delay: 每相邻两张图片之间的时间间隔
// start_index: 从第几张开始循环，其范围在[0, frame_count-1]
cocos2d::Animation* GetAnimationFromFile(const char *pPrefixName,
                                           int nFrameCount,
                                           float fDelay,
                                           int nStartIndex);

// 从plist中生成动画
// prefix_name: 序列图片的公共前缀
// frame_count: 总共几张图片
// delay: 每相邻两张图片之间的时间间隔
cocos2d::Animation* GetAnimationFromPlist(const char *pPrefixName,
                                            int frame_count,
                                            float fDelay);

// 从plist中生成动画
// prefix_name: 序列图片的公共前缀
// frame_count: 总共几张图片
// delay: 每相邻两张图片之间的时间间隔
// start_index: 从第几张开始循环，其范围在[0, frame_count-1]
cocos2d::Animation* GetAnimationFromPlist(const char *pPrefixName,
                                            int nFrameCount,
                                            float fDelay,
                                            int nStartIndex);

}
