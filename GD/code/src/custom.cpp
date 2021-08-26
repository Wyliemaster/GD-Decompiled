#include "../headers/includes.h"
#include <string>  // std::string
#include <sstream> // std::stringstream

//todo:
// 0x504DDC - android

cocos2d::CCArray *RobTop::splitToCCArray(std::string _string, char *_splitter)
{
   return reinterpret_cast<cocos2d::CCArray *(*)(std::string, char *)>(reinterpret_cast<uintptr_t>(GetModuleHandle(0)) + 0x25980)(_string, _splitter);
}
