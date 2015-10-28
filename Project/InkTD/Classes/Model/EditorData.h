
#pragma  once
#include "cocos2d.h"
#include "Core/AppDef.h"
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_iterators.hpp"
#include "rapidxml/rapidxml_print.hpp"

class EditorData : public cocos2d::Ref
{
public:
	EditorData();
	~EditorData();
public:

	void saveToXml(std::vector<MAPBLOCKVO> &vData, int nLevel);
	std::vector<MAPBLOCKVO> parseXml(const std::string &sPath);
	bool ParseXml(std::string strPath, rapidxml::xml_document<> &xmldoc);
	bool ParseXml(char* pFileData, std::string strPath, rapidxml::xml_document<> &xmldoc);

private:
	std::vector<MAPBLOCKVO> initMapVos(rapidxml::xml_node<> *pRoot);
	int  m_nCurLevel;
	std::vector<MAPBLOCKVO> m_vMapVos;
};
