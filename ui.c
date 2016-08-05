//
// Created by t on 16/07/16.
//

#include "ui.h"
#include "game.h"
#include "board.h"
#include "tetorimino.h"
#include <curses.h>

void UIInit()
{
    initscr();
    start_color();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr,TRUE);
    timeout(0);

    init_pair(1,COLOR_BLUE,COLOR_WHITE);
}

void draw(BOARD *brd, TETORIMINO *mino)
{
    attron(COLOR_PAIR(0));
    for (int x = 0; x < brd->boardWidth; ++x) {
        for (int y = 0; y < brd->boardHeight; ++y) {
            mvaddch( 5 + y , 5 + x, GetBoardBlock(brd,x,y) == 0 ? ' ' : '#' );
        }
    }
    attron(COLOR_PAIR(1));
    for (int x = 0; x < GetTetoriminoWidth(mino); ++x) {
        for (int y = 0; y < GetTetoriminoHeight(mino); ++y) {
            if(GetTetoriminoBlock(mino,x,y) != 0)mvaddch( 5 + mino->y + y , 5 + mino->x + x , '@' );
        }
    }
}

int DoUI( BOARD *brd, TETORIMINO *mino)
{
    draw(brd,mino);
    int ch = getch();

    switch(ch) {
        case 'a':
            return GA_A;
        case KEY_LEFT:
            return GA_LEFT;
        case KEY_RIGHT:
            return GA_RIGHT;
        case KEY_DOWN:
            return GA_DOWN;
        case KEY_UP:
            return GA_UP;
    }
    return GA_NONE;
}

void UIEnd()
{
    endwin();
}
