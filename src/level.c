#include "rouge.h"


/*
typedef struct Level
{
    char ** tiles;
    int numberOfRooms;
    struct Room ** rooms;
    struct Monster ** monsters;
    int numberOfMonsters;

}Level;
*/

Level * createLevel(int level)
{
    Level * newLevel;
    newLevel = malloc(sizeof(Level));

   
    newLevel->level = level;
    newLevel->numberOfRooms = 3;
    newLevel->rooms = roomsSetUp();
    newLevel->tiles = saveLevelPositions();

     newLevel->user = playerSetUp();

    

    addMonsters(newLevel);


    return newLevel;
}



Room **  roomsSetUp()
{
    Room ** rooms;
    rooms = malloc(sizeof(Room) * 6);

    rooms[0] = createRoom(13, 13, 6, 8);
    drawRoom(rooms[0]);
    
    
    rooms[1] = createRoom(40, 2, 6, 8);
    drawRoom(rooms[1]);
    
    rooms[2] = createRoom(40, 10, 6, 12);
    drawRoom(rooms[2]);
    
    connectDoors(rooms[0]->doors[3], rooms[2]->doors[1]);
    
    connectDoors(rooms[1]->doors[2], rooms[0]->doors[0]);
    
    
    return rooms;
}

char ** saveLevelPositions()
{
    int x; 
    int y;
    char ** positions;
    positions = malloc(sizeof(char *) * 25);
    
    for(y = 0;  y < 25; y++)
    {
        positions[y] = malloc(sizeof(char) * 100);
        for(x = 0; x < 100; x ++)
        {
            positions[y][x] = (char)mvinch(y, x);
        }
    }
    return positions;

}