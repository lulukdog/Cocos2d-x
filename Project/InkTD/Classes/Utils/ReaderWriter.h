/*******************************************************************************
 �����װ��CCUserDefault��
 *******************************************************************************/

#pragma once

#include "cocos2d.h"

namespace util
{
    
    class ReaderWriter
    {
    public:
        // ��ȡ
        static bool  LoadBooleanFromXML(const std::string &key, bool default_value);
        static int   LoadIntegerFromXML(const std::string &key, int default_value);
        static float LoadFloatFromXML(const std::string &key, float default_value);
        static std::string LoadStringFromXML(const std::string &key, const std::string &default_value);
        
        // д��
        static void SaveBooleanToXML(const std::string &key, bool value);
        static void SaveIntegerToXML(const std::string &key, int value);
        static void SaveFloatToXML(const std::string &key, float value);
        static void SaveStringToXML(const std::string &key, const std::string &value);
        
        // ˢ��
        static void Flush();
        
    public:
        // ��xml�м���key��Ӧ�����ݲ����أ����û�ҵ�����default_value
        static std::string GetStringForKey(const std::string &key, const std::string &default_value);
        
        // ��(key, default_value)���浽xml��
        static void SaveStringForKey(const std::string &key, const std::string &value);
        
        // ����
        static std::string Encode(const std::string &content);
        
        // ����
        static std::string Decode(const std::string &content);
        
        // �Ƿ�����[A-Z|a-z|0-9|+|/]
        static bool IsBase64Char(char c);
    };
    
}
