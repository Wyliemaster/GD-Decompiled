#include "includes"

class DialogObject : public cocos2d::CCObject {
    public:
        std::string m_sText;
        std::string m_sTitle;
        int m_nDialogType;
        cocos2d::ccColor3B m_pColour;
        float m_fTextWidth;
        bool m_bCanSkip;

        static DialogObject* create(std::string _title, std::string _text, int _type, float _width, bool _canSkip, cocos2d::ccColor3B _colour);
        bool init(std::string _title, std::string _text, int _type, float _width, bool _canSkip, cocos2d::ccColor3B _colour);
}