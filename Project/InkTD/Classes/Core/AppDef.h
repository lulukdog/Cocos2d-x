/*
 *author by mtt
 */
#ifndef __Core__AppDef__
#define __Core__AppDef__

#include "cocos2d.h"

//32������һ��
#define PTM_RATIO        (32.0f)
//�������������
#define PTM_GRAVITY      (-10.0f)
//�ӵ�������ֵ
#define BULLET_LIVE      (10)
//�����ӵ���ʱ����
#define BULLET_SHOT_TIME (100)
 
#define WORLD_UPDATE_VELOCITY (10)

#define WORLD_UPDATE_POSITION (1)

#define REPLACE_SCENE_TIME (0.5f)



enum SceneType
{
	TYPE_HOME_TO_LEVEL = 3,
	TYPE_LEVEL_TO_HOME,
	TYPE_LEVEL_TO_GAME,
	TYPE_GAME_TO_LEVEL,
	TYPE_GAME_REPLAY,
	TYPE_GAME_TO_NEXT_LEVEL
};

enum MapType
{
	Enemy = 1,   //����
	Box_1,       //��ͨ������
	Box_2,       //��������ӣ��ᱬ����
	Block,       //
	Beam,        //ƽ��ľ
	Barrel_2,    //boom
	Block_2,     //right
	Block_3,     //left
	Barrel,      //ball
	Bullet,      //bullet
	Myself,
	hand,
	leg,
	head,
	torso
};

enum GAMEOVER
{
	NOBULLET     = 1,
	MAINCHARDIED = 2,
	SUCCESS      = 3
};

//��������
enum BodyType
{
	dynamic_Body = 1,
	static_Body
};

//��ͼԪ�ص�vo
typedef struct 
{
	int     nMapType;
	int     nBodyType;
	int     fPosX;
	int     fPosY;
} MAPBLOCKVO;

#endif
