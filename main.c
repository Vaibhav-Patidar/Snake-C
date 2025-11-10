#include <stdio.h>
#include <ncurses.h>
//#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "start.h"
#include "gameover.h"



void printing_x_right(int y,int x){
    clear();
    int size = 4;
    int gain = 0;
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    box(stdscr, '|', '-');
    wattron(stdscr, COLOR_PAIR(1));
    char snake[50] = {'o','#','#','#'};
    for (int i = 0; i < size; i++){
    mvwprintw(stdscr, y, x - i, "%c", snake[i]);
    }
    wattroff(stdscr, COLOR_PAIR(1));
    refresh();
}

void printing_y_up(int y,int x){
    clear();
    int size = 4;
    int gain = 0;
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    box(stdscr, '|', '-');
    wattron(stdscr, COLOR_PAIR(1));
    char snake[50] = {'o','#','#','#'};
    for (int i = 0; i < size+gain; i++)
    {
        mvwprintw(stdscr,y+i,x,"%c", snake[i]);
    }
    wattroff(stdscr, COLOR_PAIR(1));
    refresh();
}

void printing_x_left(int y,int x){
    clear();
    int size = 4;
    int gain = 0;
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    box(stdscr, '|', '-');
    wattron(stdscr, COLOR_PAIR(1));
    char snake[50] = {'o','#','#','#'};
    for (int i = 0; i <size+gain; i++)
    {
        mvwprintw(stdscr,y,x+i,"%c", snake[i]);
    }
    wattroff(stdscr, COLOR_PAIR(1));
    refresh();
}



void printing_y_down(int y,int x){
    clear();
    int size = 4;
    int gain = 0;
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    box(stdscr, '|', '-');
    wattron(stdscr, COLOR_PAIR(1));
    char snake[50] = {'o','#','#','#'};
    for (int i = 0; i < size+gain; i++)
    {
        mvwprintw(stdscr,y-i,x,"%c", snake[i]);
    }
    wattroff(stdscr, COLOR_PAIR(1));
    refresh();
}

void printing(int y, int x, int dir) {
    switch (dir) {
        case 1:  // RIGHT
            printing_x_right(y, x);
            break;
        case 2:  // LEFT
            printing_x_left(y, x);
            break;
        case 3:  // UP
            printing_y_up(y, x);
            break;
        case 4:  // DOWN
            printing_y_down(y, x);
            break;
        default:
            break;
    }
}

int main(){

    int x,y,max_x,max_y;
    start_point:
    start_game(&y, &x, &max_y, &max_x);
    int ch;
    int dir = 1; // 1=right, 2=left, 3=up, 4=down
    box(stdscr, '|', '-');

    nodelay(stdscr, TRUE);
    while (1)
    {
        ch = getch();
        if (ch == KEY_UP && dir !=4)
            dir =3;
        else if (ch == KEY_DOWN && dir !=3)
            dir =4;
        else if (ch == KEY_LEFT && dir != 1)
            dir =2;
        else if (ch == KEY_RIGHT && dir != 2)
            dir =1;
        else if (ch == 27)
            break;
        
        switch (dir) {
        case 1: x++; break; // right
        case 2: x--; break; // left
        case 3: y--; break; // up
        case 4: y++; break; // down
        }
        
        if (x<=0 || x>= max_x || y<=0 || y>= max_y){
            nodelay(stdscr, FALSE);
            game_over();
            goto start_point;
        }
        printing(y, x, dir);
        refresh();
        usleep(100000);
    }

    nodelay(stdscr, FALSE);
    endwin();
    return 0;

}