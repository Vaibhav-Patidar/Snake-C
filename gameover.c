#include "gameover.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

void game_over(int score){
    clear();
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    int center_y = max_y / 2;
    int center_x = max_x / 2;

    attron(COLOR_PAIR(2));
    mvprintw(center_y, (max_x - strlen("Game Over")) / 2, "Game Over");
    mvprintw(center_y + 2, (max_x - strlen("Press any key to continue...")) / 2,"Press any key to continue...");
    char score_str[50];
    static int high = 0;
    if (score > high){
        high = score;
    }
    sprintf(score_str, "Final Score: %d |  High Score: %d", score, high);
    int score_x = (max_x - strlen(score_str)) / 2;
    int score_y = center_y + 4;
    mvprintw(score_y, score_x, "%s", score_str);
    attroff(COLOR_PAIR(2));

    refresh();
    nodelay(stdscr, FALSE);
    getch();
    nodelay(stdscr, TRUE);
    clear();
}