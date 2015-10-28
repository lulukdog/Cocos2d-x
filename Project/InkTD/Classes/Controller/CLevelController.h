#ifndef _LEVELCONTROLLER_H_
#define _LEVELCONTROLLER_H_

#include "cocos2d.h"
#include "Model/EditorData.h"
#include "Core/AppDef.h"
#include "Event/EventWrapper.h"

class CLevelController : public EventWrapper
{
public:
	CLevelController();
	~CLevelController();
	void initialize();
	std::vector<MAPBLOCKVO> loadCurLevelData(int nLevel);

public:
	int  getCurLevel();
	void setCurLevel(int nLevel);
	int  getCurMaxLevel();
	void setCurMaxLevel(int nLevel);
	int  getMaxPassLevel();
	void setMaxPassLevel(int nLevel);
	int  getShotLimitByLevel(int nLevel);
	int  getEnemyNumByLevel(int nLevel);

private:
	void registerEvents();
	void removeEvents();
	void onGameOver(cocos2d::EventCustom* pEvent);

private:

	EditorData*                             m_pEditorData;
	std::map<int, std::vector<MAPBLOCKVO> > m_oMapVos;

	int                                     m_nCurLevel;
	int                                     m_nCurMaxLevel;
	int                                     m_nMaxPassLevel;
	int                                     m_nShotLimit;
};

#endif 