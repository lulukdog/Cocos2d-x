/*******************************************************************************
 �������ֵ���
 ���ô���������֣���Ҫ��
 1. �ڿ�ʼ��Ϸʱ������splash���棩����MusicUtil::DoInit()���г�ʼ����������
 MusicUtil::PreloadEffect �� MusicUtil::PreloadBackgroundMusic��Ԥ����������Դ
 2. ��AppDelegate::applicationDidEnterBackground�е���MusicUtil::PauseBackgroundMusic��ͣ��������
 3. ��AppDelegate::applicationWillEnterForeground�е���MusicUtil::EnterForeground�ָ���������
 4. ��AppDelegate::~AppDelegate�е���MusicUtil::End��������
 5. ����ϷҪ�˳�ʱ���Զ����浱ǰ�����á������Ҫ�ֶ��������ã���������л������ֻ���Ч�Ŀ��������������棩��
 ����MusicUtil::SaveSettings��
 6. ��Ҫ��A�������B����ʱ����A����ı������ֲ��ţ��������������B����ʱ���´�ͷ��ʼ���ţ������������ã�
 ��A����Bǰ����MusicUtil::setReplayMusicState(false)��
 ��B��onEnter��PlayBackgroundMusic������MusicUtil::setReplayMusicState(true)
 ********************************************************************************/

#ifndef UTIL_MUSICUTIL_H_
#define UTIL_MUSICUTIL_H_

#include <string>

namespace util
{
    class MusicUtil
    {
    public:
        // ���ļ��ж�ȡ��������
        static void initialize();
    public:
        // ���������Ƿ���
        static bool isBackgroundMusicOn() { return bBgMusicOn; }
        // ���ñ������ֿ���
        static void setBackgroundMusicState(bool bValue);
        // ��Ч�����Ƿ���
        static bool isEffectMusicOn() { return bEffectMusicOn; }
        // ��ȡ�������ִ�С
        static float getMusicVolume() { return fMusicVolume; };
        // ��ȡ������С
        static float getEffectVolume() { return fEffectVolume; }
        // ������Ч��������
        static void setEffectMusicState(bool bValue) { bEffectMusicOn = bValue; }
        // ���������Ƿ�Ӧ�����²���
        static void setReplayMusicState(bool bValue) { bReplayMusic = bValue; }
    public:
        // ������Ч
        static void preloadEffect(const char* pszPath);
        // ���ر�������
        static void preloadBackgroundMusic(const char* pszPath);
        // ���ű�������
        // pszName: ������������
        // bValue: �Ƿ�ѭ������
        static void playBackgroundMusic(const char* pszName, bool bValue);
        // ��ͣ
        static void pauseBackgroundMusic();
        // �ָ�
        static void resumeBackgroundMusic();
        // ����
        static void rewindBackgroundMusic();
        // ֹͣ
        static void stopBackgroundMusic();
        // ֹͣ������Ч,�Ѽ�¼�ġ�
        static void stopAllEffect();
        
        static void pauseEffect();
        
        static void resumeEffect();
        // ������Ч������music_nameΪ��Ч��������
        static unsigned int playEffectMusic(const char* pszName);
        // ��Ϸ����ǰ̨
        static void enterForeground();
        // �������ֵĴ�С
        static void setMusicVolume(float fMusicVolume);
        // ������Ч�Ĵ�С
        static void setEffectVolume(float fMusicVolume);
        // �������õ��ļ�
        static void saveSettings();
        // �������ֲ��ţ�����Ϸ��Ҫ�˳�ʱ���ã�
        static void end();
        // �������ֳ���
        static void setOnMusicScene(bool bValue) { bPlayOnscene = bValue; }
        
        //���� ���þ���ģʽ
        static bool isSilentMode();
        static void setSilentMode(bool value);
        
    private:
        static bool         bBgMusicOn;            // ���������Ƿ���
        static bool         bEffectMusicOn;        // ��Ч�����Ƿ���
        static bool         bReplayMusic;          // ���Ʊ��������Ƿ�Ӧ��ͷ���²���
        static std::string  sBgMusicName;          // �ϴβ��ŵı������ֵ�����
        static bool         bPlayBgMusic;
        static bool         bPlayOnscene;
        static float        fMusicVolume;          // ���ֵ�������С
        static float        fEffectVolume;         // ��Ч�Ĵ�С
        static bool         bSilentMode;           // ����ģʽ
    };
}
#endif // UTIL_MUSICUTIL_H_