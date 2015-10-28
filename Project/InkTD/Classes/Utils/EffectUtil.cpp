#include "EffectUtil.h"

USING_NS_CC;

void EffectUtil::setEnableRecursiveCascading(cocos2d::Node* pNode, bool bEnable)
{	if (!pNode)
	{
		return;
	}
	pNode->setCascadeColorEnabled(bEnable);
	pNode->setOpacityModifyRGB(bEnable);
	Vector<Node*> vChildren = pNode->getChildren();
	for(auto& child : vChildren)
	{

		Node* pChild = (Node*)child;
		setEnableRecursiveCascading(pChild, bEnable);
	}
}

void EffectUtil::doFadeInAndMoveAction(cocos2d::Node* pNode, float fTime /* = 0.3f */, 
									   GLubyte fValue /* = 0xFF */, float fDistence /* = 20.0f */, 
									   cocos2d::CallFunc* pCallBackFunc /* = NULL */)
{	if (!pNode)	{		return;	}	pNode->setVisible(true);	FadeTo *pFadeIn = FadeTo::create(fTime, fValue);
	pNode->setOpacity(0x00);
	pNode->setPositionY(pNode->getPositionY() - fDistence);
	MoveBy *pMoveBy = MoveBy::create(fTime, Vec2(0, fDistence));
	pNode->runAction(Sequence::create(Spawn::create(pMoveBy,
													pFadeIn,
													nullptr),
													pCallBackFunc,
													nullptr));
}

void EffectUtil::doFadeOutAction(cocos2d::Node* pNode, float fTime, GLubyte fValue, cocos2d::CallFunc* pCallBackFuc)
{
	FadeTo *pFadeOut = FadeTo::create(fTime, fValue);
	pNode->runAction(Sequence::create(pFadeOut,
									  pCallBackFuc,
									  nullptr));
}
