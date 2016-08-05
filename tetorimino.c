//
// Created by t on 16/07/16.
//

#include <stdlib.h>
#include <stdio.h>
#include "tetorimino.h"

int *patterns;


int LoadTetorimino()
{
    FILE *fp = fopen("tetoriminos.dat","r");
    if( fp == NULL )return 0;
    int head;
    fread(&head,sizeof(int),1,fp);
    patterns = malloc( head );
    int ret = fread(patterns,head,1,fp);
    fclose(fp);
    return ret;
}

TETORIMINO *CreateTetorimino()
{
    TETORIMINO *mino = (TETORIMINO*)malloc( sizeof(TETORIMINO ) );
    return mino;
}

void DeleteTetorimino( TETORIMINO *mino )
{
    free(mino);
}

inline int GetTetoriminoBlock(TETORIMINO *mino, int x, int y)
{
    if( mino->pattern > 1)
        return -1;
    return patterns[ (mino->pattern * 4 + mino->state ) * 16 + y * 4 + x];
}

inline int GetTetoriminoHeight(TETORIMINO *mino)
{
    return 4;
}

inline int GetTetoriminoWidth( TETORIMINO *mino )
{
    return 4;
}

inline void SpinTetoriminoClockwise( TETORIMINO *mino )
{
    mino->state = (mino->state + 1 ) % 4;
}

inline void SpinTetoriminoCounterClockwise( TETORIMINO *mino )
{
    mino->state = (mino->state - 1 ) % 4;
}
