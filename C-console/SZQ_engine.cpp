/*
* ���ݶ�����λ�õĴ�֣�ѡ�������ߵ�λ�ã�������ͬ�����ѡ��
* ���ݴ����ͬ�С�ͬ�С�ͬ�Խǵ��������ͣ�ȷ������
* 
*  �ƶ���ֱ�
* C_pawn+C_pawn��100        P_pawn+P_pawn:50     C_pawn+�գ�6
* P_pawn+�գ�4             ��+�գ�2            P_pawn+C_pawn��1
* ���ǶԽ��ߣ�0
*/


#include "SZQ_engine.h"


//��ֱ���������ʽ�洢
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