#include "../headers/includes.h"

GJChallengeItem::GJChallengeItem()
{
}

bool GJChallengeItem::canEncode()
{
  return true;
}

void GJChallengeItem::encodeWithCoder(DS_Dictionary *_dict)
{
  _dict->setIntegerForKey("kCEK", CoderKey::kCoderKeyChallengeItem);
  _dict->setIntegerForKey("1", m_eChallengeType);
  _dict->setIntegerForKey("5", m_nTimeLeft);
  _dict->setBoolForKey("6", m_bCanClaim);
  _dict->setStringForKey("7", m_sQuestName);
  _dict->setIntegerForKey("2", m_nCountSeed - m_nCountRand);
  _dict->setIntegerForKey("3", m_nGoalSeed - m_nGoalRand);
  _dict->setIntegerForKey("4", m_nRewardSeed - m_nRewardRand);
  _dict->setIntegerForKey("8", m_nQuestPosition);
}

void GJChallengeItem::setCount(int _count)
{
  m_nCount = _count;
  m_nCountRand = rand();
  m_nCountSeed = m_nCountRand + m_nCount;
}

void GJChallengeItem::setGoal(int _goal)
{
  m_nGoal = _goal;
  m_nGoalRand = rand();
  m_nGoalSeed = m_nGoalRand + m_nGoal;
}

void GJChallengeItem::setReward(int _reward)
{
  m_nReward = _reward;
  m_nRewardRand = rand();
  m_nRewardSeed = m_nRewardRand + m_nReward;
}

bool GJChallengeItem::init(GJChallengeType _challengeType, int _goal, int _reward, int _timeLeft, std::string _questName)
{
  m_eChallengeType = _challengeType;
  m_nTimeLeft = _timeLeft;
  m_sQuestName = _questName;
  setGoal(_goal);
  setReward(_reward);
  return true;
}

GJChallengeItem *GJChallengeItem::create(GJChallengeType _challengeType, int _goal, int _reward, int _timeLeft, std::string _questName)
{
  auto pRet = new GJChallengeItem;

  if (pRet && pRet->init(_challengeType, _goal, _reward, _timeLeft, _questName))
  {
    pRet->autorelease();
    return pRet;
  }

  CC_SAFE_DELETE(pRet);
  return nullptr;
}

GJChallengeItem *GJChallengeItem::create()
{
  return create(GJChallengeType::kGJChallengeTypeUnknown, 0, 0, 0, "");
}

GJChallengeItem *GJChallengeItem::createFromString(std::string _string)
{
  cocos2d::CCArray *challengeArray = RobertFuncs::splitToCCArray(_string, ",");
  if (challengeArray->count() <= 4)
    return 0;

  int timeLeft = challengeArray->stringAtIndex(0)->intValue();
  GJChallengeType challengeType = static_cast<GJChallengeType>(challengeArray->stringAtIndex(1)->intValue());
  int goal = challengeArray->stringAtIndex(2)->intValue();
  int reward = challengeArray->stringAtIndex(3)->intValue();
  std::string name = challengeArray->stringAtIndex(4)->m_sString;

  return create(challengeType, goal, reward, timeLeft, name);
}

void GJChallengeItem::incrementCount(int _add)
{
  if (!m_bCanClaim)
  {
    int count = (m_nCountSeed - m_nCountRand) + _add;
    if (count >= m_nGoalSeed - m_nGoalRand)
    {
      count = m_nGoalSeed - m_nGoalRand;
      m_bCanClaim = true;
    }
    GJChallengeItem::setCount(count);
  }
}

void GJChallengeItem::dataLoaded(DS_Dictionary *_dict)
{
  m_eChallengeType = static_cast<GJChallengeType>(_dict->getIntegerForKey("1"));
  setCount(_dict->getIntegerForKey("2"));
  setGoal(_dict->getIntegerForKey("3"));
  setReward(_dict->getIntegerForKey("4"));
  m_nTimeLeft = _dict->getIntegerForKey("5");
  m_bCanClaim = _dict->getBoolForKey("6");
  m_sQuestName = _dict->getStringForKey("7");
  m_nQuestPosition = _dict->getIntegerForKey("8");
}

GJChallengeItem *GJChallengeItem::createWithCoder(DS_Dictionary *_dict)
{

  GJChallengeItem *challengeItem = GJChallengeItem::create();
  challengeItem->dataLoaded(_dict);
  return challengeItem;
}