#include <cocos2d.h>
#include "includes.h"

class RobertFuncs
{
public:
    static cocos2d::CCArray *split(std::string _string, char *_splitter);
};

namespace Globals
{
    int ShardTypes[5] = {1, 2, 3, 4, 5};
}