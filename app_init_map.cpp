/******************************************************************************
* app_init_map.cpp
* CS 281 - 0798, Fall 2020
*
* Room map initialization functions
* 
* The Room map is an array of Room pointers in each Room.
* Each Room knows which Room can be accessed in each direction.
* There is no overall map of the Rooms.
*******************************************************************************
*/
#include "app.h"

/******************************************************************************
* void initRoomMap()
*******************************************************************************
*/
void initRoomMap()
{
    // #TODO
    // In this example map, the Nexus is at the center of all other Rooms
    // Customize your Room map according to your game design
    g_pWaterfrontPark->setDirectionPtr(ROOM_NORTH, g_pTheCastle);
    g_pTheCastle->setDirectionPtr(ROOM_SOUTH, g_pWaterfrontPark);
    g_pTheCastle->setDirectionPtr(ROOM_WEST, g_pArsenal);
    g_pArsenal->setDirectionPtr(ROOM_SOUTH, g_pCemetary);
    g_pCemetary->setDirectionPtr(ROOM_WEST, g_pDocks);
}
