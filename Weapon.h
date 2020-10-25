/******************************************************************************
* Weapon.h
* CS 281-0798, Fall 2020
*
* Weapon class declaration
*******************************************************************************
*/
#ifndef WEAPON_H
#define WEAPON_H

#include <string>

// base class declaration
#include "CarryIt.h"

//----------------------------------------------------------
// Weapon class derived from base class for carried items
//----------------------------------------------------------
class Weapon : public CarryIt
{
private:
    int m_usedStatus;
    
public:
    Weapon();
    Weapon(std::string wName);
    // Weapon persists for app lifetime
    // so destructor not needed
    //~Weapon();

    bool setUsedStatus(int status);
    int getUsedStatus() const;
    
    // must implement pure virtual base class member function
    bool setId(int id);
};

#endif
