#ifndef ROUGE_H
#define ROUGE_H


#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

typedef struct Level
{
    char ** tiles;
    int level;
    int numberOfRooms;
    struct Room ** rooms;
    struct Monster ** monsters;
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
    
    Position **  doors;
    //Monster ** monsters;
    //Item ** items;
}Room;


typedef struct Player
{
    Position position;
    int health;
    //Room * room;
}Player;


int screenSetUp();

/* level/map functions */
Room ** roomSetUp();
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

#endif