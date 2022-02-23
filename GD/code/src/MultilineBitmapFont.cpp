#include "../headers/includes.h"

std::string MultilineBitmapFont::readColorInfo(std::string str)
{
	while (true)
	{
		std::string newstr = str;
		std::size_t colPos = newstr.find("<c");
		cocos2d::ccColor3B col;
		cocos2d::CCObject* textSection;

		if (colPos != std::string::npos)
		{
			std::string tag = newstr.at(colPos + 2);

			newstr.replace(colPos, 4, "");
			moveSpecialDescriptors(colPos, 4);

			std::size_t endTag = newstr.find("</c>");
			newstr.replace(endTag, 4, "");
			moveSpecialDescriptors(endTag, 4);

			switch (tag)
			{
			case 'b':
				col = { 0x4A, 0x52, 0xE1 };
				break;
			case 'g':
				col = { 0x40,0xE3,0x48 };
				break;
			case 'l':
				col = { 0x60, 0xAB, 0xEF };
				break;
			case 'j':
				col = { 0x32, 0xC8, 0xFF };
				break;
			case 'y':
				col = { 0xFF, 0xFF, 0x00 };
				break;
			case 'o':
				col = { 0xFF, 0xA5, 0x4B };
				break;
			case 'r':
				col = { 0xFF, 0x5A, 0x5A };
				break;
			case 'p':
				col = { 0xFF, 0x00 0xFF };
				break;
			default:
				col = { 0xFF, 0x00, 0x00 };
			}

			textSection = ColoredSection::create(col, colPos, endTag - 1);
			m_pColouredTextArray->addObject(textSection);;
			continue;
		}

		std::size_t iPos = newstr.find("<i>");
		if (iPos != std::string::npos)
		{
			newstr.replace(iPos, 3, "");
			moveSpecialDescriptors(iPos, 3);

			std::size_t iEnd = newstr.find("</i>");
			newstr.replace(iEnd, 4, "");
			moveSpecialDescriptors(iEnd, 4);

			textSection = InstantSection::create(iPos, iEnd - 1);
			m_pInstantTextArray->addObject(textSection);
			continue;
		}

		std::size_t dPos = newstr.find("<d");
		if (dPos == std::string::npos)
			break;

		int delay = atoi(newstr.substr(dPos + 2, 3));
		newstr.replace(dPos, 6, "");
		moveSpecialDescriptors(dPos, 6);

		textSection = DelaySection::create(dPos, delay / 100.0f);
		m_pDelayedTextArray->addObject(textSection);

	}
		return newstr;
}

void MultilineBitmapFont::moveSpecialDescriptors(int tStart, int tSize)
{

	for (int i = 0; i < m_pColouredTextArray->count(); ++i)
	{
		ColoredSection* section = m_pColouredTextArray->objectAtIndex(i);
		if (section->m_nStart <= tStart && section->m_nEnd <= tStart)
			continue;
		
		section->m_nStart -= tSize;
		section->m_nEnd -= tSize;
	}

	for (int i = 0; i < m_pInstantTextArray->count(); ++i)
	{
		InstantSection* section = m_pInstantTextArray->objectAtIndex(i);
		if (section->m_nStart <= tStart && section->m_nEnd <= tStart)
			continue;
		
		section->m_nStart -= tSize;
		section->m_nEnd -= tSize;
	}
}

void MultilineBitmapFont::setOpacity(unsigned __int8 opacity)
{
	for (int i = 0; i < m_pLetterArray->count(); ++i)
	{
		static_cast<cocos2d::CCSprite*>(m_pLetterArray->objectAtIndex(i))->setOpacity(opacity);
	}
	this->setOpacity(opacity);
}

