//
// Created by t on 16/07/16.
//

#ifndef TETORIS_BOARD_H
#define TETORIS_BOARD_H

#include "tetorimino.h"

typedef struct {
    int *table;
    int boardWidth;
    int boardHeight;
}BOARD;
BOARD *CreateBoard( int width , int height);
void DeleteBoard( BOARD *brd );

int GetBoardBlock( BOARD *brd, int x , int y);
int SetBoardBlock( BOARD *brd, int x, int y, int val);
void CopyTetoriminoToBoard( BOARD *brd , TETORIMINO *mino );
int HitTest( BOARD *brd, int x , int y ,TETORIMINO *mino);
int HitTestNow( BOARD *brd, TETORIMINO *mino);

#endif //TETORIS_BOARD_H
