/*
 *author by mtt
 */
#ifndef __Core__AppDef__
#define __Core__AppDef__

#include "cocos2d.h"

//32个像素一米
#define PTM_RATIO        (32.0f)
//物理世界的重力
#define PTM_GRAVITY      (-10.0f)
//子弹的生命值
#define BULLET_LIVE      (10)
//发射子弹的时间间隔
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
	Enemy = 1,   //敌人
	Box_1,       //普通的箱子
	Box_2,       //特殊的箱子（会爆开）
	Block,       //
	Beam,        //平衡木
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

//刚体类型
enum BodyType
{
	dynamic_Body = 1,
	static_Body
};

//地图元素的vo
typedef struct 
{
	int     nMapType;
	int     nBodyType;
	int     fPosX;
	int     fPosY;
} MAPBLOCKVO;

#endif
