#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "start.h"
#include "gameover.h"

void printing_x_right(int y,int x){
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

struct GameState {
    int x, y;
    int max_x, max_y;
    int score;   
};


void printing_y_up(int y,int x){
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
        case 1:
            printing_x_right(y, x);
            break;
        case 2:
            printing_x_left(y, x);
            break;
        case 3:
            printing_y_up(y, x);
            break;
        case 4:
            printing_y_down(y, x);
            break;
        default:
            break;
    }
}

int main(){
    int first = 4;
    int food_x,food_y;
    struct GameState g;
    start_point:
    start_game(&g.y, &g.x, &g.max_y, &g.max_x);
    food_x = 2 + rand() % (g.max_x - 4);
    food_y = 2 + rand() % (g.max_y - 4);
    int ch;
    g.score = 0;
    int dir = 1; // 1=right, 2=left, 3=up, 4=down
    box(stdscr, '|', '-');

    nodelay(stdscr, TRUE);
    while (1)
    {
        ch = getch();
        clear();
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
        case 1: g.x++; break; // right
        case 2: g.x--; break; // left
        case 3: g.y--; break; // up
        case 4: g.y++; break; // down
        }

        int speed = 100000;
        if (g.x<=0+1.5 || g.x>= g.max_x-1.5 || g.y<=0+1.5 || g.y>= g.max_y-1.5){
            nodelay(stdscr, FALSE);
            game_over(g.score);
            g.score = 0;
            goto start_point;
        }
        else if(g.x == food_x && g.y == food_y){
            g.score++;
            food_x = 2 + rand() % (g.max_x - 4);
            food_y = 2 + rand() % (g.max_y - 4);
            speed = speed * 0.9;
        }
        mvprintw(food_y, food_x, "$");
        printing(g.y, g.x, dir);
        refresh();
        usleep(speed);
    }
    nodelay(stdscr, FALSE);
    endwin();
    return 0;

}