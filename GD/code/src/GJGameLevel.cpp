#include "../headers/includes.h"

GJGameLevel::GJGameLevel()
{
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
