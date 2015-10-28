#include "MusicUtil.h"
#include "ReaderWriter.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
using namespace std;

namespace util
{
    // 读取音乐设置的key
    #define KEY_MUSIC         "keyMusic"
    #define KEY_EFFECT        "keyEffect"
    #define KEY_MUSIC_VOLUME  "keyMusicVolume"
    #define KEY_EFFECT_VOLUME "keyEffectVolume"
    #define KEY_SILENTMODE    "keySilentMode"
    
    float   MusicUtil::fMusicVolume   = 1.0f;
    float   MusicUtil::fEffectVolume  = 1.0f;
    bool    MusicUtil::bBgMusicOn     = true;
    bool    MusicUtil::bEffectMusicOn = true;
    bool    MusicUtil::bReplayMusic   = true;
    bool    MusicUtil::bPlayBgMusic   = false;
    bool    MusicUtil::bPlayOnscene   = false;   // 是否在播放页面
    bool    MusicUtil::bSilentMode    = false;
    string  MusicUtil::sBgMusicName;
    
    void MusicUtil::initialize()
    {
        // 读取音乐音效设置
        bBgMusicOn     = ReaderWriter::LoadBooleanFromXML(KEY_MUSIC, true);
        bEffectMusicOn = ReaderWriter::LoadBooleanFromXML(KEY_EFFECT, true);
        fMusicVolume   = ReaderWriter::LoadFloatFromXML(KEY_MUSIC_VOLUME, 1);
        fEffectVolume  = ReaderWriter::LoadFloatFromXML(KEY_EFFECT_VOLUME, 1);
        bSilentMode    = ReaderWriter::LoadBooleanFromXML(KEY_SILENTMODE, false);
        
        setMusicVolume(fMusicVolume);
        setEffectVolume(fEffectVolume);
    }
    
    void MusicUtil::preloadEffect(const char* pszName)
    {
        SimpleAudioEngine::getInstance()->preloadEffect(pszName);
    }
    
    void MusicUtil::preloadBackgroundMusic(const char* pszName)
    {
        SimpleAudioEngine::getInstance()->preloadBackgroundMusic(pszName);
    }
    
    void MusicUtil::enterForeground()
    {
        if (bBgMusicOn)
        {
            SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
        }
    }
    
    void MusicUtil::playBackgroundMusic(const char* pszName, bool bValue)
    {
        sBgMusicName = pszName;
        bPlayOnscene = true;
        if (bBgMusicOn && bReplayMusic)
        {
            bPlayBgMusic = true;
            SimpleAudioEngine::getInstance()->playBackgroundMusic(pszName, bValue);
        }
    }
    
    void MusicUtil::pauseBackgroundMusic()
    {
        if (bPlayBgMusic)
        {
            SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
        }
    }
    
    void MusicUtil::resumeBackgroundMusic()
    {
        if (bBgMusicOn && bPlayBgMusic)
        {
            SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
        }
    }
    
    void MusicUtil::pauseEffect()
    {
        if (bEffectMusicOn)
        {
            SimpleAudioEngine::getInstance()->pauseAllEffects();
        }
    }
    
    void MusicUtil::resumeEffect()
    {
        if (bEffectMusicOn)
        {
            SimpleAudioEngine::getInstance()->resumeAllEffects();
        }
    }
    
    void MusicUtil::rewindBackgroundMusic()
    {
        if(bBgMusicOn)
        {
            SimpleAudioEngine::getInstance()->rewindBackgroundMusic();
        }
    }
    
    void MusicUtil::stopBackgroundMusic()
    {
        bPlayBgMusic = false;
        bPlayOnscene = false;
        SimpleAudioEngine::getInstance()->stopBackgroundMusic(false);
    }
    
    void MusicUtil::stopAllEffect()
    {
        SimpleAudioEngine::getInstance()->stopAllEffects();
    }
    
    unsigned int MusicUtil::playEffectMusic(const char* pszName)
    {
        if (bEffectMusicOn)
        {
            return SimpleAudioEngine::getInstance()->playEffect(pszName);
        }
        return 0;
    }
    
    void MusicUtil::setMusicVolume(float bValue)
    {
        fMusicVolume = bValue;
        SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(bValue);
    }
    
    void MusicUtil::setEffectVolume(float bValue)
    {
        
        fEffectVolume = bValue;
        SimpleAudioEngine::getInstance()->setEffectsVolume(bValue);
    }
    
    void MusicUtil::setBackgroundMusicState(bool bValue)
    {
        if (bBgMusicOn == bValue)
        {
            return;
        }
        bBgMusicOn = bValue;
        if (bBgMusicOn)
        {
            bPlayBgMusic = true;
            if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
            {
                // 播放过背景音乐，直接恢复
                SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
            }
            else
            {
                // 没有播放过背景音乐，开始播放背景音乐
                // 如果在音乐场景，开始播放
                if (bPlayOnscene)
                {
                    SimpleAudioEngine::getInstance()->playBackgroundMusic(sBgMusicName.c_str(), true);
                }
            }
        }
        else
        {
            // 暂停背景音乐
            bPlayBgMusic = false;
            SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
        }
    }
    
    bool MusicUtil::isSilentMode()
    {
        return bSilentMode;
    }
    
    void MusicUtil::setSilentMode(bool bValue)
    {
        bSilentMode = bValue;
    }
    
    void MusicUtil::saveSettings()
    {
        ReaderWriter::SaveBooleanToXML(KEY_MUSIC, bBgMusicOn);
        ReaderWriter::SaveBooleanToXML(KEY_EFFECT, bEffectMusicOn);
        ReaderWriter::SaveBooleanToXML(KEY_SILENTMODE,bSilentMode);
        ReaderWriter::SaveFloatToXML(KEY_MUSIC_VOLUME, fMusicVolume);
        ReaderWriter::SaveFloatToXML(KEY_EFFECT_VOLUME, fEffectVolume);
        ReaderWriter::Flush();
    }
    
    void MusicUtil::end()
    {
        // 游戏结束前保存一次设置，以免忘了游戏中忘记保存了
        saveSettings();
        SimpleAudioEngine::end();
    }
}