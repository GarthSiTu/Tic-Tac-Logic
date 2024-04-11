using static System.Formats.Asn1.AsnWriter;
using System;
using System.Threading.Tasks;
using Wongoing.Basic;

namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            buttonList = new Button[9]{ this.button1, this.button2, this.button3,
                                        this.button4, this.button5, this.button6,
                                        this.button7, this.button8, this.button9};
        }
        
        int[] lifeTime = new int[9] {0,0,0,0,0,0,0,0,0};
        int[,] scoretable = new int[6, 2]{
            {'X'+'X',100 },
            {'o'+'o',50 },
            {'X'+' ',6},
            {'o'+' ',4 },
            {' '+' ',2 },
            {'X'+'o',1 }  };
        private void udateLifeTime(int retult)
        {
            if (retult == 1)
            {
                MessageBox.Show("呦呦呦，竟然让你赢了!\n再来一局吧");
                Application.Restart();
                return;
            }
            if (retult == -1)
            {
                MessageBox.Show("你输了，真的菜！！！\n再来一局吧");
                Application.Restart();
                return;
            }
            for (int i = 0; i < lifeTime.Length; i++)
            {
                if (lifeTime[i] > 0)
                {
                    if (lifeTime[i] == 6)
                    {
                        this.buttonList[i].ForeColor = System.Drawing.SystemColors.HotTrack;
                    }
                    else
                    {
                        this.buttonList[i].ForeColor = System.Drawing.SystemColors.ControlText;
                    }
                    lifeTime[i]--;
                    if (lifeTime[i] == 0)
                    {
                        this.buttonList[i].Text = " ";
                    }
                }
            }
        }
        private int isplayerWin()
        {
            int flag = 0;

            //判断行成线
            for (int i = 0; i < 3; i++)
            {
                if (buttonList[i * 3 + 0].Text == buttonList[i * 3 + 1].Text && buttonList[i * 3 + 0].Text == buttonList[i * 3 + 2].Text && buttonList[i * 3 + 0].Text == "X")
                    flag = -1;
                else if (buttonList[i * 3 + 0].Text == buttonList[i * 3 + 1].Text && buttonList[i * 3 + 0].Text == buttonList[i * 3 + 2].Text && buttonList[i * 3 + 0].Text == "o")
                    flag = 1;
            }
            //判断列成线
            for (int j = 0; j < 3; j++)
            {
                if (buttonList[0 + j].Text == buttonList[3 + j].Text && buttonList[0 + j].Text == buttonList[6 + j].Text && buttonList[0 + j].Text == "X")
                    flag = -1;
                else if (buttonList[0 + j].Text == buttonList[3 + j].Text && buttonList[0 + j].Text == buttonList[6 + j].Text && buttonList[0 + j].Text == "o")
                    flag = 1;
            }
            //判断正对角成线
            if (buttonList[0].Text == buttonList[4].Text && buttonList[0].Text == buttonList[8].Text && buttonList[0].Text == "X")
                flag = -1;
            else if (buttonList[0].Text == buttonList[4].Text && buttonList[0].Text == buttonList[8].Text && buttonList[0].Text == "o")
                flag = 1;

            //判断反对角成线
            if (buttonList[2].Text == buttonList[4].Text && buttonList[2].Text == buttonList[6].Text && buttonList[2].Text == "X")
                flag = -1;
            else if (buttonList[2].Text == buttonList[4].Text && buttonList[2].Text == buttonList[6].Text && buttonList[2].Text == "o")
                flag = 1;
            return flag;
        }
        private void computerPlay()
        {
            int index = 0;
            int score = 0;
            MessageBoxTimeOut.Show("电脑思考中...", "提示", 1000);
            for (int i = 0; i < 9; i++)
            {
                int temp_score;
                if (lifeTime[i] == 0)
                {
                    temp_score = row_score(i / 3) + column_score(i % 3) + Pdiag_score(i) + Ndiag_score(i);
                    if (temp_score > score)
                    {
                        score = temp_score;
                        index = i;
                    }
                    else if (temp_score == score)
                    {
                        Random ran = new Random();
                        index = (ran.Next(2) % 2 == 0) ? i : index;
                    }
                }
            }
            buttonList[index].Text = "X";
            lifeTime[index] = 6;
            udateLifeTime(isplayerWin());

        }
        private int row_score(int row)
        {
            int score = 0;
            int type = 0;
            for (int i = 0; i < 3; i++)
            {
                if (lifeTime[row * 3 + i] - 1 == 0)
                {
                    type = ' ' + type;
                }
                else
                {
                    type = char.Parse(buttonList[row * 3 + i].Text) + type;
                }
            }
            type = type - ' ';
            for (int k = 0; k < 6; k++)
            {
                if (scoretable[k,0] == type)
                {
                    score = scoretable[k,1];
                    break;
                }
            }
            return score;
        }
        private int column_score(int column)
        {
            int score = 0;
            int type = 0;
            for (int i = 0; i < 3; i++)
            {
                if (lifeTime[i * 3 + column] - 1 == 0)
                {
                    type = ' ' + type;
                }
                else
                {
                    type = char.Parse(buttonList[i * 3 + column].Text) + type;
                }
            }
            type = type - ' ';
            for (int k = 0; k < 6; k++)
            {
                if (scoretable[k, 0] == type)
                {
                    score = scoretable[k, 1];
                    break;
                }
            }
            return score;
        }
        private int Pdiag_score(int postion)
        {
            int score = 0;
            int type = 0;
            if (postion / 3 == postion % 3)
            {
                //type = QP[0][0] + QP[0][4] + QP[0][8];
                for (int i = 0; i < 3; i++)
                {
                    if (lifeTime[i * 4] - 1 == 0)
                    {
                        type = ' ' + type;
                    }
                    else
                    {
                        type = char.Parse(buttonList[i * 4].Text) + type;
                    }
                }
                type = type - ' ';
                for (int k = 0; k < 6; k++)
                {
                    if (scoretable[k,0] == type)
                    {
                        score = scoretable[k,1];
                        break;
                    }
                }
            }
            return score;
        }
        private int Ndiag_score(int postion)
        {
            int score = 0;
            int type = 0;
            if ((postion / 3 + postion % 3) == 2)
            {
                //type = QP[0][2] + QP[0][4] + QP[0][6];
                for (int i = 0; i < 3; i++)
                {
                    if (lifeTime[i * 2 + 2] - 1 == 0)
                    {
                        type = ' ' + type;
                    }
                    else
                    {
                        type = char.Parse(buttonList[i * 2 + 2].Text) + type;
                    }
                }
                type = type - ' ';
                for (int k = 0; k < 6; k++)
                {
                    if (scoretable[k,0] == type)
                    {
                        score = scoretable[k,1];
                        break;
                    }
                }
            }
            return score;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            if (lifeTime[0] == 0)
            {
                this.buttonList[0].Text = "o";
                lifeTime[0] = 6;
                udateLifeTime(isplayerWin());
                computerPlay();
            }
            else
            {
                MessageBox.Show("该位置已有棋子\n请重新落子");
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (lifeTime[1] == 0)
            {
                this.buttonList[1].Text = "o";
                lifeTime[1] = 6;
                udateLifeTime(isplayerWin());
                computerPlay();
            }
            else
            {
                MessageBox.Show("该位置已有棋子\n请重新落子");
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (lifeTime[2] == 0)
            {
                this.buttonList[2].Text = "o";
                lifeTime[2] = 6;
                udateLifeTime(isplayerWin());
                computerPlay();
            }
            else
            {
                MessageBox.Show("该位置已有棋子\n请重新落子");
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (lifeTime[3] == 0)
            {
                this.buttonList[3].Text = "o";
                lifeTime[3] = 6;
                udateLifeTime(isplayerWin());
                computerPlay();
            }
            else
            {
                MessageBox.Show("该位置已有棋子\n请重新落子");
            }
        }
        private void button5_Click(object sender, EventArgs e)
        {
            if (lifeTime[4] == 0)
            {
                this.buttonList[4].Text = "o";
                lifeTime[4] = 6;
                udateLifeTime(isplayerWin());
                computerPlay();
            }
            else
            {
                MessageBox.Show("该位置已有棋子\n请重新落子");
            }
        }
        private void button6_Click(object sender, EventArgs e)
        {
            if (lifeTime[5] == 0)
            {
                this.buttonList[5].Text = "o";
                lifeTime[5] = 6;
                udateLifeTime(isplayerWin());
                computerPlay();
            }
            else
            {
                MessageBox.Show("该位置已有棋子\n请重新落子");
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            if (lifeTime[6] == 0)
            {
                this.buttonList[6].Text = "o";
                lifeTime[6] = 6;
                udateLifeTime(isplayerWin());
                computerPlay();
            }
            else
            {
                MessageBox.Show("该位置已有棋子\n请重新落子");
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            if (lifeTime[7] == 0)
            {
                this.buttonList[7].Text = "o";
                lifeTime[7] = 6;
                udateLifeTime(isplayerWin());
                computerPlay();
            }
            else
            {
                MessageBox.Show("该位置已有棋子\n请重新落子");
            }
        }

        private void button9_Click(object sender, EventArgs e)
        {
            if (lifeTime[8] == 0)
            {
                this.buttonList[8].Text = "o";
                lifeTime[8] = 6;
                udateLifeTime(isplayerWin());
                computerPlay();
            }
            else
            {
                MessageBox.Show("该位置已有棋子\n请重新落子");
            }
        }

        private void button10_Click(object sender, EventArgs e)
        {
            MessageBox.Show("1.玩家棋子：“o”\t电脑棋子“X”\n2.一方三子连成线即获得胜利\n3.当棋盘落下第6颗棋子时，若还未决出胜负，此时第一颗下的棋子会消失,以此类推！\n4.游戏是玩家先手，电脑先手的功能还未开发");
        }

        private void button11_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}