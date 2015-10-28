/*******************************************************************************
 此类封装了CCUserDefault。
 *******************************************************************************/

#pragma once

#include "cocos2d.h"

namespace util
{
    
    class ReaderWriter
    {
    public:
        // 读取
        static bool  LoadBooleanFromXML(const std::string &key, bool default_value);
        static int   LoadIntegerFromXML(const std::string &key, int default_value);
        static float LoadFloatFromXML(const std::string &key, float default_value);
        static std::string LoadStringFromXML(const std::string &key, const std::string &default_value);
        
        // 写入
        static void SaveBooleanToXML(const std::string &key, bool value);
        static void SaveIntegerToXML(const std::string &key, int value);
        static void SaveFloatToXML(const std::string &key, float value);
        static void SaveStringToXML(const std::string &key, const std::string &value);
        
        // 刷新
        static void Flush();
        
    public:
        // 从xml中加载key对应的内容并返回，如果没找到返回default_value
        static std::string GetStringForKey(const std::string &key, const std::string &default_value);
        
        // 将(key, default_value)保存到xml中
        static void SaveStringForKey(const std::string &key, const std::string &value);
        
        // 加密
        static std::string Encode(const std::string &content);
        
        // 解密
        static std::string Decode(const std::string &content);
        
        // 是否属于[A-Z|a-z|0-9|+|/]
        static bool IsBase64Char(char c);
    };
    
}