MultilineBitmapFont* MultilineBitmapFont::create(const char* fontName, int* str, float scale, float width, cocos2d::CCPoint anchorPoint, bool tagsDisabled)
{
	auto pRet = new MultilineBitmapFont;

	if (pRet && pRet->initWithFont(fontName, str, scale, width, anchorPoint, tagsDisabled))
	{
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool MultilineBitmapFont::initWithFont(const char* fontName, int* str, float scale, float width, cocos2d::CCPoint anchorPoint, bool tagsDisabled)
{
	bool init = this->init(); // inititialising CCSprite Stuff
	if (init)
	{
		std::string modifiedStr = str;
		m_bTagsDisabled = tagsDisabled;

		cocos2d::CCDirector* director = cocos2d::CCDirector::sharedDirector();
		float scaledWidth = width * director->getContentScaleFactor();

		m_pColouredTextArray = cocos2d::CCArray::create();
		m_pColouredTextArray->retain();

		m_pInstantTextArray = cocos2d::CCArray::create();
		m_pInstantTextArray->retain();

		m_pDelayedTextArray = cocos2d::CCArray::create();
		m_pDelayedTextArray->retain();

		m_pLetterArray = cocos2d::CCArray::create();
		m_pLetterArray->retain();

		FontObject* font = BitmapFontCache::sharedFontCache()->fontWithConfigFile(fontName, scale);

		for (int i = 0; i < 300; i++)
			m_fFontWidth[i] = font->getFontWidth(i);

		if (!m_bTagsDisabled)
			modifiedStr = this->readColorInfo(str);



		float yPos = 0.0f;
		int strPos = 0;
		int loops = 0;
		while (modifiedStr)
		{
			modifiedStr = this->stringWithMaxWidth(modifiedStr, scaledWidth, scale);

			cocos2d::CCLabelBMFont* label = cocos2d::CCLabelBMFont::create(modifiedStr, fontName);
			label->setPosition({ 0.0f, yPos });
			label->setScale(scale);

			if (m_fContentSizeScaleMod < label->getContentSize().width * label->getScale())
				m_fContentSizeScaleMod = label->getContentSize().width * label->getScale();

			label->setAnchorPoint(anchorPoint);

			if (label->getAnchorPoint().x == 0.5f)
			{
				label->setAnchorPoint({ 0.0f, label->getAnchorPoint().y });
				cocos2d::CCPoint pos = label->getPosition();

				label->setPosition({ roundf(pos.x - (label->getContentSize().width / 2)), pos.y });
			}

			if (label->getAnchorPoint().y == 0.5f)
			{
				label->setAnchorPoint({ label->getAnchorPoint().x, 0.0f });
				cocos2d::CCPoint pos = label->getPosition();

				label->setPosition({ pos.x, roundf(pos.y - (label->getContentSize().height / 2)) });
			}

			
			std::size_t strSize = modifiedStr.size();
			int currentIdx = strPos + strSize; // names may change

			while (m_pColouredTextArray->count())
			{
				ColoredSection* section = m_pColouredTextArray->objectAtIndex(0);

				if (section->m_nStart < strPos || section->m_nStart > currentIdx)
					break;

				if (section->m_nEnd <= currentIdx)
					m_pColouredTextArray->removeObjectAtIndex(0, 1);
				else
					section->m_nStart = (section->m_nEnd = currentIdx) + 1;

				int pos = section->m_nStart - strPos;
				int limit = section->m_nEnd - strPos;

				if (pos == 1)
					pos = 0;

				while (pos <= limit)
				{
					cocos2d::CCSprite* child = label->getChildByTag(pos);

					if (child)
						child->setColor(section->m_cColour);
					++pos;
				}
			}

			while (m_pInstantTextArray->count())
			{
				ColoredSection* section = m_pInstantTextArray->objectAtIndex(0);

				if (section->m_nStart < strPos || section->m_nStart > currentIdx)
					break;

				if (section->m_nEnd <= currentIdx)
					m_pInstantTextArray->removeObjectAtIndex(0, 1);
				else
					section->m_nStart = (section->m_nEnd = currentIdx) + 1;

				int pos = section->m_nStart - strPos;
				int limit = section->m_nEnd - strPos;

				if (pos == 1)
					pos = 0;

				while (pos <= limit)
				{
					cocos2d::CCSprite* child = label->getChildByTag(pos);

					if (child)
						child->m_bVisible = true;
					++pos;
				}
			}

			while (m_pDelayedTextArray->count())
			{
				ColoredSection* section = m_pDelayedTextArray->objectAtIndex(0);

				if (section->m_nStart < strPos || section->m_nStart > currentIdx)
					break;

					m_pDelayedTextArray->removeObjectAtIndex(0, 1);

					int pos = section->m_nStart - strPos;
					if (pos == 1)
						pos = 0;

					if (!label->getChildByTag(pos))
					{
						cocos2d::CCSprite* child = label->getChildByTag(pos - 1);
						if (child)
							child->m_fDelay = section->m_fDelay;
					}
			}

			addChild(label);

			for (size_t i = 0; i < label->getChildrenCount(); i++)
				m_pLetterArray->addObject(label->getChildren()->objectAtIndex(i));
			
			modifiedStr = modifiedStr.erase(0, strLen);
			strPos += strLen;
			++loops;
		}

		m_pColouredTextArray->release();
		m_pInstantTextArray->release();

		m_obTextureSize.width = (loops - 1) * anchorPoint.y;
		m_obTextureSize.height = scaledWidth + 0.0f;

		float x = 0.0f;

		if (anchorPoint.x != 0.0f)
		{
			if (anchorPoint.x != 1.0f)
				x = m_obTextureSize.height / 2;
		}

		m_obPosition = { x, m_obTextureSize.width };
	}
	return init;
}