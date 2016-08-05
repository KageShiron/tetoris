//
// Created by t on 16/07/16.
//

#include "board.h"

#ifndef TETORIS_GAME_H
#define TETORIS_GAME_H

enum GAME_ACTION{
    GA_NONE,
    GA_LEFT,
    GA_RIGHT,
    GA_UP,
    GA_DOWN,
    GA_A,
    GA_B,
    GA_BREAK
};

void GameInit ();
void DoFrame( int action );
void GameEnd();
BOARD *GetBoard();
TETORIMINO *GetTetoriminoOnBoard();

#endif //TETORIS_GAME_H
