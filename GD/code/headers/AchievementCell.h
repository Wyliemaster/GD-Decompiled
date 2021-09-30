#include "includes.h"

class AchievementCell : public TableViewCell {
	AchievementCell(char const*, float, float);
	bool init();
	virtual void draw();
	void updateBGColor(int);
	const char* getTitleFromKey(char const*);
	void loadFromDict(cocos2d::CCDictionary*);
};