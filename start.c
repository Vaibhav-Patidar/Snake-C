#include "start.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


void start_game(int *y, int *x, int *max_y, int *max_x) {
    initscr();
    cbreak();
    start_color();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    getmaxyx(stdscr, *max_y, *max_x);
    *y = *max_y/2;
    *x = *max_x/2;
    refresh();
    mvwprintw(stdscr,*max_y/2, (*max_x-22)/2,"Press Enter to start");
    refresh();
    getch();
    clear();
    int size = 4;
    wattron(stdscr, COLOR_PAIR(1));
    char snake[50] = {'o','#','#','#'};
    for (int i = 0; i < size; i++)
    {
        mvwprintw(stdscr,*y,*x+i,"%c", snake[i]);
    }
    wattroff(stdscr, COLOR_PAIR(1));
    refresh();
}