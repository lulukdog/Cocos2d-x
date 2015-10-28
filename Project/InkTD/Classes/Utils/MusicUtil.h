/*******************************************************************************
 处理音乐的类
 若用此类管理音乐，需要：
 1. 在开始游戏时（比如splash界面）调用MusicUtil::DoInit()进行初始化，并且用
 MusicUtil::PreloadEffect 和 MusicUtil::PreloadBackgroundMusic来预加载音乐资源
 2. 在AppDelegate::applicationDidEnterBackground中调用MusicUtil::PauseBackgroundMusic暂停背景音乐
 3. 在AppDelegate::applicationWillEnterForeground中调用MusicUtil::EnterForeground恢复背景音乐
 4. 在AppDelegate::~AppDelegate中调用MusicUtil::End结束音乐
 5. 在游戏要退出时会自动保存当前的设置。如果想要手动保存设置（比如玩家切换了音乐或音效的开启就想立即保存），
 调用MusicUtil::SaveSettings。
 6. 若要从A界面进入B界面时继续A界面的背景音乐播放，在其他界面进入B界面时重新从头开始播放，可以这样设置：
 在A进入B前设置MusicUtil::setReplayMusicState(false)，
 在B的onEnter中PlayBackgroundMusic后设置MusicUtil::setReplayMusicState(true)
 ********************************************************************************/

#ifndef UTIL_MUSICUTIL_H_
#define UTIL_MUSICUTIL_H_

#include <string>

namespace util
{
    class MusicUtil
    {
    public:
        // 从文件中读取音乐设置
        static void initialize();
    public:
        // 背景音乐是否开了
        static bool isBackgroundMusicOn() { return bBgMusicOn; }
        // 设置背景音乐开关
        static void setBackgroundMusicState(bool bValue);
        // 特效声音是否开了
        static bool isEffectMusicOn() { return bEffectMusicOn; }
        // 获取背景音乐大小
        static float getMusicVolume() { return fMusicVolume; };
        // 获取声音大小
        static float getEffectVolume() { return fEffectVolume; }
        // 设置特效声音开关
        static void setEffectMusicState(bool bValue) { bEffectMusicOn = bValue; }
        // 设置音乐是否应该重新播放
        static void setReplayMusicState(bool bValue) { bReplayMusic = bValue; }
    public:
        // 加载音效
        static void preloadEffect(const char* pszPath);
        // 加载背景音乐
        static void preloadBackgroundMusic(const char* pszPath);
        // 播放背景音乐
        // pszName: 背景音乐名字
        // bValue: 是否循环播放
        static void playBackgroundMusic(const char* pszName, bool bValue);
        // 暂停
        static void pauseBackgroundMusic();
        // 恢复
        static void resumeBackgroundMusic();
        // 回绕
        static void rewindBackgroundMusic();
        // 停止
        static void stopBackgroundMusic();
        // 停止所有音效,已记录的。
        static void stopAllEffect();
        
        static void pauseEffect();
        
        static void resumeEffect();
        // 播放特效声音，music_name为特效声音名字
        static unsigned int playEffectMusic(const char* pszName);
        // 游戏进入前台
        static void enterForeground();
        // 设置音乐的大小
        static void setMusicVolume(float fMusicVolume);
        // 设置音效的大小
        static void setEffectVolume(float fMusicVolume);
        // 保存设置到文件
        static void saveSettings();
        // 结束音乐播放（在游戏将要退出时调用）
        static void end();
        // 设置音乐场景
        static void setOnMusicScene(bool bValue) { bPlayOnscene = bValue; }
        
        //开启 设置静音模式
        static bool isSilentMode();
        static void setSilentMode(bool value);
        
    private:
        static bool         bBgMusicOn;            // 背景音乐是否开了
        static bool         bEffectMusicOn;        // 特效声音是否开了
        static bool         bReplayMusic;          // 控制背景音乐是否应从头重新播放
        static std::string  sBgMusicName;          // 上次播放的背景音乐的名称
        static bool         bPlayBgMusic;
        static bool         bPlayOnscene;
        static float        fMusicVolume;          // 音乐的音量大小
        static float        fEffectVolume;         // 音效的大小
        static bool         bSilentMode;           // 静音模式
    };
}
#endif // UTIL_MUSICUTIL_H_