/******************************************************************************
* Weapon.cpp
* CS 281-0798, Fall 2020
*
* Weapon class definition
*******************************************************************************
*/
#include <string>

#include "Weapon.h"

// default Weapon characteristics
#define WEAPON_DEFAULT_STATUS   1

//***********************************************************
// Weapon(string wName)
//
// overload constructor
//
// wName is a call by value string parameter
// to allow passing string literals
//***********************************************************
Weapon::Weapon(std::string wName)
{
    m_id = static_cast<int>('w');   // 'w' means Weapon
    m_name = wName;
    m_usedStatus = WEAPON_DEFAULT_STATUS;
}

//***********************************************************
// Weapon()
//
// constructor
//***********************************************************
Weapon::Weapon() : Weapon("weapon of protection")
{ }

//***********************************************************
// setId()
//
// must implement this member function because
// it's declared as pure virtual in base class CarryIt
//
// identify Weapon class or unique Weapon
//
// NOTE: member variable m_id is initialized to (int) 'w'
// in constructor
//
// set m_id to passed value
//***********************************************************
bool Weapon::setId(int id)
{
    m_id = id;
    return true;
}

//***********************************************************
// setUsesRemaining()
//***********************************************************
bool Weapon::setUsedStatus(int status)
{
    m_usedStatus = status;
    return true;
}


//***********************************************************
// getUsedStatus()
//
// returns status of the weapon. 1 for unused, 0 for used
//***********************************************************
int Weapon::getUsedStatus() const { return m_usedStatus; }

