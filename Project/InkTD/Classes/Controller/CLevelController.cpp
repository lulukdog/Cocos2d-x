#include "CLevelController.h"
#include "AppDelegate.h"
#include "Core/AppRes.h"
#include "Utils/Utils.h"
#include "Core/AppDef.h"
#include "Core/AppEvent.h"

using namespace std;
using namespace util;
USING_NS_CC;

CLevelController::CLevelController()
{
	m_nMaxPassLevel = 0;
	m_nCurLevel = 0;
	m_oMapVos.clear();
}

CLevelController::~CLevelController()
{
	removeEvents();
}

void CLevelController::registerEvents()
{
	ADD_OBSERVER(CLevelController::onGameOver, EVT_GAME_OVER);
}


void CLevelController::removeEvents()
{
	REMOVE_OBSERVER(EVT_GAME_OVER);
}

void CLevelController::initialize()
{
	m_pEditorData = new EditorData();
	m_nMaxPassLevel = theApp->m_pLocalModel->getMaxPassLevel();
	m_nCurMaxLevel = m_nMaxPassLevel + 1;
	m_nCurLevel = m_nMaxPassLevel + 1;
	registerEvents();
}

vector<MAPBLOCKVO> CLevelController::loadCurLevelData(int nLevel)
{
	vector<MAPBLOCKVO> vVos;
	auto iter = m_oMapVos.find(nLevel);
	if (iter != m_oMapVos.end())
	{
		return  iter->second;
	}
	const string sPathLevel = str_format(LEVEL_PATH, nLevel);
	vVos = m_pEditorData->parseXml(sPathLevel);
	m_oMapVos.insert(pair<int, vector<MAPBLOCKVO> >(nLevel, vVos));
	return vVos;
}

int CLevelController::getMaxPassLevel()
{
	return m_nMaxPassLevel;
}

void CLevelController::setMaxPassLevel(int nValue)
{
	m_nMaxPassLevel = nValue;
	theApp->m_pLocalModel->setMaxPassLevel(m_nMaxPassLevel);
}

void CLevelController::setCurLevel(int nValue)
{
	m_nCurLevel = nValue;
}

int CLevelController::getCurLevel()
{
	return m_nCurLevel;
}

int CLevelController::getShotLimitByLevel(int nValue)
{
	m_nShotLimit = 100000;
	return m_nShotLimit;
}

void CLevelController::setCurMaxLevel(int nValue)
{
	m_nCurMaxLevel = nValue;
}

int CLevelController::getCurMaxLevel()
{
	return m_nCurMaxLevel;
}

int CLevelController::getEnemyNumByLevel(int nValue)
{
	vector<MAPBLOCKVO> vVos = loadCurLevelData(nValue);
	int nNum = 0;
	for (vector<MAPBLOCKVO>::iterator pItor = vVos.begin(); pItor != vVos.end(); pItor++)
	{
		if (pItor->nMapType == MapType::Enemy)
		{
			nNum++;
		}
	}
	return nNum;
}

void CLevelController::onGameOver(cocos2d::EventCustom* pEvent)
{
	Value *pData = static_cast<Value*>(pEvent->getUserData());
	int nType = pData->asInt();
	switch (nType)
	{
	case GAMEOVER::NOBULLET:
		break;
	case GAMEOVER::MAINCHARDIED:
		break;
	case GAMEOVER::SUCCESS:
		if (m_nCurLevel > m_nMaxPassLevel)
		{
			setMaxPassLevel(m_nCurLevel);
			setCurMaxLevel(m_nCurLevel + 1);
		}
		m_nCurLevel = m_nCurLevel + 1;
		break;
	default:
		break;
	}
}
