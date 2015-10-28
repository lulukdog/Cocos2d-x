
#include "CLocalModel.h"
#include "Utils/Utils.h"

using namespace std;
using namespace util;

//保存通过的最大关卡
static const string  KEY_MAX_PASS_LEVEL = "KEY_MAX_PASS_LEVEL";
//static const string  KEY_CUR_LEVEL      = "KEY_CUR_LEVEL"; 

CLocalModel::CLocalModel()
{
}

CLocalModel::~CLocalModel()
{
}

void CLocalModel::initialize()
{
	m_nPassMaxLevel = ReaderWriter::LoadIntegerFromXML(KEY_MAX_PASS_LEVEL, 0);
}

void CLocalModel::saveLevel()
{
	ReaderWriter::SaveIntegerToXML(KEY_MAX_PASS_LEVEL, m_nPassMaxLevel);
}

int CLocalModel::getMaxPassLevel()
{
	return m_nPassMaxLevel;
}

void CLocalModel::setMaxPassLevel(int nValue)
{
	m_nPassMaxLevel = nValue;
	saveLevel();
}
