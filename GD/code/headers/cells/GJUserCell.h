#include "includes.h"

class  GJUserCell : public TableViewCell, public FLAlertLayerProtocol, public UploadPopupDelegate, public UploadActionDelegate
{
	GJUserScore* m_pUserScore;
	UploadActionPopup* m_pUploadPopup;
};
