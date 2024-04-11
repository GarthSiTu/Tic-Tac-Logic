#include "SZQ_basic.h"


/*
* @brief    creat  chequer
*/
char** creatQP() {
	char** QP;
	QP = (char**)malloc(sizeof(char*) * N);
	if (QP == NULL)
		return NULL;
	for (int i = 0; i < N; i++) {
		QP[i] = (char*)malloc(sizeof(char) *N);
		if (QP[i] == NULL)
			return NULL;
		memset(QP[i], ' ', sizeof(char)*N);
	}
	return QP;
}


/*
* @brief    printf Chequer
* @para     ���̵�ַ
*/
void printQP(char** QP) {

	if (QP == NULL) {
		printf("print Chequer failed!");
		return;
	}

	puts("|_____________________________    ����    ___________________________|");
	printf("\t\t �кš�  1   2   3\t\t������ӣ���o��\n\t\t �кš�\t\t\t\t�������ӣ���X��\n");
	printf("\t\t       |---|---|---|\n");
	for (int i = 0; i < N; i++) {
		printf("\t\t      %d|", i + 1);
		for (int j = 0; j < N; j++) {
			printf(" %c |", QP[i][j]);
		}
		printf("\n");
		printf("\t\t       |");
		for (int j = 0; j < N; j++) {
			printf("---|");
		}
		printf("\n");
	}
	puts("|--------------------------------------------------------------------|");
}

int inputQZ(char** QP, int row, int column) {
	if (row < 0 || row>2 || column < 0 || column>2) {
		printf("��������λ�ò��Ϸ���\n���������룺>>");
		return 0;
	}
	if (QP[row][column] != ' ') {
		printf("��λ���������ӣ�\n���������룺>>");
		return 0;
	}
	QP[row][column] = P_pawn;
	return 1;
}

/*
*@brief  �ж���Ϸ�Ƿ��������һ�ʤ����
*@ret    1:���ʤ   0����Ϸδ����   -1����Ұ�
*/
int isPlayerWin(char** QP) {
	int flag = 0;

	//�ж��г���
	for (int i = 0; i < N; i++)
	{
		if (QP[i][0] == QP[i][1] && QP[i][0] == QP[i][2] && QP[i][0] == C_pawn)
			flag = -1;
		else if (QP[i][0] == QP[i][1] && QP[i][0] == QP[i][2] && QP[i][0] == P_pawn)
			flag = 1;
	}
	//�ж��г���
	for (int j = 0; j < N; j++)
	{
		if (QP[0][j] == QP[1][j] && QP[0][j] == QP[2][j] && QP[0][j] == C_pawn)
			flag = -1;
		else if (QP[0][j] == QP[1][j] && QP[0][j] == QP[2][j] && QP[0][j] == P_pawn)
			flag = 1;
	}
	//�ж����Խǳ���
	if (QP[0][0] == QP[1][1] && QP[0][0] == QP[2][2] && QP[0][0] == C_pawn)
		flag = -1;
	else if (QP[0][0] == QP[1][1] && QP[0][0] == QP[2][2] && QP[0][0] == P_pawn)
		flag = 1;

	//�жϷ��Խǳ���
	if (QP[0][2] == QP[1][1] && QP[0][2] == QP[2][0] && QP[0][2] == C_pawn)
		flag = -1;
	else if (QP[0][2] == QP[1][1] && QP[0][2] == QP[2][0] && QP[0][2] == P_pawn)
		flag = 1;

	return flag;
}


/*
* brief  �ж������Ƿ����ˣ����˼�ƽ��
*/
int isQPFull(char** QP) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (QP[i][j] ==' ')
				return 0;
		}
	}
	return 1;
}