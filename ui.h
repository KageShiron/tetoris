//
// Created by t on 16/07/16.
//

#ifndef TETORIS_UI_H
#define TETORIS_UI_H

#include "tetorimino.h"
#include "board.h"

void UIInit();
int DoUI(BOARD *brd, TETORIMINO *mino);
void UIEnd();

#endif //TETORIS_UI_H
