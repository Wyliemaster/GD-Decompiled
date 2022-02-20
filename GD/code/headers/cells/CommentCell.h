#include "../includes.h"

class CommentCell : public TableViewCell, public LikeItemDelegate, public FLAlertLayerProtocol
{
	cocos2d::CCSprite* m_pLikesIcon;
	cocos2d::CCLabelBMFont* m_pLikesLabel;
	GJComment* m_pComment;
	bool m_bAccountComment;

	CommentCell(const char*, float, float);
	bool init();
	void draw();
	void onViewProfile(cocos2d::CCObject*);
	void onConfirmDelete(cocos2d::CCObject*);
	void onGoToLevel(cocos2d::CCObject*);
	void onLike(cocos2d::CCObject*);
	void loadFromComment(GJComment);
	void onUnhide(cocos2d::CCObject*);
	void updateBGColor(int);
	void updateLabelValues();
	void incrementDislikes();
	void incrementLikes();
	void likedItem(LikeItemType, int, bool);
	void onDelete();
	void FLAlert_Clicked(FLAlertLayer*, bool);
	void onUndelete(cocos2d::CCObject*);
};
