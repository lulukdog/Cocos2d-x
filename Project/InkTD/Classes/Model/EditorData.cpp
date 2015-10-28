
#include "Model/EditorData.h"
#include <iostream>
#include "Core/AppDef.h"
#include "Utils/Utils.h"
#include "Core/AppRes.h"

using namespace rapidxml;
using namespace std;
using namespace util;
USING_NS_CC;

EditorData::EditorData()
{
	m_nCurLevel = 0;
	m_vMapVos.clear();
}

EditorData::~EditorData()
{
}

void EditorData::saveToXml(std::vector<MAPBLOCKVO> &vData, int nLevel)
{
	const string sName = str_format(LEVEL_PATH, nLevel);
	std::string sFilePath = FileUtils::getInstance()->fullPathForFilename(sName);
	xml_document<> fDoc;   
	xml_node<>* pRoot = fDoc.allocate_node(rapidxml::node_pi, fDoc.allocate_string("xml version='1.0' encoding='utf-8'")); 
	fDoc.append_node(pRoot); 

	xml_node<>* pNode =  fDoc.allocate_node(node_element,"config","information");   
	xml_node<>* pLevel =  fDoc.allocate_node(node_element,"level", NULL);   
	fDoc.append_node(pNode); 
	pNode->append_node(pLevel); 
	pLevel->append_attribute(fDoc.allocate_attribute("level", int2str(nLevel)));
	for (int i = 0; i < vData.size(); i++)
	{
		xml_node<>* pTempNode = fDoc.allocate_node(node_element, "sprite", NULL);
		pTempNode->append_attribute(fDoc.allocate_attribute("type1", int2str(vData[i].nMapType)));
		pTempNode->append_attribute(fDoc.allocate_attribute("type2", int2str(vData[i].nBodyType)));
		pTempNode->append_attribute(fDoc.allocate_attribute("x",     int2str(vData[i].fPosX)));
		pTempNode->append_attribute(fDoc.allocate_attribute("y",     int2str(vData[i].fPosY)));
		pLevel->append_node(pTempNode);
	}
	std::string text;   
	rapidxml::print(std::back_inserter(text), fDoc, 0);   

	std::ofstream out(sFilePath.c_str(), std::ios::out); 
	out << fDoc;
	out.close();
}

bool EditorData::ParseXml(std::string strPath, rapidxml::xml_document<> &xmldoc)
{
	bool bResult = false;
	do
	{
		char *pFileData = nullptr;
		bResult = ParseXml(pFileData, strPath, xmldoc);
		CC_SAFE_DELETE_ARRAY(pFileData);
	}
	while (0);

	return bResult;
}


bool EditorData::ParseXml(char* pFileData, std::string strPath, xml_document<> &xmldoc)
{
	bool bResult = false;
	do
	{
		__String *cstrData = __String::createWithContentsOfFile(strPath.c_str());

		if (cstrData == nullptr || cstrData->length() == 0)
		{
			std::string strMsg = "找不到 " + strPath;
			CCAssert(!(cstrData->length() == 0),strMsg.c_str());
			break;
		}
		if (cstrData->length() <= 0)
		{
			break;
		}
		pFileData = new char[cstrData->length() + 1];
		memcpy(pFileData, cstrData->getCString(), cstrData->length());
		pFileData[cstrData->length()] = '\0';
		//cstrData->release();
		//捕获解析异常
		try
		{
			xmldoc.parse<0>(pFileData);
		}
		//捕获到异常后的操作
		catch(...)
		{
			xmldoc.clear();
			bResult = false;
			CC_SAFE_DELETE_ARRAY(pFileData);
			break;
		}

		bResult = true;
	}
	while (0);

	return bResult;
}

std::vector<MAPBLOCKVO> EditorData::parseXml(const std::string &sPath)
{
	//加载xml文件
	std::vector<MAPBLOCKVO> vMapVos;
	xml_document<>* xmldoc = new xml_document<>;
	if (!ParseXml(sPath, *xmldoc))
	{
		log("void EditorData::parseXml ++++ Failed!");
		return vMapVos;
	}
	xml_node<>* pRoot = xmldoc->first_node("config");
	vMapVos = initMapVos(pRoot);
	return vMapVos;
}

std::vector<MAPBLOCKVO> EditorData::initMapVos(rapidxml::xml_node<> *pRoot)
{
	std::vector<MAPBLOCKVO> vMapVos;
	xml_node<>* pNodeLevel = pRoot->first_node("level");
	log("EditorData::initMapVos + level + %s", pNodeLevel->name());
	xml_attribute<char>* pAttribute = pNodeLevel->first_attribute("level");
	log("EditorData::initMapVos + level + %s", pNodeLevel->value());
	m_nCurLevel = atoi(pAttribute->value());

	MAPBLOCKVO oAttribute;
	for (xml_node<>* pNode = pNodeLevel->first_node(); pNode != nullptr; pNode = pNode->next_sibling())
	{
		xml_attribute<char>* pAttribute = pNode->first_attribute("type1");
		oAttribute.nMapType = atoi(pAttribute->value());
		log("EditorData::initMapVos + nMapType + %d", oAttribute.nMapType);
		pAttribute = pAttribute->next_attribute();
		oAttribute.nBodyType = atoi(pAttribute->value());
		log("EditorData::initMapVos + nBodyType + %d", oAttribute.nBodyType);
		pAttribute = pAttribute->next_attribute();
		oAttribute.fPosX = atoi(pAttribute->value());
		log("EditorData::initMapVos + fPosX + %d", oAttribute.fPosX);
		pAttribute = pAttribute->next_attribute();
		oAttribute.fPosY = atoi(pAttribute->value());
		log("EditorData::initMapVos + fPosY + %d", oAttribute.fPosY);
		vMapVos.push_back(oAttribute);
	}
	return vMapVos;
}

