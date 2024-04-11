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
	puts("|************************           请选择以下功能      *************|");
	puts("|************************            0：退出游戏          ***********|");
	puts("|************************     1：作为先手开始与电脑对弈   ***********|");
	puts("|************************     2：作为后手开始与电脑对弈   ***********|");
	puts("|********************************************************************|");
	puts("|——————————————————————————————————|");
	printf(">请输入对应序号：>>");
	scanf_s("%d", &cmd);
	switch (cmd)
	{
	case 0:
		exit(0);
	case 1:
		printf(">您选择与电脑对弈，落子时请输入行号和列号确定位置，中间用空格隔开\n");
		printf(">您的棋子是“o”,电脑的棋子是“X”\n");
		printQP(TicTacToe);
		printf(">您先走棋  ");
		while (1) {
			printf(">请输入您的下一步落子位置：>>");
			do {
				scanf_s("%d%d", &hang, &lie);
			} while (!inputQZ(TicTacToe, hang - 1, lie - 1));
			printf(">您走棋后，棋盘如下\n");
			printQP(TicTacToe);
			if (isPlayerWin(TicTacToe) == 1) {
				printf("\n>！恭喜玩家获胜 ！<\n >  您太强了  <\n");
				break;
			}
			else if (isPlayerWin(TicTacToe) == -1) {
				printf("\n >  电脑获胜  < \n >！你太菜拉！< \n");
				break;
			}
			else if (isQPFull(TicTacToe)) {
				printf(" >！平局 ！< \n");
				break;
			}
			position = computerPlay(TicTacToe);
			printf(" 电脑正在思考......\n");
			Sleep(1000);
			printf(">电脑的落子位置：>>%d %d\n>电脑落子后，棋盘如下\n", position / N + 1, position % N + 1);
			TicTacToe[position / N][position % N] = C_pawn;
			Sleep(100);
			printQP(TicTacToe);
			if (isPlayerWin(TicTacToe) == 1) {
				printf("\n>！恭喜玩家获胜 ！<\n >  您太强了  <\n");
				break;
			}
			else if (isPlayerWin(TicTacToe) == -1) {
				printf("\n >  电脑获胜  < \n >！你太菜拉！< \n");
				break;
			}
			else if (isQPFull(TicTacToe)) {
				printf(" >！平局 ！< \n");
				break;
			}
		}
		break;
	case 2:
		printf(">您选择与电脑对弈，落子时请输入行号和列号确定位置，中间用空格隔开\n");
		printf(">您的棋子是“o”,电脑的棋子是“X”\n");
		printf(">电脑先走棋\n");
		while (1) {
			position = computerPlay(TicTacToe);
			printf(" 电脑正在思考......\n");
			Sleep(1000);
			printf(">电脑的落子位置：>>%d %d\n>电脑落子后，棋盘如下\n", position / N + 1, position % N + 1);
			TicTacToe[position / N][position % N] = C_pawn;
			Sleep(250);
			printQP(TicTacToe);
			if (isPlayerWin(TicTacToe) == 1) {
				printf("\n>！恭喜玩家获胜 ！<\n >  您太强了  <\n");
				break;
			}
			else if (isPlayerWin(TicTacToe) == -1) {
				printf("\n >  电脑获胜  < \n >！你太菜拉！< \n");
				break;
			}
			else if (isQPFull(TicTacToe)) {
				printf(" >！平局 ！< \n");
				break;
			}
			printf(">请输入您的下一步落子位置：>>");
			do {
				scanf_s("%d%d", &hang, &lie);
			} while (!inputQZ(TicTacToe, hang - 1, lie - 1));
			printf(">您走棋后，棋盘如下\n");
			printQP(TicTacToe);
			if (isPlayerWin(TicTacToe) == 1) {
				printf("\n>！恭喜玩家获胜 ！<\n >  您太强了  <\n");
				break;
			}
			else if (isPlayerWin(TicTacToe) == -1) {
				printf("\n >  电脑获胜  < \n >！你太菜拉！< \n");
				break;
			}
			else if (isQPFull(TicTacToe)) {
				printf(" >！平局 ！< \n");
				break;
			}

		}
		break;
	default:
		printf(">输入序号不准确，程序异常退出！\n 请重新启动！");
		exit(-1);
	}
	printf("\n  游戏结束！ \n");
	for (int i = 0; i < N; i++)
		free(TicTacToe[i]);
	free(TicTacToe);
	for (int i = 5; i >= 0; i--)
	{
		printf("程序将在%ds后关闭...\n", i);
		Sleep(1000);
	}
	return 0;
}
