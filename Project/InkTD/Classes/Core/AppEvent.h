#ifndef _Core_AppEvent_h
#define _Core_AppEvent_h

#define EVT_ENTER_GAME			"EVT_ENTER_GAME"
//游戏开始事件
#define EVT_GAME_START			"EVT_GAME_START"
//游戏暂停事件
#define EVT_GAME_PAUSE			"EVT_GAME_PAUSE"
//游戏结束事件
#define EVT_GAME_OVER			"EVT_GAME_OVER"

#define EVT_SCENE_REPLACE       "EVT_SCENE_REPACE"

//通知刷新界面子弹的数目
//参数：value（num = 子弹数）
#define NTF_UPDATE_BULLET_NUM   "NTF_UPDATE_BULLET_NUM"
//参数：value（num = enemy num）
#define NTF_UPDATE_ENEMY_NUM    "NTF_UPDATE_ENEMY_NUM"

#define NTF_UPDATE_EDITOR_POS   "NTF_UPDATE_EDITOR_POS"   


#endif