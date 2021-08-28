#include "../headers/includes.h"

GJMapPack::GJMapPack() 
{
}

int GJMapPack::getPackID()
{
	return m_nPackID;
}

GJDifficulty GJMapPack::getPackDifficulty()
{
	return m_eDifficulty;
}

int GJMapPack::getPackStars()
{
	return m_nStars;
}

int GJMapPack::getPackCoins()
{
	return m_nCoins;
}

cocos2d::ccColor3B GJMapPack::getColor1()
{
	return m_tTextColour;
}

cocos2d::ccColor3B GJMapPack::getColor2()
{
	return m_tBarColour;
}

int GJMapPack::getM_ID()
{
	return m_nMId;
}

std::string GJMapPack::getPackLevels()
{
	return m_sLevels;
}

std::string GJMapPack::getPackName()
{
	return m_sPackName;
}

void GJMapPack::setPackID(int _packID)
{
	m_nPackID = _packID;
}

void GJMapPack::setPackDifficulty(GJDifficulty _diff)
{
	m_eDifficulty = _diff;
}

void GJMapPack::setPackStars(int _stars)
{
	m_nStars = _stars;
}

void GJMapPack::setPackCoins(int _coins)
{
	m_nCoins = _coins;
}

void GJMapPack::setColor1(cocos2d::ccColor3B _col)
{
	m_tTextColour = _col;
}

void GJMapPack::setColor2(cocos2d::ccColor3B _col)
{
	m_tBarColour = _col;	
}

void GJMapPack::setPackLevels(std::string _levels)
{
	m_sLevels = _levels;
}

void GJMapPack::setPackName(std::string _name)
{
	m_sPackName;
}

bool GJMapPack::init()
{
	setPackName("");
	m_nMId++;
	m_pLevels = NULL;
	m_nStars = 0;
	m_nCoins = 0;
	m_nPackID = 0;
	return true;
}

GJMapPack* GJMapPack::create()
{
	auto pRet = new GJMapPack;

	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}

GJMapPack* GJMapPack::create(cocos2d::CCDictionary *_dict)
{
	setPackID(_dict->valueForKey("1")->intValue());
	setPackName(_dict->valueForKey("2")->m_sString);
	setPackLevels(_dict->valueForKey("3")->m_sString);
	setPackStars(_dict->valueForKey("4")->intValue());
	setPackCoins(_dict->valueForKey("5")->intValue());
	setPackDifficulty(static_Cast<GJDifficulty>(_dict->valueForKey("6")->intValue()));
	setColor1(_dict->valueForKey("7")->m_sString);
	setColor2(_dict->valueForKey("8")->m_sString);
}

void GJMapPack::parsePackLevels(std::string _levels)
{
	if (m_pLevels)
		m_pLevels->autorelease();
	m_pLevels = RobTop::splitToCCArray(_levels, ",");
	m_pLevels->retain();
}

void GJMapPack::parsePackColors(std::string _text, std::string _bar)
{
	cocos2d::CCArray* text = RobTop::splitToCCArray(_text, ",");
	cocos2d::CCArray* bar = RobTop::splitToCCArray(_bar, ",");
	if (text->count() > 2)
	{
		m_tTextColour.r = static_cast<cocos2d::CCString*>(text->objectAtIndex(0))->intValue();
		m_tTextColour.g = static_cast<cocos2d::CCString*>(text->objectAtIndex(1))->intValue();
		m_tTextColour.b = static_cast<cocos2d::CCString*>(text->objectAtIndex(2))->intValue();
	}

	if (bar->count() > 2)
	{
		m_tBarColour.r = static_cast<cocos2d::CCString*>(text->objectAtIndex(0))->intValue();
		m_tBarColour.g = static_cast<cocos2d::CCString*>(text->objectAtIndex(1))->intValue();
		m_tBarColour.b = static_cast<cocos2d::CCString*>(text->objectAtIndex(2))->intValue();
	}
}

int GJMapPack::totalMaps()
{
	if (m_pLevels)
		return m_pLevels->count();
	return 0;
}

int GJMapPack::completedMaps()
{
	if (m_pLevels)
	{
		unsigned int idx = 0;
		int completedMap = 0;
		while (idx < m_pLevels->count())
		{
		bool levelCompleted = false;
			int level = static_cast<cocos2d::CCString*>(m_pLevels->objectAtIndex(idx))->intValue();
			if (m_bIsGauntlet)
				levelCompleted = GameStatsManager::sharedState()->hasCompletedGauntletLevel(level);
			else
				levelCompleted = GameStatsManager::sharedState()->hasCompletedOnlineLevel(level);

			if (levelCompleted)
				completedMap++;
			idx++;
		}
		return completedMap;
	}
	return 0;
}

bool GJMapPack::hasCompletedMapPack()
{
	int maps = totalMaps();
	if (maps)
		return completedMaps() >= maps;
	return false;
}