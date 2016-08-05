#include <ncurses.h>
#include "ui.h"
#include "game.h"


int main() {
    GameInit();
    UIInit();

    attron(COLOR_PAIR(1));
    mvaddstr(1,0,"000");
    while(true) {
        BOARD *brd = GetBoard();
        TETORIMINO *mino = GetTetoriminoOnBoard();
        int act = DoUI(brd,mino);
        DoFrame(act);

        attron(COLOR_PAIR(1));
        mvprintw(0,0,"(%d,%d)",mino->x,mino->y);
    }
    GameEnd();
    UIEnd();
}