#include "CSoundController.h"
#include "Utils/Utils.h"
#include "Core/AppRes.h"

using namespace util;

void CSoundController::initialize()
{
   MusicUtil::initialize();
}

void CSoundController::playSndStart()
{
	MusicUtil::playEffectMusic(SOUND_START);
}

void CSoundController::playSndBackground()
{
	MusicUtil::playBackgroundMusic(SOUND_BG, true);
}

void CSoundController::stopSndBackground()
{
	MusicUtil::stopBackgroundMusic();
}

void CSoundController::playSndBoom()
{
	MusicUtil::playEffectMusic(SOUND_BOOM);
}

void CSoundController::playSndShootBox()
{
	MusicUtil::playEffectMusic(SOUND_BOX);
}
void CSoundController::playSndBullet()
{
	MusicUtil::playEffectMusic(SOUND_BULLET);
}

void CSoundController::playSndNoBullet()
{
	MusicUtil::playEffectMusic(SOUND_NO_BULLET);
}

void CSoundController::playSndDieByOther()
{
	MusicUtil::playEffectMusic(SOUND_OTHER_DIE);
}
void CSoundController::playSndPices()
{
	MusicUtil::playEffectMusic(SOUND_PICES);
}

void CSoundController::playSndShoot()
{
	MusicUtil::playEffectMusic(SOUND_SHOOT);
}
void CSoundController::playSndShootDown()
{
	MusicUtil::playEffectMusic(SOUND_SHOOT_DOWN);
}