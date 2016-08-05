//
// Created by t on 16/07/16.
//

#include "board.h"
#include "tetorimino.h"
#include "stdlib.h"


#define MINOLOOP int width = GetTetoriminoWidth(mino);\
    int height = GetTetoriminoHeight(mino);\
    for (int x = 0; x < width; ++x)\
    for (int y = 0; y < height; ++y)

BOARD *CreateBoard( int width , int height )
{
    BOARD *brd = (BOARD*)calloc(0 , sizeof(BOARD));
    if(brd == NULL)return NULL;
    brd->boardWidth = width;
    brd->boardHeight = height;
    brd->table = calloc( brd->boardWidth * brd->boardHeight , sizeof(int) );
    if(brd->table == NULL)
    {
        DeleteBoard(brd);
        return NULL;
    }
    return brd;
}

void DeleteBoard( BOARD *brd )
{
    if(brd == NULL)return;
    free(brd->table);
    free(brd);
}


int GetBoardBlock( BOARD *brd, int x , int y)
{
    return brd->table[ y * brd->boardWidth + x];
}

int SetBoardBlock( BOARD *brd, int x, int y, int val)
{
    int ret = brd->table[ y * brd->boardWidth + x];
    brd->table[ y * brd->boardWidth + x] = val;
    return ret;
}

void CopyTetoriminoToBoard( BOARD *brd , TETORIMINO *mino )
{
    int width = GetTetoriminoWidth(mino);
    int height = GetTetoriminoHeight(mino);
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            {
                int m = GetTetoriminoBlock(mino, x, y);
                if (m != 0) SetBoardBlock(brd, mino->x + x, mino->y + y, m);
            }
        }
    }
}
int HitTest(BOARD *brd, int moveX , int moveY ,TETORIMINO *mino)
{
    MINOLOOP{
            if( GetTetoriminoBlock(mino,x,y) == 0)continue;
            if( mino->x + moveX + x < 0 || mino->x + moveX + x >= brd->boardWidth
                || mino->y + moveY + y < 0 || mino->y + moveY + y >= brd->boardHeight)
                return 1;
            if( GetBoardBlock(brd,mino->x + moveX + x, mino->y + moveY + y) != 0 )
                return 2;
        };
    return 0;
}

int HitTestNow(BOARD *brd, TETORIMINO *mino)
{
    return HitTest(brd,0,0,mino);
}

