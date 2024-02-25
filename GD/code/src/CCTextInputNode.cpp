#include "includes.h"

/* Robtop's List Of Bad Words */
cocos2d::CCArray *loadGJBlacklist()
{
    return cocos2d::CCArray::create(
        cocos2d::CCString::create("ahole"),
        cocos2d::CCString::create("ass-hole"),
        cocos2d::CCString::create("ass_hole"),
        cocos2d::CCString::create("ashole"),
        cocos2d::CCString::create("asholes"),
        cocos2d::CCString::create("assface"),
        cocos2d::CCString::create("asshole"),
        cocos2d::CCString::create("assholez"),
        cocos2d::CCString::create("asshole"),
        cocos2d::CCString::create("assholes"),
        cocos2d::CCString::create("assholz"),
        cocos2d::CCString::create("asswipe"),
        cocos2d::CCString::create("azzhole"),
        cocos2d::CCString::create("biatch"),
        cocos2d::CCString::create("bitch"),
        cocos2d::CCString::create("bitches"),
        cocos2d::CCString::create("blowjob"),
        cocos2d::CCString::create("boffing"),
        cocos2d::CCString::create("butthole"),
        cocos2d::CCString::create("buttwipe"),
        cocos2d::CCString::create("cock"),
        cocos2d::CCString::create("cocks"),
        cocos2d::CCString::create("cockhead"),
        cocos2d::CCString::create("cock-head"),
        cocos2d::CCString::create("cocks"),
        cocos2d::CCString::create("cocksucker"),
        cocos2d::CCString::create("cock-sucker"),
        cocos2d::CCString::create("cunt"),
        cocos2d::CCString::create("cunts"),
        cocos2d::CCString::create("cuntz"),
        cocos2d::CCString::create("dick"),
        cocos2d::CCString::create("dildo"),
        cocos2d::CCString::create("dildos"),
        cocos2d::CCString::create("enema"),
        cocos2d::CCString::create("fucker"),
        cocos2d::CCString::create("fagit"),
        cocos2d::CCString::create("faget"),
        cocos2d::CCString::create("faggit"),
        cocos2d::CCString::create("faggot"),
        cocos2d::CCString::create("fuckin"),
        cocos2d::CCString::create("fucking"),
        cocos2d::CCString::create("fucks"),
        cocos2d::CCString::create("fukah"),
        cocos2d::CCString::create("fuken"),
        cocos2d::CCString::create("fuker"),
        cocos2d::CCString::create("fukin"),
        cocos2d::CCString::create("fukkah"),
        cocos2d::CCString::create("fukken"),
        cocos2d::CCString::create("fukker"),
        cocos2d::CCString::create("fukkin"),
        cocos2d::CCString::create("hore"),
        cocos2d::CCString::create("jerk-off"),
        cocos2d::CCString::create("lesbian"),
        cocos2d::CCString::create("lipshits"),
        cocos2d::CCString::create("lipshitz"),
        cocos2d::CCString::create("masochist"),
        cocos2d::CCString::create("masokist"),
        cocos2d::CCString::create("massterbait"),
        cocos2d::CCString::create("masstrbait"),
        cocos2d::CCString::create("masstrbate"),
        cocos2d::CCString::create("masterbaiter"),
        cocos2d::CCString::create("masterbate"),
        cocos2d::CCString::create("masterbates"),
        cocos2d::CCString::create("mothafucker"),
        cocos2d::CCString::create("mothafuker"),
        cocos2d::CCString::create("mothafukkah"),
        cocos2d::CCString::create("mothafukker"),
        cocos2d::CCString::create("motherfucker"),
        cocos2d::CCString::create("motherfukah"),
        cocos2d::CCString::create("motherfuker"),
        cocos2d::CCString::create("motherfukkah"),
        cocos2d::CCString::create("motherfukker"),
        cocos2d::CCString::create("mother-fucker"),
        cocos2d::CCString::create("muthafucker"),
        cocos2d::CCString::create("muthafukah"),
        cocos2d::CCString::create("muthafuker"),
        cocos2d::CCString::create("muthafukkah"),
        cocos2d::CCString::create("muthafukker"),
        cocos2d::CCString::create("nastt"),
        cocos2d::CCString::create("nigger"),
        cocos2d::CCString::create("nigur"),
        cocos2d::CCString::create("niiger"),
        cocos2d::CCString::create("niigr"),
        cocos2d::CCString::create("orgasim"),
        cocos2d::CCString::create("orgasm"),
        cocos2d::CCString::create("orgasum"),
        cocos2d::CCString::create("oriface"),
        cocos2d::CCString::create("orifice"),
        cocos2d::CCString::create("orifiss"),
        cocos2d::CCString::create("peenus"),
        cocos2d::CCString::create("peinus"),
        cocos2d::CCString::create("penis"),
        cocos2d::CCString::create("penas"),
        cocos2d::CCString::create("penis"),
        cocos2d::CCString::create("phuker"),
        cocos2d::CCString::create("phukker"),
        cocos2d::CCString::create("poonani"),
        cocos2d::CCString::create("pusse"),
        cocos2d::CCString::create("pussee"),
        cocos2d::CCString::create("pussy"),
        cocos2d::CCString::create("puuke"),
        cocos2d::CCString::create("puuker"),
        cocos2d::CCString::create("queer"),
        cocos2d::CCString::create("qweers"),
        cocos2d::CCString::create("qweerz"),
        cocos2d::CCString::create("qweir"),
        cocos2d::CCString::create("recktum"),
        cocos2d::CCString::create("rectum"),
        cocos2d::CCString::create("retard"),
        cocos2d::CCString::create("sadist"),
        cocos2d::CCString::create("scank"),
        cocos2d::CCString::create("schlong"),
        cocos2d::CCString::create("screwing"),
        cocos2d::CCString::create("skankee"),
        cocos2d::CCString::create("skankey"),
        cocos2d::CCString::create("skanks"),
        cocos2d::CCString::create("skanky"),
        cocos2d::CCString::create("sluts"),
        cocos2d::CCString::create("slutty"),
        cocos2d::CCString::create("slutz"),
        cocos2d::CCString::create("vaijina"),
        cocos2d::CCString::create("vagina"),
        cocos2d::CCString::create("vagiina"),
        cocos2d::CCString::create("vagina"),
        cocos2d::CCString::create("vajina"),
        cocos2d::CCString::create("vullva"),
        cocos2d::CCString::create("vulva"),
        cocos2d::CCString::create("whore"),
        cocos2d::CCString::create("arschloch"),
        cocos2d::CCString::create("boiolas"),
        cocos2d::CCString::create("buceta"),
        cocos2d::CCString::create("chink"),
        cocos2d::CCString::create("clits"),
        cocos2d::CCString::create("cock"),
        cocos2d::CCString::create("cunt"),
        cocos2d::CCString::create("dildo"),
        cocos2d::CCString::create("dirsa"),
        cocos2d::CCString::create("ejakulate"),
        cocos2d::CCString::create("fcuk"),
        cocos2d::CCString::create("fuxor"),
        cocos2d::CCString::create("hoer"),
        cocos2d::CCString::create("hore"),
        cocos2d::CCString::create("jism"),
        cocos2d::CCString::create("kawk"),
        cocos2d::CCString::create("lesbian"),
        cocos2d::CCString::create("masturbate"),
        cocos2d::CCString::create("nigga"),
        cocos2d::CCString::create("nigger"),
        cocos2d::CCString::create("nutsack"),
        cocos2d::CCString::create("phuck"),
        cocos2d::CCString::create("pimpis"),
        cocos2d::CCString::create("pusse"),
        cocos2d::CCString::create("pussy"),
        cocos2d::CCString::create("scrotum"),
        cocos2d::CCString::create("shemale"),
        cocos2d::CCString::create("testical"),
        cocos2d::CCString::create("testicle"),
        cocos2d::CCString::create("jackoff"),
        cocos2d::CCString::create("whoar"),
        cocos2d::CCString::create("dyke"),
        cocos2d::CCString::create("fuck"),
        cocos2d::CCString::create("amcik"),
        cocos2d::CCString::create("andskota"),
        cocos2d::CCString::create("arse"),
        cocos2d::CCString::create("assrammer"),
        cocos2d::CCString::create("ayir"),
        cocos2d::CCString::create("bollock"),
        cocos2d::CCString::create("breasts"),
        cocos2d::CCString::create("butt-pirate"),
        cocos2d::CCString::create("cabron"),
        cocos2d::CCString::create("cazzo"),
        cocos2d::CCString::create("chraa"),
        cocos2d::CCString::create("cunt"),
        cocos2d::CCString::create("dick"),
        cocos2d::CCString::create("dike"),
        cocos2d::CCString::create("dupa"),
        cocos2d::CCString::create("dziwka"),
        cocos2d::CCString::create("ejackulate"),
        cocos2d::CCString::create("ekrem"),
        cocos2d::CCString::create("ekto"),
        cocos2d::CCString::create("enculer"),
        cocos2d::CCString::create("fanculo"),
        cocos2d::CCString::create("fanny"),
        cocos2d::CCString::create("feces"),
        cocos2d::CCString::create("felcher"),
        cocos2d::CCString::create("ficken"),
        cocos2d::CCString::create("flikker"),
        cocos2d::CCString::create("foreskin"),
        cocos2d::CCString::create("fotze"),
        cocos2d::CCString::create("futkretzn"),
        cocos2d::CCString::create("honkey"),
        cocos2d::CCString::create("huevon"),
        cocos2d::CCString::create("injun"),
        cocos2d::CCString::create("kanker"),
        cocos2d::CCString::create("klootzak"),
        cocos2d::CCString::create("kraut"),
        cocos2d::CCString::create("knulle"),
        cocos2d::CCString::create("kuksuger"),
        cocos2d::CCString::create("kurac"),
        cocos2d::CCString::create("kurwa"),
        cocos2d::CCString::create("kyrpa"),
        cocos2d::CCString::create("lesbo"),
        cocos2d::CCString::create("mamhoon"),
        cocos2d::CCString::create("masturbat"),
        cocos2d::CCString::create("mibun"),
        cocos2d::CCString::create("monkleigh"),
        cocos2d::CCString::create("mouliewop"),
        cocos2d::CCString::create("muie"),
        cocos2d::CCString::create("mulkku"),
        cocos2d::CCString::create("muschi"),
        cocos2d::CCString::create("nazis"),
        cocos2d::CCString::create("nepesaurio"),
        cocos2d::CCString::create("nigger"),
        cocos2d::CCString::create("orospu"),
        cocos2d::CCString::create("paska"),
        cocos2d::CCString::create("perse"),
        cocos2d::CCString::create("picka"),
        cocos2d::CCString::create("pierdol"),
        cocos2d::CCString::create("pillu"),
        cocos2d::CCString::create("pimmel"),
        cocos2d::CCString::create("pizda"),
        cocos2d::CCString::create("poontsee"),
        cocos2d::CCString::create("porn"),
        cocos2d::CCString::create("preteen"),
        cocos2d::CCString::create("puta"),
        cocos2d::CCString::create("qahbeh"),
        cocos2d::CCString::create("queef"),
        cocos2d::CCString::create("rapist"),
        cocos2d::CCString::create("raper"),
        cocos2d::CCString::create("rautenberg"),
        cocos2d::CCString::create("schaffer"),
        cocos2d::CCString::create("scheiss"),
        cocos2d::CCString::create("schlampe"),
        cocos2d::CCString::create("schmuck"),
        cocos2d::CCString::create("sharmuta"),
        cocos2d::CCString::create("sharmute"),
        cocos2d::CCString::create("shipal"),
        cocos2d::CCString::create("skribz"),
        cocos2d::CCString::create("skurwysyn"),
        cocos2d::CCString::create("sphencter"),
        cocos2d::CCString::create("spierdalaj"),
        cocos2d::CCString::create("splooge"),
        cocos2d::CCString::create("testicle"),
        cocos2d::CCString::create("wetback"),
        cocos2d::CCString::create("wichser"),
        cocos2d::CCString::create("zabourah"));
};

