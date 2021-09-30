#include "includes.h"

class CommentCell : public TableViewCell, public LikeItemDelegate, public FLAlertLayerProtocol
{
	cocos2d::CCSprite* m_pLikesIcon;
	cocos2d::CCLabelBMFont* m_pLikesLabel;
	GJComment* m_pComment;
	bool m_bAccountComment;
};
