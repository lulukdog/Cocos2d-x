//
//  ButtonUtil.cpp
//  WKKP
//
//  Created by mtt on 14-11-1.
//
//

#include "ButtonUtil.h"

USING_NS_CC;

MenuItem* ButtonUtil::createGrayBtn(const char *pszName, 
											  const cocos2d::ccMenuCallback &fucCallBack, 
											  bool bExpandTouchSize)
{
    
    auto pButtonItemUp   = Sprite::create(pszName);
    auto pButtonItemDown = Sprite::create(pszName);
    MenuItem* pButtonItem = NULL;
    if (bExpandTouchSize)
    {
        auto pSpriteUpContainer = Sprite::create();
        pSpriteUpContainer->setContentSize(Size(pButtonItemUp->getContentSize().width + 30,
                                                pButtonItemDown->getContentSize().height + 30));
        pButtonItemUp->setPosition(Vec2(pSpriteUpContainer->getContentSize().width / 2,
                                        pSpriteUpContainer->getContentSize().height / 2));
        pSpriteUpContainer->addChild(pButtonItemUp);
        
        auto pSpriteDownContainer = Sprite::create();
        pSpriteDownContainer->setContentSize(Size(pButtonItemDown->getContentSize().width + 30,
                                                  pButtonItemDown->getContentSize().height + 30));
        pButtonItemDown->setPosition(Vec2(pSpriteDownContainer->getContentSize().width / 2,
                                          pSpriteDownContainer->getContentSize().height / 2));
        pSpriteDownContainer->addChild(pButtonItemDown);
        
        pSpriteDownContainer->setColor(Color3B::GRAY);
        pSpriteDownContainer->setCascadeColorEnabled(true);
        
        pButtonItem = MenuItemSprite::create(pSpriteUpContainer,
                                             pSpriteDownContainer,
                                             fucCallBack);
        
    } else
    {
        pButtonItemDown->setColor(Color3B::GRAY);
        pButtonItem = MenuItemSprite::create(pButtonItemUp,
                                             pButtonItemDown,
                                             fucCallBack);
    }
    return pButtonItem;

}

MenuItem* ButtonUtil::createScaleBtn(const char *pszName, 
											  const cocos2d::ccMenuCallback &fucCallBack, 
											  bool bExpandTouchSize)
{

	auto pButtonItemUp   = Sprite::create(pszName);
	auto pButtonItemDown = Sprite::create(pszName);

	MenuItem* pButtonItem = NULL;
	if (bExpandTouchSize)
	{
		auto pSpriteUpContainer = Sprite::create();
		pSpriteUpContainer->setContentSize(Size(pButtonItemUp->getContentSize().width + 30,
			pButtonItemDown->getContentSize().height + 30));
		pButtonItemUp->setPosition(Vec2(pSpriteUpContainer->getContentSize().width / 2,
			pSpriteUpContainer->getContentSize().height / 2));
		pSpriteUpContainer->addChild(pButtonItemUp);

		auto pSpriteDownContainer = Sprite::create();
		pSpriteDownContainer->setContentSize(Size(pButtonItemDown->getContentSize().width + 30,
			pButtonItemDown->getContentSize().height + 30));
		pButtonItemDown->setPosition(Vec2(pSpriteDownContainer->getContentSize().width / 2,
			pSpriteDownContainer->getContentSize().height / 2));
		pSpriteDownContainer->addChild(pButtonItemDown);
		pSpriteDownContainer->setColor(Color3B::GRAY);
		pSpriteDownContainer->setCascadeColorEnabled(true);
		pSpriteDownContainer->setScale(0.95);
		pSpriteDownContainer->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		pButtonItem = MenuItemSprite::create(pSpriteUpContainer,
			pSpriteDownContainer,
			fucCallBack);

	} else
	{
		pButtonItemDown->setColor(Color3B::GRAY);
		pButtonItemDown->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		pButtonItemDown->setScale(0.95f);
		pButtonItem = MenuItemSprite::create(pButtonItemUp,
			pButtonItemDown,
			fucCallBack);
	}
	return pButtonItem;

}

MenuItem* ButtonUtil::createLabelBtn(const char* pszContent,
										const char *pszName, 
										const cocos2d::ccMenuCallback &fucCallBack, 
										bool bExpandTouchSize)
{

	auto pButtonItemUp   = Sprite::create(pszName);
	auto pButtonItemDown = Sprite::create(pszName);

	auto pLabel1 = Label::createWithSystemFont(pszContent, "ºÚÌå", 26);
	auto pLabel2 = Label::createWithSystemFont(pszContent, "ºÚÌå", 26);

	MenuItem* pButtonItem = NULL;
	if (bExpandTouchSize)
	{
		auto pSpriteUpContainer = Sprite::create();
		pSpriteUpContainer->setContentSize(Size(pButtonItemUp->getContentSize().width + 30,
			                                    pButtonItemDown->getContentSize().height + 30));
		pButtonItemUp->setPosition(Vec2(pSpriteUpContainer->getContentSize().width / 2,
			                            pSpriteUpContainer->getContentSize().height / 2));
		pLabel1->setPosition(pButtonItemUp->getPosition());
		pSpriteUpContainer->addChild(pLabel1);
		pSpriteUpContainer->addChild(pButtonItemUp);

		auto pSpriteDownContainer = Sprite::create();
		pSpriteDownContainer->setContentSize(Size(pButtonItemDown->getContentSize().width + 30,
			                                      pButtonItemDown->getContentSize().height + 30));
		pButtonItemDown->setPosition(Vec2(pSpriteDownContainer->getContentSize().width / 2,
			                              pSpriteDownContainer->getContentSize().height / 2));
		pLabel2->setPosition(pButtonItemDown->getPosition());
		pSpriteDownContainer->addChild(pLabel2);
		pSpriteDownContainer->addChild(pButtonItemDown);
		pSpriteDownContainer->setCascadeColorEnabled(true);
		pSpriteDownContainer->setColor(Color3B::GRAY);
		pButtonItem = MenuItemSprite::create(pSpriteUpContainer,
			                                 pSpriteDownContainer,
			                                 fucCallBack);
	} else
	{
		pLabel1->setPosition(Vec2(pButtonItemUp->getContentSize().width / 2,
			                      pButtonItemUp->getContentSize().height/ 2));
		pButtonItemUp->addChild(pLabel1);
		pLabel2->setPosition(Vec2(pButtonItemDown->getContentSize().width / 2,
			                      pButtonItemDown->getContentSize().height/ 2));
		pButtonItemDown->addChild(pLabel2);
		pButtonItemDown->setCascadeColorEnabled(true);
		pButtonItemDown->setColor(Color3B::GRAY);
		pButtonItem = MenuItemSprite::create(pButtonItemUp,
			                                 pButtonItemDown,
			                                 fucCallBack);
	}
	return pButtonItem;

}