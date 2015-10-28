
#ifndef _CLOCAL_MODEL_H_
#define _CLOCAL_MODEL_H_

#include "cocos2d.h"
class CLocalModel
{
public:
	CLocalModel();
	~CLocalModel();

public:
	void initialize();
	void setMaxPassLevel(int nValue);
	int  getMaxPassLevel();
private:
	void saveLevel();

private:
	 int  m_nPassMaxLevel;

};

#endif