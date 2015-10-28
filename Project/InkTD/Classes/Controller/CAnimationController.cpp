// #include "CAnimationController.h"
// #include "Core/AppRes.h"
// 
// USING_NS_CC;
// 
// CAnimationController::CAnimationController()
// {
// }
// 
// CAnimationController::~CAnimationController()
// {
// }
// 
// void CAnimationController::playBoomAnimation(Layer* pContainer, Vec2 &vPos)
// {
// 	auto pSprtieFrameCache = SpriteFrameCache::getInstance();
// 	pSprtieFrameCache->addSpriteFramesWithFile(ANIMATION_BOOM_PLIST);
// 
// 	auto pSprite = Sprite::create();
// 	pSprite->setPosition(vPos);
// 	pContainer->addChild(pSprite);
// 
// 	Vector<cocos2d::SpriteFrame *> vArr;
// 	char str[100] = { 0 };
// 	for (int i = 1; i < 5; i++)
// 	{
// 		sprintf(str, "boom_%d.png", i);
// 		auto pFrame = pSprtieFrameCache->getSpriteFrameByName(str);
// 		vArr.pushBack(pFrame);
// 	}
// 
// 	auto pAnimation = Animation::createWithSpriteFrames(vArr, 1 / 45.0f);
// 	pSprite->runAction(Sequence::create(Animate::create(pAnimation),
// 		                                RemoveSelf::create(),
// 										nullptr));
// }
// 
// 
// void CAnimationController::playBloodAnimation(Sprite* pSprite, float fAngle)
// {
// 	auto pSprtieFrameCache = SpriteFrameCache::getInstance();
// 	pSprtieFrameCache->addSpriteFramesWithFile(ANIMATION_BLOOD_PLIST);
// 
// 	auto pSpriteA = Sprite::create();
// 	pSpriteA->setAnchorPoint(Vec2(0.3, 1));
// 	pSpriteA->setRotation(fAngle - 180);
// 	pSpriteA->setPosition(Vec2(pSprite->getContentSize().width / 2, pSprite->getContentSize().height / 2));
// 	pSprite->addChild(pSpriteA);
// 	Vector<cocos2d::SpriteFrame *> vArr;
// 	char str[100] = { 0 };
// 	for (int i = 1; i < 49; i++)
// 	{
// 		sprintf(str, "blood_%d.png", i);
// 		auto pFrame = pSprtieFrameCache->getSpriteFrameByName(str);
// 		vArr.pushBack(pFrame);
// 	}
// 
// 	auto pAnimation = Animation::createWithSpriteFrames(vArr, 1 / 30.0f);
// 	pSpriteA->runAction(Sequence::create(Animate::create(pAnimation),
// 										RemoveSelf::create(),
// 										nullptr));
// }
// 
// CPices* CAnimationController::playBox2PicesAnimation(cocos2d::Layer* pContainer, const Vec2 &vPos)
// {
// 	auto pSprtieFrameCache = SpriteFrameCache::getInstance();
// 	pSprtieFrameCache->addSpriteFramesWithFile(ANIMATION_BOX2_PLIST);
// 	CPices* pSprite = CPices::create();
// 	pSprite->setPosition(vPos);
// 	pContainer->addChild(pSprite);
// 	Vector<cocos2d::SpriteFrame *> vArr;
// 	char str[100] = { 0 };
// 	for (int i = 1; i < 5; i++)
// 	{
// 		sprintf(str, "box2_%d.png", i);
// 		auto pFrame = pSprtieFrameCache->getSpriteFrameByName(str);
// 		vArr.pushBack(pFrame);
// 	}
// 	auto pAnimation = Animation::createWithSpriteFrames(vArr, 1 / 30.0f);
// 	pSprite->runAction(RepeatForever::create(Animate::create(pAnimation)));
// 	return pSprite;
// }
// 
// CPices* CAnimationController::playBoomPicesAnimation(cocos2d::Layer* pContainer, const Vec2 &vPos)
// {
// 	auto pSprtieFrameCache = SpriteFrameCache::getInstance();
// 	pSprtieFrameCache->addSpriteFramesWithFile(ANIMATION_BOOM1_PIST);
// 	CPices* pSprite = CPices::create();
// 	pSprite->setPosition(vPos);
// 	pContainer->addChild(pSprite);
// 	Vector<cocos2d::SpriteFrame *> vArr;
// 	char str[100] = { 0 };
// 	for (int i = 1; i < 5; i++)
// 	{
// 		sprintf(str, "boom1_%d.png", i);
// 		auto pFrame = pSprtieFrameCache->getSpriteFrameByName(str);
// 		vArr.pushBack(pFrame);
// 	}
// 	auto pAnimation = Animation::createWithSpriteFrames(vArr, 1 / 30.0f);
// 	pSprite->runAction(RepeatForever::create(Animate::create(pAnimation)));
// 	return pSprite;
// }
// 
// static void playBulletAnimation(cocos2d::Layer* pContainer, const cocos2d::Vec2 &vPos)
// {
// 	auto pSprtieFrameCache = SpriteFrameCache::getInstance();
// 	pSprtieFrameCache->addSpriteFramesWithFile(ANIMATION_BOX2_PLIST);
// 
// 	CPices* pSprite = CPices::create();
// 	pSprite->setPosition(vPos);
// 	pContainer->addChild(pSprite);
// 
// 	Vector<cocos2d::SpriteFrame *> vArr;
// 	char str[100] = { 0 };
// 	for (int i = 1; i < 5; i++)
// 	{
// 		sprintf(str, "box2_%d.png", i);
// 		auto pFrame = pSprtieFrameCache->getSpriteFrameByName(str);
// 		vArr.pushBack(pFrame);
// 	}
// 
// 	auto pAnimation = Animation::createWithSpriteFrames(vArr, 1 / 30.0f);
// 	pSprite->runAction(RepeatForever::create(Animate::create(pAnimation)));
// 
// }