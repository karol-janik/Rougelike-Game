#include "rouge.h"


int addMonsters(Level * level)
{
    int x;
    level->monsters = malloc(sizeof(Monster *) * 6);
    level->numberOfMonsters = 0;
    
    for (x = 0; x < level->numberOfRooms; x++)
    {
        if((rand() % 2) == 0)
        {
           level->monsters[level->numberOfMonsters] = selectMonster(level->level);
           setStartingPosition(level->monsters[level->numberOfMonsters], level->rooms[x]);
           level->numberOfMonsters++; 
        }
    }
    
    return 1;
}
Monster * selectMonster(int level)
{
    int monster;
    switch (level)
    {
    case 1:
    case 2:
    case 3:
        monster = (rand() % 2) + 1;
        break;
    case 4:
    case 5:
        monster = ( rand() % 2 ) + 2;
        break;
    case 6:
        monster = 3;
        break;
    
    default:
        break;
    }

    switch (monster)
    {
    case 1:  /* spider */
        return createMonster('X', 2, 1, 1, 1, 1);
    case 2: /* goblin */
        return createMonster('G', 5, 3, 1, 1, 2);
    case 3: /* troll */
        return createMonster('T', 15, 5, 1, 1, 1);
    default:
        break;
    }

    
}

Monster * createMonster(char symbol, int health, int attack, int speed, int defence, int pathfinding)
{
    Monster * newMonster;
    newMonster = malloc(sizeof(Monster));
    

    newMonster->symbol = symbol;
    newMonster->health = health;
    newMonster->attack = attack;
    newMonster->speed = speed;
    newMonster->defence = defence;
    newMonster->pathfinding = pathfinding;

    sprintf(newMonster->string, "%c", symbol);

    return newMonster;
}
int setStartingPosition(Monster * monster, Room * room)
{

    monster->position = malloc(sizeof(Position));

    monster->position->x = (random() % (room->width - 2)) + room->position.x;
    monster->position->y = (random() % (room->height - 2)) + room->position.y;

    

    mvprintw(monster->position->y, monster->position->x,monster->string);
     
     return 1;

}

int moveMonsters(Level * level)
{
    for(int x = 0; x  < level->numberOfMonsters; x++ )
    {
        if(level->monsters[x]->pathfinding == 1)
        {
          pathfindingRandom(level->monsters[x]->position);
        }
        else
        {
            mvprintw(level->monsters[x]->position->y, level->monsters[x]->position->x, ".");
            pathfindingSeek(level->monsters[x]->position, level->user->position);
            mvprintw(level->monsters[x]->position->y, level->monsters[x]->position->x, level->monsters[x]->string);
        }
        
    }
    return 1;
}

int pathfindingRandom(Position * position)
{
    int random;

    random = rand() % 5;

    switch (random)
    {
    /*step up */
    case 0:
        if (mwinch(position->y - 1, position->x) == '.')
        {
            position->y = position->y - 1;
        }
        break;


    /* step down */
    case 1:
        if (mwinch(position->y + 1, position->x) == '.')
        {
            position->y = position->y + 1;
        }
        break;


    /*step left  */ 
    case 2:
     if (mvinch(position->y, position->x - 1) == '.')
        {
            position->x = position->x - 1;
        }
        break;


    /* step right */
    case 3:
     if (mvinch(position->y, position->x + 1) == '.')
        {
            position->x = position->x + 1;
        }
        break;

    /* do nothing */
    case 4:
        break;
    
    default:
        break;
    }

    return 1;


}

int pathfindingSeek(Position * start, Position * destination)
{
    while(1)
    {
        /* step left */
        if(abs((start->x - 1) - destination->x) < abs(start->x - destination->x) && (mvinch(start->y, start->x - 1 )) == '.')
        {
            start->x = start->x - 1;
        /* step rigth */
        }else if(abs((start->x + 1) - destination->x) < abs(start->x - destination->x) && (mvinch(start->y, start->x + 1 )) == '.')
        {
            start->x = start->x + 1;
        /* step down */
        }else if(abs((start->y + 1) - destination->y) < abs(start->y - destination->y) && (mvinch(start->y + 1, start->x )) == '.')
        {
            start->y = start->y + 1;
        /*step up*/
        }else if(abs((start->y - 1) - destination->y) < abs(start->y - destination->y) && (mvinch(start->y - 1, start->x )) == '.')
        {
            start->y = start->y - 1;
        }else
        {
            /* do nothing */
        }

        return 1;
        
    }
}

