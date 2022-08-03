#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define ROW 3
#define COL 3
void computermove(char ch[ROW][COL],int row,int col)
	{
		printf("电脑走\n");
		srand((unsigned int)time(NULL));
		while(1)
		{
			int a = rand() % 3;
			int b = rand() % 3;
			if(ch[a -1][b -1] == ' ')
			{
				ch[a - 1][b - 1] = '#';
				break;	
			}
		}	
	} 	
int is_win(char ch[ROW][COL],int row,int col)
{
	int i,a;
	for(i = 0;i < ROW;i++)
	{
		if(ch[i][0] == ch[i][1] && ch[i][1] ==ch[i][2]&& ch[i][0] != ' ')
		{
			if(ch[i][0] == '*')
			{
				return 0;
				break;
			}
			else
			return 1;
			break;	
		}		
	}
	for(i = 0;i < ROW;i++)
	{
		if(ch[0][i] == ch[1][i] && ch[1][i] ==ch[2][i] && ch[0][i] != ' ')
		{
			if(ch[0][i] =='*' )
			{
				return 0;
				break;
			}
			else
			return 1;
			break;	
		}
	}
	
	if(ch[0][0] == ch[1][1] && ch[1][1] ==ch[2][2] && ch[0][0] != ' ')
	{
		if(ch[0][0] =='*')
		{
			return 0;
			
		}
		else
		return 1;
			
	}
	if(ch[0][2] == ch[1][1] && ch[1][1] ==ch[2][0] && ch[0][2] != ' ')
	{
		if(ch[2][0] =='*')
		{
			return 0;
			
		}
		else
		return 1;
			
	}			
	if(is_full( ch, row, col) == 1)
	{
		return 2;
	}
	return 3;
	
}
int is_full(char ch[ROW][COL],int row,int col)
{
	int i,j;
	for(i = 0;i < ROW;i++)
	{
		for(j = 0;j <COL;j++)
		{
			if(ch[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
void player_move(char ch[ROW][COL],int row,int col)
{
	int a,b;
	printf("玩家走\n");
	while(1)
	{
		printf("请输入坐标:");
		scanf("%d%d",&a,&b);
		if(ch[a -1][b -1] == ' ')
		{
			if(a <=3 && b <= 3)
			{
				ch[a - 1][b - 1] = '*';
				break;
			}
			else
			printf("坐标不合法");	
		}
		else
		printf("坐标已被占用");
		
	}
}
void print(char ch[ROW][COL],int row,int col)
{
	int i,a;
	for(i = 0;i < ROW;i++)//打印行
	{
		printf(" %c | %c | %c \n",ch[i][0],ch[i][1],ch[i][2]);
		if(i < ROW - 1)
		{	
			printf("---|---|---\n");
		}
	}
}
void arry(char ch[ROW][COL],int row,int col)
{
	int a,b;
	for(a = 0;a < row;a++)
	{
		for(b = 0;b < col;b++)
		{
			ch[a][b] = ' ';
		}
	}
}
void game()
{
	char ch[ROW][COL];
	arry(ch,ROW,COL);//数组初始化
	while(1)
	{
		print(ch,ROW,COL);//打印棋盘
		player_move(ch,ROW,COL);//玩家走
		print(ch,ROW,COL);
		if(is_win(ch,ROW,COL) == 0)
		{
			printf("玩家胜利");
			break;
		}
		if(is_win(ch,ROW,COL) == 2)
		{
			printf("平局");
			break;
		}	
		computermove(ch,ROW,COL);//电脑走
		if(is_win(ch,ROW,COL) == 1)
		{
			printf("电脑胜利");
			break;
		}
		if(is_win(ch,ROW,COL) == 2)
		{
			printf("平局");
			break;
		}//判断胜利
	}
}
void menu()
{
	printf("三子棋游戏");
	Sleep(1000);
	system("cls");
	while(1)
	{
		printf("**********************************\n");
		printf("***1.开始游戏******2.退出*********\n");
		printf("**********************************\n");
		printf("请选择>:");
		int a = 0;
		scanf("%d",&a);
		system("cls");
		if(a == 1)
		{
			game();
			
		}
		if(a == 2)
		{
			break;
		}	
		Sleep(2000);
		system("cls");
	}
	
}
int main()
{
	system("chcp 65001");
	menu();
}