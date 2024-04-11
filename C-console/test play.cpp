#define _CRT_SECURE_NO_WARNINGS 
#include <windows.h> 

#include "SZQ_engine.h"
#include "SZQ_basic.h"


int main() {
	//printf("%d", C_pawn+C_pawn);
	int hang, lie;
	int cmd = 1;
	int position;
	char** TicTacToe = creatQP();
	puts("______________________________________________________________________");
	puts("|*********************** Tic-Tac-Logic (game) ***********************|");
	puts("|** author:gofan-SiTu ***********************************************|");
	puts("|************************           ��ѡ�����¹���      *************|");
	puts("|************************            0���˳���Ϸ          ***********|");
	puts("|************************     1����Ϊ���ֿ�ʼ����Զ���   ***********|");
	puts("|************************     2����Ϊ���ֿ�ʼ����Զ���   ***********|");
	puts("|********************************************************************|");
	puts("|��������������������������������������������������������������������|");
	printf(">�������Ӧ��ţ�>>");
	scanf_s("%d", &cmd);
	switch (cmd)
	{
	case 0:
		exit(0);
	case 1:
		printf(">��ѡ������Զ��ģ�����ʱ�������кź��к�ȷ��λ�ã��м��ÿո����\n");
		printf(">���������ǡ�o��,���Ե������ǡ�X��\n");
		printQP(TicTacToe);
		printf(">��������  ");
		while (1) {
			printf(">������������һ������λ�ã�>>");
			do {
				scanf_s("%d%d", &hang, &lie);
			} while (!inputQZ(TicTacToe, hang - 1, lie - 1));
			printf(">���������������\n");
			printQP(TicTacToe);
			if (isPlayerWin(TicTacToe) == 1) {
				printf("\n>����ϲ��һ�ʤ ��<\n >  ��̫ǿ��  <\n");
				break;
			}
			else if (isPlayerWin(TicTacToe) == -1) {
				printf("\n >  ���Ի�ʤ  < \n >����̫������< \n");
				break;
			}
			else if (isQPFull(TicTacToe)) {
				printf(" >��ƽ�� ��< \n");
				break;
			}
			position = computerPlay(TicTacToe);
			printf(" ��������˼��......\n");
			Sleep(1000);
			printf(">���Ե�����λ�ã�>>%d %d\n>�������Ӻ���������\n", position / N + 1, position % N + 1);
			TicTacToe[position / N][position % N] = C_pawn;
			Sleep(100);
			printQP(TicTacToe);
			if (isPlayerWin(TicTacToe) == 1) {
				printf("\n>����ϲ��һ�ʤ ��<\n >  ��̫ǿ��  <\n");
				break;
			}
			else if (isPlayerWin(TicTacToe) == -1) {
				printf("\n >  ���Ի�ʤ  < \n >����̫������< \n");
				break;
			}
			else if (isQPFull(TicTacToe)) {
				printf(" >��ƽ�� ��< \n");
				break;
			}
		}
		break;
	case 2:
		printf(">��ѡ������Զ��ģ�����ʱ�������кź��к�ȷ��λ�ã��м��ÿո����\n");
		printf(">���������ǡ�o��,���Ե������ǡ�X��\n");
		printf(">����������\n");
		while (1) {
			position = computerPlay(TicTacToe);
			printf(" ��������˼��......\n");
			Sleep(1000);
			printf(">���Ե�����λ�ã�>>%d %d\n>�������Ӻ���������\n", position / N + 1, position % N + 1);
			TicTacToe[position / N][position % N] = C_pawn;
			Sleep(250);
			printQP(TicTacToe);
			if (isPlayerWin(TicTacToe) == 1) {
				printf("\n>����ϲ��һ�ʤ ��<\n >  ��̫ǿ��  <\n");
				break;
			}
			else if (isPlayerWin(TicTacToe) == -1) {
				printf("\n >  ���Ի�ʤ  < \n >����̫������< \n");
				break;
			}
			else if (isQPFull(TicTacToe)) {
				printf(" >��ƽ�� ��< \n");
				break;
			}
			printf(">������������һ������λ�ã�>>");
			do {
				scanf_s("%d%d", &hang, &lie);
			} while (!inputQZ(TicTacToe, hang - 1, lie - 1));
			printf(">���������������\n");
			printQP(TicTacToe);
			if (isPlayerWin(TicTacToe) == 1) {
				printf("\n>����ϲ��һ�ʤ ��<\n >  ��̫ǿ��  <\n");
				break;
			}
			else if (isPlayerWin(TicTacToe) == -1) {
				printf("\n >  ���Ի�ʤ  < \n >����̫������< \n");
				break;
			}
			else if (isQPFull(TicTacToe)) {
				printf(" >��ƽ�� ��< \n");
				break;
			}

		}
		break;
	default:
		printf(">������Ų�׼ȷ�������쳣�˳���\n ������������");
		exit(-1);
	}
	printf("\n  ��Ϸ������ \n");
	for (int i = 0; i < N; i++)
		free(TicTacToe[i]);
	free(TicTacToe);
	for (int i = 5; i >= 0; i--)
	{
		printf("������%ds��ر�...\n", i);
		Sleep(1000);
	}
	return 0;
}
