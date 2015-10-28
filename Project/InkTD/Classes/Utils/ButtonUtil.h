
#ifndef __WKKP__ButtonUtil__
#define __WKKP__ButtonUtil__

#include <stdio.h>
#include "cocos2d.h"


class ButtonUtil
{
public:
    //创建点击置灰的button
    static cocos2d::MenuItem* createGrayBtn(const char* pszName,
                                            const cocos2d::ccMenuCallback &fucCallBack,
                                            bool bExpandTouchSize = false);

	//创建点击置灰的button
	static cocos2d::MenuItem* createScaleBtn(const char* pszName,
		                                               const cocos2d::ccMenuCallback &fucCallBack,
		                                               bool bExpandTouchSize = false);
	//创建点击置灰的button
	static cocos2d::MenuItem* createLabelBtn(const char* pszContent, const char* pszName, 
		                                        const cocos2d::ccMenuCallback &fucCallBack,
		                                        bool bExpandTouchSize = false);
};

#endif