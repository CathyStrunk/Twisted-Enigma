/******************************************************************************
* app_init_rooms.cpp
* CS 281 - 0798, Fall 2020
*
* Room initialization functions
*   - set Room entry text, exit text, direction text
*   - install Treasures in Room Treasure vector or in Room mixed vector
*   - install Weapons in Room Weapon vector or in Room mixed vector
* #TODO
*   - install bogies in Room Bogie vector
*   - install magic words in Room MagicWord vector
*******************************************************************************
*/
#include "app.h"

/******************************************************************************
* Room* initWaterfrontPark()
*******************************************************************************
*/
Room* initWaterfrontPark()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(100);

    std::string str = "Waterfront Park";
    pRoom->setName(str);

    str = "You are in a small 18th century town. The world starts to shift\n"
        "and twist the longer you look\n";
    pRoom->setEntryText(str);

    str = "You are leaving the Waterfront Park";
    pRoom->setExitText(str);

    str = "Looking north the whole of the town lies before you.\n"
        "The Mundane world starts to shift the longer you stare.\n";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "To the south is the vast tidal marsh that surrounds the town.\n";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "Glancing east we can barely make out the shadowy figures\n"
        "of the large gothic homes bordering the tidal marsh.\n";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "An oak tree lined street runs west.\n"
        "Graceful homes with sweeping porches peek from\n"
        "beneath the Spanish moss covered trees.\n";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "A dark sky starts to roll in above you.\n"
        "The clouds clear as an inky blackness blankets the sky.\n";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "The cobble stones beneath your feet feel sturdy and real.\n";
    pRoom->setDirectionText(ROOM_DOWN, str);

    pRoom->setDirectionPtr(ROOM_NORTH, g_pTheCastle);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "Copper chalice with silver filigree";
    pTreasure->setName(str);
    pTreasure->setPoints(50);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize second Treasure instance
    
    Treasure* pTreasure2 = new Treasure();
    str = "Ruby encrusted box";
    pTreasure2->setName(str);
    pTreasure2->setPoints(100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure2);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon();
    str = "Pirate sword";
    pWeapon->setName(str);
    pWeapon->setPoints(100);

    // install Weapon pointer in Room's Weapon vector
    pRoom->addWeapon(pWeapon);

    return pRoom;
}

/******************************************************************************
* Room* initTheCastle()
*******************************************************************************
*/
Room* initTheCastle()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(150);

    std::string str = "The Castle";
    pRoom->setName(str);

    str = "You are in The Castle"; // adjust welcome text for all rooms
    pRoom->setEntryText(str);

    str = "You are leaving The Castle";
    pRoom->setExitText(str);

    str = "As you squint through the windows you barely make out\n"
        "a vast stretch of land still smoldering from the Boglamen wars.\n";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Peering out across the gardens you look south\n"
        "to the Waterfront Park. The black sky casting an eerie gloom\n"
        "over the town.\n";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "Glancing east we watch the flickering lights of the oil lamps\n"
        "shimmering their way through from the Mundane world.\n";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "To the west we see a set of stairs going down to a tunnel below.\n"
        "Where do you think it could lead?\n";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "The exposed rafters above haven't been dusted in years.\n";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "The marble tile is worn with age. Ivy grows across the floor\n"
        "mimicking the veins in the stone.\n";
    pRoom->setDirectionText(ROOM_DOWN, str);

    pRoom->setDirectionPtr(ROOM_SOUTH, g_pWaterfrontPark);
    pRoom->setDirectionPtr(ROOM_WEST, g_pArsenal);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "Gold pocket watch";
    pTreasure->setName(str);
    pTreasure->setPoints(50);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Bogie instance
    Bogie* pBogie = new Bogie();
    str = "Bedesci";
    pBogie->setName(str);
    pBogie->setPoints(100);

    // install Bogie pointer in Room's Bogie vector
    pRoom->addBogie(pBogie);

    return pRoom;
}

/******************************************************************************
* Room* initArsenal()
*******************************************************************************
*/
Room* initArsenal()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(100);

    std::string str = "Arsenal";
    pRoom->setName(str);

    str = "The smell of gunpowder stings your nose.";
    pRoom->setEntryText(str);

    str = "Exiting the arsenal";
    pRoom->setExitText(str);

    str = "Crates of weapons line the smooth stone wall before you.";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Through the small slit in the door you can just make out the shadowy\n"
        "figures of the cemetary headstones. A pale mist blankets the air.\n";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "TODO";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "TODO";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "TODO";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "TODO";
    pRoom->setDirectionText(ROOM_DOWN, str);

    pRoom->setDirectionPtr(ROOM_SOUTH, g_pCemetary);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "huge diamond in the rough";
    pTreasure->setName(str);
    pTreasure->setPoints(100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon();
    str = "Silver pan flute";
    pWeapon->setName(str);
    pWeapon->setPoints(100);

    // install Weapon pointer in Room's Weapon vector
    pRoom->addWeapon(pWeapon);

    // create and initialize Bogie instance
    Bogie* pBogie = new Bogie();
    str = "Grauster";
    pBogie->setName(str);
    pBogie->setPoints(150);

    // install Bogie pointer in Room's Bogie vector
    pRoom->addBogie(pBogie);

    return pRoom;
}

/******************************************************************************
* Room* initCemetary()
*******************************************************************************
*/
Room* initCemetary()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(100);

    std::string str = "Cemetary";
    pRoom->setName(str);

    str = "You find yourself in a pale mist shrouded cemetary.\n";
    pRoom->setEntryText(str);

    str = "You hastily make your exit.\n";
    pRoom->setExitText(str);

    str = "TODO";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "TODO";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "TODO";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "TODO";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "TODO";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "TODO";
    pRoom->setDirectionText(ROOM_DOWN, str);

    pRoom->setDirectionPtr(ROOM_SOUTH, g_pDocks);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "Carved jade dragon";
    pTreasure->setName(str);
    pTreasure->setPoints(100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon();
    str = "Silver dagger with emerald inlaid sheath";
    pWeapon->setName(str);
    pWeapon->setPoints(100);

    // install Weapon pointer in Room's Weapon vector
    pRoom->addWeapon(pWeapon);

    // create and initialize Bogie instance
    Bogie* pBogie = new Bogie();
    str = "Mistwraiths";
    pBogie->setName(str);
    pBogie->setPoints(200);

    // install Bogie pointer in Room's Bogie vector
    pRoom->addBogie(pBogie);

    return pRoom;
}

/******************************************************************************
* Room* initDocks()
*******************************************************************************
*/
Room* initDocks()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(100);

    std::string str = "Docks";
    pRoom->setName(str);

    str = "Cold hugs you from all sides as the water laps against the rotting\n"
        "support posts. You can hear the splintering of the wood as the docks\n"
        "sway with the movement of the water.\n";
    pRoom->setEntryText(str);

    str = "TODO";
    pRoom->setExitText(str);

    str = "TODO";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "TODO";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "TODO";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "TODO";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "TODO";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "TODO";
    pRoom->setDirectionText(ROOM_DOWN, str);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "Treasure chest brimming with gold";
    pTreasure->setName(str);
    pTreasure->setPoints(200);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Bogie instance
    Bogie* pBogie = new Bogie();
    str = "Dragon";
    pBogie->setName(str);
    pBogie->setPoints(300);

    // install Bogie pointer in Room's Bogie vector
    pRoom->addBogie(pBogie);

    return pRoom;
}

