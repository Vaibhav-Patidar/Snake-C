#include "gameover.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

void game_over(){
    clear();
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    
    init_pair(2, COLOR_RED, COLOR_BLACK);
    
    int center_y = max_y / 2;
    int center_x = max_x / 2;
    
    // Even simpler, more compact text
    char* game_over_text[] = {
        "  ██████   █████  ███    ███ ███████  ",
        " ██       ██   ██ ████  ████ ██       ",
        " ██   ███ ███████ ██ ████ ██ █████    ",
        " ██    ██ ██   ██ ██  ██  ██ ██       ",
        "  ██████  ██   ██ ██      ██ ███████  ",
        "                                       ",
        "  ██████  ██    ██ ███████ ██████     ",
        " ██    ██ ██    ██ ██      ██   ██    ",
        " ██    ██ ██    ██ █████   ██████     ",
        " ██    ██  ██  ██  ██      ██   ██    ",
        "  ██████    ████   ███████ ██   ██    "
    };
    
    int num_lines = 11;
    
    attron(COLOR_PAIR(2) | A_BOLD);
    
    // Print each line
    for (int i = 0; i < num_lines; i++) {
        int line_width = strlen(game_over_text[i]);
        int x_pos = (max_x - line_width) / 2;
        int y_pos = center_y - num_lines/2 + i;
        
        // Safety check
        if (y_pos >= 0 && y_pos < max_y && x_pos >= 0) {
            mvprintw(y_pos, x_pos, "%s", game_over_text[i]);
        }
    }
    
    attroff(COLOR_PAIR(2) | A_BOLD);
    
    // Print message
    attron(COLOR_PAIR(2));
    char* msg = "Press any key to continue...";
    int msg_y = center_y + num_lines/2 + 2;
    int msg_x = (max_x - strlen(msg)) / 2;
    if (msg_y < max_y && msg_x >= 0) {
        mvprintw(msg_y, msg_x, "%s", msg);
    }
    attroff(COLOR_PAIR(2));
    
    refresh();
    nodelay(stdscr, FALSE);
    getch();
    nodelay(stdscr, TRUE);
    clear();
}