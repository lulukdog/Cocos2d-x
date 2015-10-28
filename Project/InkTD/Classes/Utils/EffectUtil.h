
#pragma  once
#include "cocos2d.h"

class EffectUtil
{
public:
	 static void setEnableRecursiveCascading(cocos2d::Node* pNode, bool bEnable);

	 /*
     *pNode      Ҫ�������Ķ���
     *fTime      ��������ʱ��
     *fValue     ͸���ȱ仯ֵ
     *fDistence  �����ƶ��ľ���
     *pCallBackFunc ���Ļص�����
     */
	 static void doFadeInAndMoveAction(cocos2d::Node* pNode, float fTime = 0.3f, GLubyte fValue = 0xFF, 
		                               float fDistence = 20.0f, cocos2d::CallFunc* pCallBackFunc = NULL);

	 /*
     *pNode      Ҫ�������Ķ���
     *fTime      ��������ʱ��
     *fValue     ͸���ȱ仯ֵ
     *pCallBackFunc ���Ļص�����
     */
	 static void doFadeOutAction(cocos2d::Node* pNode, float fTime, GLubyte fValue, cocos2d::CallFunc* pCallBackFuc);
};

 