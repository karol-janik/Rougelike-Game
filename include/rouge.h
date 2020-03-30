#ifndef ROUGE_H
#define ROUGE_H


#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

typedef struct  Level
{
    char  ** tiles;
    int level;
    int numberOfRooms;
    struct Room ** rooms; 
    struct Monster ** monsters;
    int numberOfMonsters;
    struct Player * user;
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
    
    Position **  doors;
    //Monster ** monsters;
    //Item ** items;
}Room;


typedef struct Player
{
    Position * position;
    int health;
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
    Position * position;
    
}Monster;



int screenSetUp();

/* level/map functions */
Level * createLevel();
Room ** roomsSetUp();
char ** saveLevelPositions();


/* player functions */
Player * playerSetUp();
Position * handelInput(int input, Player * user);
int checkPosition(Position * newPosition, Player * unit,char ** level );
int playerMove(Position * newPosition, Player * user, char ** level);


/* room functions */
Room * createRoom(int x, int y, int height, int width);
int drawRoom(Room * room);
int connectDoors(Position * doorOne, Position * doorTwo);

/* monster functions */
int addMonsters(Level * level);
Monster * selectMonster(int level);
Monster * createMonster(char symbol, int health, int attack, int speed, int defence, int pathfinding);
int setStartingPosition(Monster * monster, Room * room);
int moveMonsters(Level * level);
int pathfindingSeek(Position * start, Position * destination);

#endif