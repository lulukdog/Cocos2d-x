
#pragma  once
#include "cocos2d.h"

class EffectUtil
{
public:
	 static void setEnableRecursiveCascading(cocos2d::Node* pNode, bool bEnable);

	 /*
     *pNode      要做动作的对象
     *fTime      动作持续时间
     *fValue     透明度变化值
     *fDistence  往上移动的距离
     *pCallBackFunc 最后的回调函数
     */
	 static void doFadeInAndMoveAction(cocos2d::Node* pNode, float fTime = 0.3f, GLubyte fValue = 0xFF, 
		                               float fDistence = 20.0f, cocos2d::CallFunc* pCallBackFunc = NULL);

	 /*
     *pNode      要做动作的对象
     *fTime      动作持续时间
     *fValue     透明度变化值
     *pCallBackFunc 最后的回调函数
     */
	 static void doFadeOutAction(cocos2d::Node* pNode, float fTime, GLubyte fValue, cocos2d::CallFunc* pCallBackFuc);
};

 