#include<stdio.h>
#include <string.h>
#include<stdlib.h>

#define N 3
#define P_pawn 'o'
#define C_pawn 'X'

char** creatQP();
void printQP(char** QP);
int inputQZ(char** QP, int row, int column);
int isPlayerWin(char** QP);
int isQPFull(char** QP);

