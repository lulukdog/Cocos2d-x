#include "ReaderWriter.h"
#include "MacroUtil.h"

USING_NS_CC;
using namespace std;

namespace util
{
    
    bool ReaderWriter::LoadBooleanFromXML(const string &key, bool default_value)
    {
        return LoadIntegerFromXML(key, default_value) == 1;
    }
    
    int ReaderWriter::LoadIntegerFromXML(const string &key, int default_value)
    {
        const string kEncodedKey = Encode(key);
        const string kEncodedDefaultValue = Encode(int2str(default_value));
        const string kValue = GetStringForKey(kEncodedKey, kEncodedDefaultValue);
        return atoi(Decode(kValue).c_str());
    }
    
    float ReaderWriter::LoadFloatFromXML(const string &key, float default_value)
    {
        const string kEncodedKey = Encode(key);
        const string kEncodedDefaultValue = Encode(float2str(default_value));
        const string kValue = GetStringForKey(kEncodedKey, kEncodedDefaultValue);
        return atof(Decode(kValue).c_str());
    }
    
    string ReaderWriter::LoadStringFromXML(const string &key, const string &default_value)
    {
        const string kEncodedKey = Encode(key);
        const string kEncodedDefaultValue = Encode(default_value);
        const string kValue = GetStringForKey(kEncodedKey, kEncodedDefaultValue);
        return Decode(kValue);
    }
    
    void ReaderWriter::SaveBooleanToXML(const string &key, bool value)
    {
        SaveStringForKey(Encode(key), Encode(int2str(value)));
    }
    
    void ReaderWriter::SaveIntegerToXML(const string &key, int value)
    {
        SaveStringForKey(Encode(key), Encode(int2str(value)));
    }
    
    void ReaderWriter::SaveFloatToXML(const string &key, float value)
    {
        SaveStringForKey(Encode(key), Encode(float2str(value)));
    }
    
    void ReaderWriter::SaveStringToXML(const string &key, const string &value)
    {
        SaveStringForKey(Encode(key), Encode(value));
    }
    
    void ReaderWriter::Flush()
    {
        UserDefault::getInstance()->flush();
    }
    
    string ReaderWriter::GetStringForKey(const string &key, const string &default_value)
    {
        return UserDefault::getInstance()->getStringForKey(key.c_str(), default_value);
    }
    
    void ReaderWriter::SaveStringForKey(const string &key, const string &value)
    {
        UserDefault::getInstance()->setStringForKey(key.c_str(), value);
        UserDefault::getInstance()->flush();
    }
    
    static const string kBase64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    
    string ReaderWriter::Encode(const string &content)
    {
        string ret;
        int i = 0;
        int j = 0;
        char array_3[3];
        char array_4[4];
        for (int k = 0; k < content.size(); k++)
        {
            array_3[i++] = content[k];
            if (i == 3)
            {
                array_4[0] = (array_3[0] & 0xfc) >> 2;
                array_4[1] = ((array_3[0] & 0x03) << 4) + ((array_3[1] & 0xf0) >> 4);
                array_4[2] = ((array_3[1] & 0x0f) << 2) + ((array_3[2] & 0xc0) >> 6);
                array_4[3] = array_3[2] & 0x3f;
                for (i = 0; i < 4; i++)
                {
                    ret += kBase64Chars[array_4[i]];
                }
                i = 0;
            }
        }
        if (i != 0)
        {
            for (j = i; j < 3; j++)
            {
                array_3[j] = '\0';
            }
            array_4[0] = (array_3[0] & 0xfc) >> 2;
            array_4[1] = ((array_3[0] & 0x03) << 4) + ((array_3[1] & 0xf0) >> 4);
            array_4[2] = ((array_3[1] & 0x0f) << 2) + ((array_3[2] & 0xc0) >> 6);
            array_4[3] = array_3[2] & 0x3f;
            for (j = 0; j < i + 1; j++)
            {
                ret += kBase64Chars[array_4[j]];
            }
            while (i++ < 3)
            {
                ret += '_';
            }
        }
        return ret;
    }
    
    string ReaderWriter::Decode(const string &content)
    {
        string ret;
        int i = 0;
        int j = 0;
        int index = 0;
        char array_3[3];
        char array_4[4];
        string::size_type length = content.size();
        while (length-- && (content[index] != '_') && IsBase64Char(content[index]))
        {
            array_4[i++] = content[index];
            index++;
            if (i == 4)
            {
                for (i = 0; i < 4; i++)
                {
                    array_4[i] = kBase64Chars.find(array_4[i]);
                }
                array_3[0] = (array_4[0] << 2) + ((array_4[1] & 0x30) >> 4);
                array_3[1] = ((array_4[1] & 0xf) << 4) + ((array_4[2] & 0x3c) >> 2);
                array_3[2] = ((array_4[2] & 0x3) << 6) + array_4[3];
                for(i = 0; i < 3; i++)
                {
                    ret += array_3[i];
                }
                i = 0;
            }
        }
        if (i != 0)
        {
            for (j = i; j < 4; j++)
            {
                array_4[j] = 0;
            }
            for (j = 0; j < i; j++)
            {
                array_4[j] = kBase64Chars.find(array_4[j]);
            }
            array_3[0] = (array_4[0] << 2) + ((array_4[1] & 0x30) >> 4);
            array_3[1] = ((array_4[1] & 0xf) << 4) + ((array_4[2] & 0x3c) >> 2);
            array_3[2] = ((array_4[2] & 0x3) << 6) + array_4[3];
            for (j = 0; j < i - 1; j++)
            {
                ret += array_3[j];
            }
        }
        return ret;
    }
    
    bool ReaderWriter::IsBase64Char(char c)
    {
        return (isalnum(c) || (c == '+') || (c == '/'));
    }
}