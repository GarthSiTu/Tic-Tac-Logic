/*
* 根据对落子位置的打分，选择分数最高的位置，分数相同则随机选择
* 根据打表表和同行、同列、同对角的棋子类型，确定分数
* 
*  制定打分表
* C_pawn+C_pawn：100        P_pawn+P_pawn:50     C_pawn+空：6
* P_pawn+空：4             空+空：2            P_pawn+C_pawn：1
* 不是对角线：0
*/


#include "SZQ_engine.h"


//打分表以数组形式存储
int scoretable[6][2] = { {C_pawn + C_pawn,100},
						 {P_pawn + P_pawn,50},
						 {C_pawn + ' ',6},
						 {P_pawn + ' ',4},
						 {' ' +' ',2},
						 {P_pawn + C_pawn,1},
};


int computerPlay(char** QP) {
	int index=0;
	int score = 0;

	for (int i = 0; i < N*N; i++)
	{
		int temp_score = 0;
		if (QP[i / N][i % N] == ' ')
		{
			temp_score = row_score(QP, i/N) + column_score(QP, i%N) + Pdiag_score(QP, i) + Ndiag_score(QP, i);
			if (temp_score > score)
			{
				score = temp_score;
				index = i;
			}
			else if (temp_score == score)
			{
				srand((unsigned)time(NULL));
				index=(rand() % 2)? i:index;
			}	
		}
	}
	return index;
}

int row_score(char** QP,int row){
	int score=0;
	int type = 0;
	for (int i = 0; i < N; i++)
	{
		type = QP[row][i] + type;
	}
	type = type - ' ';
	for (int k = 0; k < 6; k++)
	{
		if (scoretable[k][0] == type)
		{
			score = scoretable[k][1];
			break;
		}
	}

	return score;
}

int column_score(char** QP, int column) {
	int score = 0;
	int type = 0;
	for (int i = 0; i < N; i++)
	{
		type = QP[i][column] + type;
	}
	type = type - ' ';
	for (int k = 0; k < 6; k++)
	{
		if (scoretable[k][0] == type)
		{
			score = scoretable[k][1];
			break;
		}
	}

	return score;
}

int Pdiag_score(char** QP, int postion) {
	int score = 0;
	int type ;
	if (postion/N==postion%N)
	{
		type = QP[0][0] + QP[1][1] + QP[2][2];
		type = type - ' ';
		for (int k = 0; k < 6; k++)
		{
			if (scoretable[k][0] == type)
			{
				score = scoretable[k][1];
				break;
			}
		}
	}
	return score;
}

int Ndiag_score(char** QP, int postion) {
	int score = 0;
	int type;
	if ((postion / N+postion % N)==2)
	{
		type = QP[0][2] + QP[1][1] + QP[2][0];
		type = type - ' ';
		for (int k = 0; k < 6; k++)
		{
			if (scoretable[k][0] == type)
			{
				score = scoretable[k][1];
				break;
			}
		}
	}
	return score;
}