#include "includes.h"

/* TODO: Alter names to reflect the Geode Binding's code */

bool GameManager::getGameVariable(char * key){
    return m_pGameVariableDict->valueForKey(key)->boolValue();
}

