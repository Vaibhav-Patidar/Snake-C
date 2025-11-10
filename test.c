#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

void launch(){
    for (int i = 3; i >= 1; i--)
    {
        clear();
        printw("Launching in....%d",i);
        refresh();
        sleep(1);
    }  
}
void closing(){
    for (int i = 3; i >= 1; i--)
    {
        clear();
        printw("Closing in ....%d",i);
        refresh();
        sleep(1);
    } 
}
int main(){
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
 
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    refresh();
    printw("Launching in....");
    clear();
    launch();
    clear();
    mvwprintw(stdscr,max_y/2, (max_x-28)/2,"Press any key to continue");
    refresh();
    getch();
    clear();
    printw("Closing in....");
    clear();
    closing();
    clear();
    mvprintw(max_y / 2, (max_x - 10) / 2, "Goodbye!");
    refresh();
    sleep(1);
    endwin();
    return 0;
}