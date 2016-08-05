//
// Created by t on 16/07/16.
//

#include <stdlib.h>
#include <curses.h>
#include "game.h"
#include "board.h"
#include "tetorimino.h"

static BOARD *brd;
static TETORIMINO *mino;
static int speed = 9000;

void newMino()
{
    mino->x = 0;
    mino->y = 0;
    mino->pattern = 0;
    mino->state = 0;
    mino->color = 1;
}
void GameInit()
{
    int t = LoadTetorimino();
    if(t == 0 )
    {
        fputs("Load Error",stderr);
        exit(1);
    }
    brd = CreateBoard(10,20);
    mino = CreateTetorimino();
    newMino();
}

//移動を試みます
// 0 : 成功
// 1 : 失敗(壁)
// 2 : 失敗(他のブロック)
int tryMove( BOARD *brd , TETORIMINO *mino , int moveX , int moveY )
{
    int r = HitTest( brd ,  moveX , moveY , mino );
    if(r != 0)
    {
        return 1;
    }
    mino->x += moveX;
    mino->y += moveY;
    return 0;
}


void doAction( int action )
{
    switch( action )
    {
        case GA_A:
            SpinTetoriminoClockwise(mino);
            if( HitTestNow(brd,mino) != 0)  //あたっていたら回転失敗
                SpinTetoriminoCounterClockwise(mino);
            break;
        case GA_B:
            SpinTetoriminoCounterClockwise(mino);
            if( HitTestNow(brd,mino) != 0)  //あたっていたら回転失敗
                SpinTetoriminoClockwise(mino);
        case GA_LEFT:
            tryMove(brd, mino, -1, 0);
            break;
        case GA_RIGHT:
            tryMove(brd, mino, 1, 0);
            break;
    }
}
void deleteLine(int line){
    int width = brd->boardWidth;
    for (int y = line ; y > 0 ; --y) {
        for (int x = 0; x < width; ++x) {
            SetBoardBlock(brd,x,y , GetBoardBlock(brd,x,y - 1));
        }
    }
}
void checkLine() {
    int width = brd->boardWidth;
    int height = brd->boardHeight;
    int flag = 0;
    for (int y = 0; y < height ; ++y) {
        flag = 1;
        for (int x = 0; x < width; ++x) {
            if (GetBoardBlock(brd, x, y) == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)deleteLine(y);
    }
}
void doEvery()
{
    static int count = 0;
    count++;
    if( count > speed)
    {
        if(tryMove(brd, mino, 0, 1) != 0) {
            CopyTetoriminoToBoard(brd, mino);
            newMino();
            checkLine();
        }
        count = 0;
    }
}


void DoFrame( int action )
{
    doAction( action );
    doEvery();
}
void GameEnd()
{
    DeleteBoard(brd);
    DeleteTetorimino(mino);
}

BOARD *GetBoard()
{
    return brd;
}

TETORIMINO *GetTetoriminoOnBoard()
{
    return mino;
}