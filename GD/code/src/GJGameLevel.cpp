#include "../headers/includes.h"

GJGameLevel::GJGameLevel()
{
}

int GJGameLevel::getLevelID()
{
	return m_nLevelIDSeed - m_nLevelIDRand;
}

int GJGameLevel::getUserID()
{
	return m_nUserIDSeed - m_nUserIDRand;
}

int GJGameLevel::getDailyID()
{
	return m_nTimelyIDSeed - m_nTimelyIDRand;
}

bool GJGameLevel::getCoin1()
{
	return m_nCoin1Seed - m_nCoin1Rand;
}

bool GJGameLevel::getCoin2()
{
	return m_nCoin2Seed - m_nCoin2Rand;
}

bool GJGameLevel::getCoin3()
{
	return m_nCoin3Seed - m_nCoin3Rand;
}


void GJGameLevel::setDailyID(int _dailyID)
{
	m_nTimelyID = _dailyID;
	m_nTimelyIDRand = rand();
	m_nTimelyIDSeed = m_nTimelyIDRand + m_nTimelyID;
}

void GJGameLevel::setCoin1(bool _coin)
{
	m_nCoin1 = _coin;
	m_nCoin1Rand = rand();
	m_nCoin1Seed = m_nCoin1Rand + m_nCoin1;
}

void GJGameLevel::setCoin2(bool _coin)
{
	m_nCoin2 = _coin;
	m_nCoin2Rand = rand();
	m_nCoin2Seed = m_nCoin2Rand + m_nCoin2;
}

void GJGameLevel::setCoin3(bool _coin)
{
	m_nCoin3 = _coin;
	m_nCoin3Rand = rand();
	m_nCoin3Seed = m_nCoin3Rand + m_nCoin3;
}


bool GJGameLevel::areCoinsVerified()
{
	int coins = 0;
	if (getCoin1() == 1)
		coins++;
	if (getCoin2() == 1)
		coins++;
	if (getCoin3() == 1)
		coins++;

	return m_nTotalCoins <= coins;
}

void GJGameLevel::unverifyCoins()
{
	setCoin1(false);
	setCoin2(false);
	setCoin3(false);
}

void GJGameLevel::levelWasAltered()
{
	m_bHasBeenAltered = true;
	setIsVerified(false);
	setExtraString("");
	if (m_bPublished)
	{
		setLevelVersion(getLevelVersion()++);
		setIsUploaded(false);
	}
}

void GJGameLevel::savePercentage(int _percentage, bool _practice, int _clicks, int _attemptTime, bool _vfDChk)
{
	bool percentageSynced = false;
	int oldPercent = getNormalPercent();
	if (_practice)
		oldPercent = getPracticePercent();

	if (oldPercent <= _percentage || _clicks > 0 && getClicks() <= 0)
	{
		if (_practice)
		{
			setPracticePercent(_percentage);
			return;
		}
		setNormalPercent(_percentage);
	}
	if (getNewNormalPercent2() < _percentage)
	{
		setNewNormalPercent2(_percentage);
		setClicks(_clicks);
		setAttemptTime(_attemptTime);
		int seedBase = 0;
		setVfDChk(_vfDChk)
		if (_vfDChk)
			seedBase = 1482;

		setLevelSeed(seedBase + (_attemptTime + 4085) * (_attemptTime + 4085) + (_clicks + 3991) * (_percentage + 8354) - 50028039);

		setLevelProgress(getLevelProgress(',' + (_percentage - oldPercent)))

		if (getNewNormalPercent() < _percentage)
			setNewNormalPercent(_percentage);

	}
}	
