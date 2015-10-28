// �������Ļ�ߴ��йص�һЩ�������������
// 1. ��Ļ���
// 2. ��Ļ�߶�
// 3. ˮƽ����ֵ
// 4. ��ֱ����ֵ
// 5. ��ť����ֵ(ˮƽ����ֵ����ֵ����ֵ��С��һ����
#pragma  once
#include "cocos2d.h"
namespace util
{
	class WindowUtil
	{
	public:
		static void initialize();

	public:
		static cocos2d::Size sizeDesign;
		static cocos2d::Size sizeDevice;
		static float scaleX;
		static float scaleY;
		static float scaleFit;
	};

#define DESIGN_S  util::WindowUtil::sizeDesign
#define DESIGN_W  util::WindowUtil::sizeDesign.width
#define DESIGN_H  util::WindowUtil::sizeDesign.height

#define DEVICE_S  util::WindowUtil::sizeDevice
#define DEVICE_W  util::WindowUtil::sizeDevice.width
#define DEVICE_H  util::WindowUtil::sizeDevice.height
#define SCALE_X   util::WindowUtil::scaleX
#define SCALE_Y   util::WindowUtil::scaleY
#define SCALE_FIT util::WindowUtil::scaleFit
 
}