cocos2d::CCArray *load_unknown_list()
{
    return cocos2d::CCArray::create(
        cocos2d::CCString::create("13"),
        cocos2d::CCString::create("b"),
        cocos2d::CCString::create("i3"),
        cocos2d::CCString::create("b"),
        cocos2d::CCString::create("l3"),
        cocos2d::CCString::create("b"),
        cocos2d::CCString::create("0"),
        cocos2d::CCString::create("o"),
        cocos2d::CCString::create("1"),
        cocos2d::CCString::create("i"),
        cocos2d::CCString::create("2"),
        cocos2d::CCString::create("r"),
        cocos2d::CCString::create("3"),
        cocos2d::CCString::create("e"),
        cocos2d::CCString::create("4"),
        cocos2d::CCString::create("a"),
        cocos2d::CCString::create("5"),
        cocos2d::CCString::create("s"),
        cocos2d::CCString::create("7"),
        cocos2d::CCString::create("t"),
        cocos2d::CCString::create("8"),
        cocos2d::CCString::create("b"),
        cocos2d::CCString::create("9"),
        cocos2d::CCString::create("g"));
};

void CCTextInputNode::addTextArea(TextArea *tArea)
{
    if (m_textArea == nullptr)
    {
        m_textArea = tArea;
        addchild(tArea);
        auto pos = m_textArea->setPosition(cocos2d::CCPoint::CCPoint(pos, pos >> 0x20));
        m_textField->setVisible(false);
        updateLabel(m_textField->getString());
        updateDefaultFontValues(this->m_textArea->m_text);
    }
}

