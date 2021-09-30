#include "includes.h"

class StatsCell : public TableViewCell {
	StatsCell(char const*, float, float);
	bool init();
	virtual void draw();
	void updateBGColor(int);
	const char* getTitleFromKey(char const*);
	void loadFromObject(StatsObject*);
};