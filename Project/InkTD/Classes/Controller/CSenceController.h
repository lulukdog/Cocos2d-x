#ifndef _SENCE_CONTROLLER_H_
#define _SENCE_CONTROLLER_H_

#include "cocos2d.h"
#include "Model/EditorData.h"
#include "Core/AppDef.h"
#include "Event/EventWrapper.h"

class CSenceController : public EventWrapper
{
public:
	CSenceController();
	~CSenceController();
	void initialize();
	
private:
	void registerEvents();
	void removeEvents();
	void onDealwithSenceReplace(cocos2d::EventCustom* pEvent);

};

#endif 