void CCTextInputNode::forceOffset()
{
    m_bForceOffset = true;
}

std::string CCTextInputNode::getString()
{
    return m_text->m_textArea->m_textStr;
}

bool CCTextInputNode::keyboardWillHide(CCIMEKeyboardNotificationInfo *keyboardNotificationInfo)
{
    if (m_forceOffset == false)
    {
        if ((m_textField != nullptr) && (m_unknown2 != false))
        {
            m_unknown2 = false;
            if (m_delegate != nullptr)
            {
                return m_delegate->textInputOpened(this);
            }
        }
    }
    else if ((m_selected != false) && (m_textField != nullptr))
    {
        if (m_delegate != nullptr)
        {
            return m_delegate->textInputOpened(this);
            // Unknown Call
            // (**(code **)((int)*pTVar1 + 0x10))(pTVar1,this);
        }
        m_selected = false;
        return false;
    }
    return false;
}


bool CCTextInputNodeCallback(CCTextInputNode *textInputNode){
    return textInputNode->keyboardWillShow((CCIMEKeyboardNotificationInfo *)(unaff_r7 << 1));
}


/* TODO */
// bool CCTextInputNode::keyboardWillShow(CCIMEKeyboardNotificationInfo *keyboard)

// {
//   bool bVar1;
//   CCTextFieldTTF *textField;
//   CCPoint *other;
//   CCRect *keyaboardEnd;
//   float fVar2;
//   int extraout_r1;
//   int *callback;
//   CCPoint CStack_3c;
//   CCRect CStack_34;
//   int local_24;
  
