#include "AnimateUtil.h"
#include "Utils.h"


USING_NS_CC;

namespace util
{
    
    Animation* GetAnimationFromFile(const char* pPrefixName, int nFramecount, float fDelay)
    {
        return GetAnimationFromFile(pPrefixName, nFramecount, fDelay, 0);
    }
    
    Animation* GetAnimationFromFile(const char* pPrefixName, int nFramecount, float fDelay, int nStartIndex)
    {
        Vector<SpriteFrame*> vFrames;
        for (int i = 0; i < nFramecount; i++)
        {
            const char *pFrameName = str_format("%s%d.png", pPrefixName, nStartIndex + i);
            SpriteFrame *pFrame = GetFrameFromFile(pFrameName);
            vFrames.pushBack(pFrame);
        }
        Animation *pAnimation = Animation::createWithSpriteFrames(vFrames, fDelay);
        //当动画播放完后，帧序是否重设为默认第一帧
        pAnimation->setRestoreOriginalFrame(false);
        return pAnimation;
    }
    
    Animation* GetAnimationFromPlist(const char* pPrefixName, int nFramecount, float fDelay)
    {
        return GetAnimationFromPlist(pPrefixName, nFramecount, fDelay, 0);
    }
    
    Animation* GetAnimationFromPlist(const char* pPrefixName, int nFramecount, float fDelay, int nStartIndex)
    {
        Vector<SpriteFrame*> vFrames;
        std::string sPrefixName(pPrefixName);
        for (int i = 0; i < nFramecount; i++)
        {
            const char *pFrameName = str_format("%s%d.png", sPrefixName.c_str(), nStartIndex + i);
            SpriteFrame *pFrame = GetFrameFromPlist(pFrameName);
            vFrames.pushBack(pFrame);
        }
        Animation *pAnimation = Animation::createWithSpriteFrames(vFrames, fDelay);
        //当动画播放完后，帧序是否重设为默认第一帧
        pAnimation->setRestoreOriginalFrame(true);
        return pAnimation;
    }
    
}
