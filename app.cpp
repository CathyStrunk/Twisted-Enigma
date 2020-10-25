/******************************************************************************
* app.cpp
* CS 281 - 0798, Fall 2020
*
* App main with entry point main()
*******************************************************************************
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <array>

// app common include file
#include "app.h"

// local function prototypes
void displayMessageQueue(std::vector<std::string>& msgQueue);
int mapMoveCommand(char cmd);
char menuOption();

// global variables available (extern) to all app code
Room* g_pWaterfrontPark = nullptr;
Room* g_pTheCastle      = nullptr;
Room* g_pArsenal        = nullptr;
Room* g_pCemetary       = nullptr;
Room* g_pDocks          = nullptr;

/******************************************************************************
* int main()
* entry point
*******************************************************************************
*/
int main()
{
    // accumulate messages for display each game loop iteration
    std::vector<std::string> messageQueue;

    // init game rooms with text, Treasure, and Weapons
    g_pWaterfrontPark = initWaterfrontPark();
    g_pTheCastle = initTheCastle();
    g_pArsenal = initArsenal();
    g_pCemetary = initCemetary();
    g_pDocks = initDocks();
    // init game rooms done

    // all global pointers now valid for use as Room map pointers
    initRoomMap();

    // #TODO put Player in starting Room of your choice
    // set utility pointer used throughout app main()
    Room* pRoom = g_pWaterfrontPark;

    // all-purpose string and message buffer
    std::string str;
    std::string playerName;

    // Game name goes here
    std::cout << "\nTwisted Engima\n";
    std::cout << "What's your name? ";
    std::cin >> playerName;

    // display app version
    messageQueue.push_back("Welcome " + playerName + "!\n");

    // create Player, award Room points,
    // and queue messages for display
    Player* pPlayer = new Player(playerName);
    visitRoom(pPlayer, pRoom, messageQueue);

    // display things Player sees in this Room
    getInventory(pRoom, messageQueue);

    // display queued messages and clear queue
    displayMessageQueue(messageQueue);

    // one-character command from user cin >> userCmd
    char userCmd;
    int direction = ROOM_DEAD_END;

    // temp Room pointer for Player "movement"
    Room* pNextRoom = nullptr;

// main app loop: display game menu, handle user command
    do
    {
        userCmd = menuOption();

// handle move commands first
        // translate char command to int direction constant
        direction = mapMoveCommand(userCmd);
        if (direction != ROOM_DEAD_END)
            pRoom = movePlayer(pPlayer, pRoom, direction, messageQueue);
        // L)ook command
        else if (userCmd == 'l')
            lookAllDirections(pRoom, messageQueue);
        // G)et treasure command
        else if (userCmd == 'g')
            grabTreasure(pPlayer, pRoom, messageQueue);
        // dR)op treasure command
        else if (userCmd == 'r')
            dropTreasure(pPlayer, pRoom, messageQueue);
        // T)ake weapon command
        else if (userCmd == 't')
            grabWeapon(pPlayer, pRoom, messageQueue);
        // deF)end weapon command
        else if (userCmd == 'f')
            messageQueue.push_back("#TODO Can't use weaponry yet!\n");
        // I)nfo command
        else if (userCmd == 'i')
            getAllInfo(pPlayer, pRoom, messageQueue);
// Q)uit command 
        else if (userCmd == 'q')
            messageQueue.push_back("Leaving so soon?");
// handle bad input
        else
            messageQueue.push_back("\aSorry, I don't know that command.");

// display after every iteration
        if (userCmd != 'i' && userCmd != 'q')
            getInventory(pRoom, messageQueue);

        displayMessageQueue(messageQueue);

    } while (userCmd != 'q');
// end main input loop

    // status display and farewell to Player
    getInfo(pPlayer, pRoom, messageQueue);
    messageQueue.push_back("\nGoodbye " + playerName + "!\n");
    displayMessageQueue(messageQueue);

    system("pause");

   return 0;
}

/******************************************************************************
* displayMessageQueue()
*
* display queued messages and clear queue
*
*******************************************************************************
*/
void displayMessageQueue(std::vector<std::string>& msgQ)
{
    std::cout << std::endl;

    // add a newline after each queued message 
    for (std::string msg : msgQ)
        std::cout << msg << "\n";

    // reset queue for next iteration
    msgQ.clear();
 }

/******************************************************************************
* mapMoveCommand()
*
* assumes parameter is lower case
* 
* if passed command char is a move command,
* return the direction constant
* 
* otherwise return ROOM_DEAD_END
* 
* #TODO add custom direction mappings here
*******************************************************************************
*/
int mapMoveCommand(char cmd)
{
    if (cmd == 'n')         // n)orth
        return ROOM_NORTH;   
    if (cmd == 's')         // s)outh
        return ROOM_SOUTH;
    if (cmd == 'e')         // e)ast
        return ROOM_EAST;
    if (cmd == 'w')         // w)est
        return ROOM_WEST;
    if (cmd == 'u')         // u)p
        return ROOM_UP;
    if (cmd == 'd')         // d)own
        return ROOM_DOWN;

    // this is not a move command!
    return ROOM_DEAD_END;
}

/******************************************************************************
* char menuOption()
*
* display menu and prompt
* 
* return lower case user command
*
*******************************************************************************
*/
char menuOption()
{
    char cmd;

    // display game menu
    std::cout << std::endl;
    std::cout << "N)orth, S)outh, E)ast, W)est, U)p, D)own,\n";
    std::cout << "L)ook, G)et treasure, dR)op treasure,\n";
    std::cout << "T)ake weapon, deF)end, I)nfo, Q)uit ? ";

    // get user command
    std::cin >> cmd;
    
    // lower case simplifies command handling
    cmd = tolower(cmd);

    return cmd;
}