//   local_24 = *callback;
//   textField = (CCTextFieldTTF *)this;
//   if (((this->m_forceOffset == false) &&
//       (textField = this->m_textField, textField != (CCTextFieldTTF *)0x0)) &&
//      (this->m_selected != false)) {
//     keyaboardEnd = &keyboard->end;
//     other = (CCPoint *)(*(code *)textField->field0_0x0[0x24])();
//     cocos2d::CCPoint::CCPoint(&CStack_3c,other);
//     FUN_002f97c4((CCRect *)&CStack_34,(int *)this,&CStack_3c.x);
//     CStack_34.y = CStack_34.y - 4.0;
//     bVar1 = cocos2d::CCRect::intersectsRect((CCRect *)&CStack_34,(CCRect *)keyaboardEnd);
//     textField = (CCTextFieldTTF *)(uint)bVar1;
//     if (textField != (CCTextFieldTTF *)0x0) {
//       this->m_unknown2 = true;
//       cocos2d::CCRect::getMaxY((CCRect *)keyaboardEnd);
//       fVar2 = (float)cocos2d::CCRect::getMinY(&CStack_34,extraout_r1);
//       textField = (CCTextFieldTTF *)this->m_delegate;
//       if (textField != (CCTextFieldTTF *)0x0) {
//         textField = (CCTextFieldTTF *)
//                     (*(code *)textField->field0_0x0[3])(textField,this,(float)keyaboardEnd - fVar2 );
//       }
//     }
//   }
//   if (local_24 != *callback) {
//                     /* WARNING: Subroutine does not return */
//     __stack_chk_fail();
//   }
//   return SUB41(textField,0);
// }



