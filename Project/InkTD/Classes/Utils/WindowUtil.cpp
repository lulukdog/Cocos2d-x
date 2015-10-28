#include "WindowUtil.h"
#include "cocos2d.h"
USING_NS_CC;

namespace util
{

	Size  WindowUtil::sizeDesign(960, 640);
	Size  WindowUtil::sizeDevice(0, 0);
	float WindowUtil::scaleX = 1.0f;
	float WindowUtil::scaleY = 1.0f;
	float WindowUtil::scaleFit = 1.0f;

	void WindowUtil::initialize()
	{
		sizeDesign = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
		sizeDevice = Director::getInstance()->getWinSizeInPixels();
 		scaleX = sizeDevice.width / 960;
 		scaleY = sizeDevice.height / 640;
 		scaleFit = MIN(scaleX, scaleY);
	}
}
 