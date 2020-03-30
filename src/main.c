//
//  main.c
//  Rougelike game
//
//  Created by Karol Janik on 27/03/2020.
//
#include "rouge.h"

int main(int argc, const char * argv[]) {
    
    Player * user;
    int ch;
    Position  * newPosition;

    Level * level;
    
    screenSetUp();

    level = createLevel(3);
    
    

    /* main game loop */
    while((ch =getch()) != 'q')
    {
        newPosition = handelInput(ch, user);
        checkPosition(newPosition, user, level->tiles);
        moveMonsters(level);
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