void CCTextInputNode::setLabelNormalColor(cocos2d::_ccColor3B color)
{
    m_cColour = color;
}

void CCTextInputNode::setString(std::string str)
{
    m_textField->setString(str);
    updateLabel(str);
    if (m_delegate != nullptr)
        m_delegate->textChanged(this);
}


/* I like this function :) */

bool CCTextInputNode::onTextFieldDetachWithIME(cocos2d::CCTextFieldTTF *tField)
{
    if (m_cursor != nullptr)
    {
        m_cursor->setVisible(false);
    }
    if (m_unknown3 != false)
    {
        std::string pretextString = tField->getString();
        std::string textString = "";
        std::string passedString = "";

        /* The code is a little more complex than this but I think this gets the point across... */
        for (size_t x = 0; x < pretextString.size(); x++)
        {
            textString[x] = static_cast<char>(tolower(pretextString[x]));
        }

        auto unknownList = load_unknown_list();
        auto gjblacklist = LoadGJBlacklist();

        size_t pos = 0;
        std::string idx;
        /* Text Replacement (To prevent Swearword bypassing )*/
        for (unsigned int i = 0; unknownList->count() <= 0; i += 2)
        {
            idx = (reinterpret_cast<cocos2d::CCString *>(unknownList->objectAtIndex(unknownList, i)))->getCString();
            pos = textString.find(idx);
            if (pos != std::string::npos)
            {
                textString.replace(pos, idx->size(), ((reinterpret_cast<cocos2d::CCString *>(unknownList->objectAtIndex(unknownList, i + 1)))->getCString()));
            }
        }

        bool SaidCurseWord = false;
        for (unsigned int j = 0; j < gjblacklist->count(); j++)
        {
            idx = (reinterpret_cast<cocos2d::CCString *>(gjblacklist->objectAtIndex(j)))->getCString(pCVar9);
            pos = textString.find(idx);
            if (pos != std::string::npos)
            {
                textString.replace(pos, idx->size(), " ");
                SaidCurseWord = true;
            }
        }
        if (!SaidCurseWord)
        {
            passedString = textString;
        }

        if (passedString == textString)
        {
            setString(passedString);
        }
    }

    updateLabel(getTextString());

    m_selected = false;
    PlatformToolbox::setKeyboardState(0);

    if (m_delegate != nullptr)
    {
        m_delegate->enterPressed(this);
    }
    if ((m_forceOffset != false) && (m_delegate != nullptr))
    {
        return m_delegate->textInputClosed(this);
    }
    return false;
}





void CCTextInputNode::updateCursorPosition(CCPoint point, CCRect rect){
    if (m_textField->getString() == ""){

        if (m_placeholderLabel == nullptr){
            unsigned int count = m_textArea->m_labels->count();
            if (count == 0){
                return ;
            }
            else if (count == 1){
                m_placeholderLabel = reinterpret_cast<cocos2d::CCLabelBMFont*>m_textArea->m_labels->objectAtIndex(0);
            }
            else {
            
            /* We need to find our missing CCLabelBMFont... */
            /* TODO: Finish Function Tomorrow...*/

            }
        }
    }
}



void CCTextInputNode::updateDefaultFontValues(std::string fntVal)
{
    bool sameAs = fntVal == "chatFont.fnt";

    if (!= 0)
    {
        m_fontValue2 = 20.0;
        m_fontValue1 = 1.5;
    }
    else
    {
        m_fontValue2 = 5.0;
        m_fontValue1 = -0.5;
    }
    m_isCharFont = !sameAs;
}

