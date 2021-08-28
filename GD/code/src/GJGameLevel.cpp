#include "../headers/includes.h"

GJGameLevel::GJGameLevel()
{
}

void GJGameLevel::savePercentage(int _percentage, bool _practice, int _clicks, int _attemptTime, bool _vfDChk)
{
	bool percentageSynced = false;
	int oldPercent = getNormalPercent();
	if (_practice)
		oldPercent = m_nPractice;

	_clicks > 0 ? percentageSynced = oldPercent == _percentage : percentageSynced = false;

	if (oldPercent < _percentage || percentageSynced && getClicks() <= 0)
	{
		if (_practice)
		{
			m_nPractice = _percentage;
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
		if (m_bVfDChk)
			seedBase = 1482;

		m_nLevelSeed = seedBase + (_attemptTime + 4085) * (_attemptTime + 4085) + (_clicks + 3991) * (_percentage + 8354) - 50028039;

		m_sLevelProgress = m_sLevelProgress + ',' + (_percentage - oldPercent)

		if (getNewNormalPercent() < _percentage)
			setNewNormalPercent(_percentage);
	}
}	
