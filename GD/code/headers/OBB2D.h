#include "includes.h"

class OBB2D : public cocos2d::CCNode
{
public:
	cocos2d::CCPoint m_obVertexBottomLeft;
	cocos2d::CCPoint m_obVertexBottomRight;
	cocos2d::CCPoint m_obVertexTopRight;
	cocos2d::CCPoint m_obVertexTopLeft;
	cocos2d::CCPoint cocos2d__ccpoint10C;
	int gap114;
	int field_118;
	int field_11C;
	int field_120;
	int field_124;
	int field_128;
	cocos2d::CCPoint m_obHorizontalDifference;
	cocos2d::CCPoint m_obVerticalDifference;
	int field_13C;
	int field_140;
	int field_144;
	cocos2d::CCPoint* field_148;
	cocos2d::CCPoint m_obAxes;
	int field_154;
	int field_158;
	int field_15C;
	cocos2d::CCPoint m_obCenter;

	void calculateOBBWithCenter(cocos2d::CCPoint, float, float, float);
	void computeAxes();
	void orderCorners();
	bool init(cocos2d::CCPoint, float, float, float);
	cocos2d::CCRect getBoundingRect();
	bool overlaps1Way(OBB2D*);
	bool overlaps(OBB2D*);

};