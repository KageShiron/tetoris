//
// Created by t on 16/07/16.
//

#ifndef TETORIS_TETO_H
#define TETORIS_TETO_H
typedef struct {
    int x;
    int y;
    int color;
    int pattern;
    int state;
}TETORIMINO;

TETORIMINO *CreateTetorimino();
int LoadTetorimino();
void DeleteTetorimino( TETORIMINO *mino );
int GetTetoriminoBlock(TETORIMINO *mino, int x, int y);
int GetTetoriminoHeight(TETORIMINO *mino);
int GetTetoriminoWidth( TETORIMINO *mino );
void SpinTetoriminoClockwise( TETORIMINO *mino );
void SpinTetoriminoCounterClockwise( TETORIMINO *mino );

#endif //TETORIS_TETO_H
