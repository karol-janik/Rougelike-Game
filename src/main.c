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

<<<<<<< HEAD
    level = createLevel(1);
=======
    level = createLevel(3);
    
    
>>>>>>> 0650bb33b7d747a9ca265200fe5ddb34d0c015bc

    /* main game loop */
    while((ch =getch()) != 'q')
    {
<<<<<<< HEAD
        newPosition = handelInput(ch, level->user);
        checkPosition(newPosition, level->user, level->tiles);
        moveMonsters(level);
        move(level->user->position->y, level->user->position->x);
=======
        newPosition = handelInput(ch, user);
        checkPosition(newPosition, user, level->tiles);
        moveMonsters(level);
>>>>>>> 0650bb33b7d747a9ca265200fe5ddb34d0c015bc
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


