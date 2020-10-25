/******************************************************************************
* Bogie.h
* CS 281-0798, Fall 2020
*
* Bogie class declaration
*******************************************************************************
*/
#ifndef BOGIE_H
#define BOGIE_H

#include <string>
#include <vector>

#include "CarryIt.h"

class Bogie : public CarryIt
{
private:
	int m_lifeStatus;
public:
	Bogie();
	Bogie(std::string bName);
	bool setLifeStatus(int);
	int getLifeStatus();

	// must implement pure virtual base class member function
	bool setId(int id);
};

#endif
