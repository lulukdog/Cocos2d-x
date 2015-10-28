#ifndef _CSOUND_CONTROLLER_H_
#define _CSOUND_CONTROLLER_H_

#include "cocos2d.h"

class CSoundController
{
public:
    static void initialize();
	static void playSndStart();
	static void playSndBackground();
	static void stopSndBackground();
	static void playSndBoom();
	static void playSndShootBox();
	static void playSndBullet();
	static void playSndNoBullet();
	static void playSndDieByOther();
	static void playSndPices();
	static void playSndShoot();
	static void playSndShootDown();
};

#endif