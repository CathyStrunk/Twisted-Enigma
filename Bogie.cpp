/******************************************************************************
* Bogie.cpp
* CS 281-0798, Fall 2020
*
* Container pure abstract class definition
*******************************************************************************
*/
#include <string>

#include "Bogie.h"
#include "CarryIt.h"

//***********************************************************
// Bogie(string bName)
//
// overload constructor
//
// bName is a call by value string parameter
// to allow passing string literals
//***********************************************************
Bogie::Bogie(std::string bName)
{
    m_id = static_cast<int>('b');   // 'b' means Bogie
    m_name = bName;
    m_lifeStatus = 1;
}

//***********************************************************
// Bogie()
//
// constructor
//***********************************************************
Bogie::Bogie() : Bogie("Boglamen appear!") { }

//***********************************************************
// setLifeStatus(int)
//
// sets the bogie's life status to 1 (alive) or 0 (dead)
//***********************************************************
bool Bogie::setLifeStatus(int status)
{
	m_lifeStatus = status;
    return true;
}

//***********************************************************
// getLifeStatus()
//
// returns the bogie's current life status
//***********************************************************
int Bogie::getLifeStatus()
{
	return m_lifeStatus;
}

//***********************************************************
// setId()
//
// must implement this member function because
// it's declared as pure virtual in the base class
//
// identify Bogie class or unique Bogie
//
// NOTE: member variable m_id is initialized to (int) 'b'
// in Bogie constructor
//
// set m_id to passed value
//***********************************************************
bool Bogie::setId(int id)
{
    m_id = id;
    return true;
}