//
//  main.c
//  Rougelike game
//
//  Created by Karol Janik on 27/03/2020.
//
#include "rouge.h"

int main(int argc, const char * argv[]) {
    int ch;
    Position  * newPosition;

    Level * level;
    
    screenSetUp();

    level = createLevel(1);

    /* main game loop */
    while((ch =getch()) != 'q')
    {
        newPosition = handelInput(ch, level->user);
        checkPosition(newPosition, level);
        moveMonsters(level);
        move(level->user->position->y, level->user->position->x);
    }
    
    
    //getch();
    endwin();
    return 0;
}

int screenSetUp()
{
    initscr();
    noecho();
    refresh();
    
    srand(time(NULL));
    
    return 1;
}


