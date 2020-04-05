#ifndef ROUGE_H
#define ROUGE_H


#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

/*** struct definitions ***/

typedef struct  Level
{
    char  ** tiles;
    int level;
    int numberOfRooms;
    struct Room ** rooms; 
    struct Monster ** monsters;
    struct Player * user;
    int numberOfMonsters;
}Level;

typedef struct Position
{
    int x;
    int y;
    // TILE_TYPE taile;
}Position;

typedef struct Room
{
    Position position;
    int height;
    int width;
    
    struct Door **  doors;
    int numberOfDoors;
    //Monster ** monsters;
    //Item ** items;
}Room;

typedef struct Door
{
    Position position;
    int connected;
}Door;


typedef struct Player
{
    Position * position;
    int health;
    int attack;
    int gold;
    int maxHealth;
    int exp;
    //Room * room;
}Player;

typedef struct Monster
{
    char string[2];
    char symbol;                // represent the monster at map
    int health;
    int attack;
    int speed;
    int defence;
    int pathfinding;
    int alive;
    Position * position;
    
}Monster;

/*** Global variables ***/
int MAX_HEIGHT;
int MAX_WIDTH;

/* screen functions */
int screenSetUp();
int printGameHub(Level * level);

/* level/map functions */
Level * createLevel();
Room ** roomsSetUp();
char ** saveLevelPositions();
void connectDoors(Level * level);



/* player functions */
Player * playerSetUp();
Position * handelInput(int input, Player * user);
int checkPosition(Position * newPosition, Level * level);
int playerMove(Position * newPosition, Player * user, char ** level);
int placePlayer(Room ** rooms, Player * user);


/* room functions */
Room * createRoom(int grid, int numberOfDoors);
int drawRoom(Room * room);

/* monster functions */
int addMonsters(Level * level);
Monster * selectMonster(int level);
Monster * createMonster(char symbol, int health, int attack, int speed, int defence, int pathfinding);
int setStartingPosition(Monster * monster, Room * room);
int pathfindingSeek(Position * start, Position * destination);
int moveMonsters(Level * level);
int pathfindingRandom(Position * position);
Monster * getMonsterAt(Position * position, Monster ** monsters);
int killMonster(Monster * monster);

int combat(Player * player, Monster * monster, int order);

#endif