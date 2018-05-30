#include <stdio.h>
#include <time.h>   
#include <conio.h>   
#include <windows.h>
void start_game(); // 开始游戏 
void reset_game(); // 重置游戏 

void move_left();
void move_right();
void move_up();
void move_down();

void refresh_show();    // 刷新界面显示
void add_rand_num();    // 生成随机数，本程序中仅生成2或4，概率之比设为2:1
void check_game_over(); // 检测是否输掉游戏，设定游戏结束标志
int get_null_count();   // 获取游戏面板上空位置数量 
void color(int m);
int board[4][4];     // 游戏数字面板，抽象为二维数组 
int score;           // 游戏的分 
int if_need_add_num; // 是否需要生成随机数标志，1表示需要，0表示不需要
int if_game_over;    // 是否游戏结束标志，1表示游戏结束，0表示正常

int main()
{
	start_game();
}

// 开始游戏 函数定义
void start_game()
{
	reset_game();
	char cmd;
	while (1)
	{
		cmd = getch(); // 接收标准输入流字符命令

		if (if_game_over) // 判断是否已经输掉游戏
		{
			if (cmd == 'y' || cmd == 'Y') // 重玩游戏
			{
				reset_game();
				continue;
			}
			else if (cmd == 'n' || cmd == 'N') // 退出
			{
				return;
			}
			else
			{
				continue;
			}
		}

		if_need_add_num = 0; // 先设定不默认需要生成随机数，需要时再设定为 1

		switch (cmd) // 命令解析 w，s，a，d 字符代表上下左右命令
		{
		case 'a':
		case 'A':
		case 75:
			move_left();
			break;
		case 's':
		case 'S':
		case 80:
			move_down();
			break;
		case 'w':
		case 'W':
		case 72:
			move_up();
			break;
		case 'd':
		case 'D':
		case 77:
			move_right();
			break;
		}
		if (if_need_add_num) //默认为需要生成随机数时也同时需要刷新显示，反之亦然 
		{
			add_rand_num();
			refresh_show();
		}
	}
}

//重置游戏 函数定义
void reset_game()
{
	score = 0;
	if_need_add_num = 1;
	if_game_over = 0;

	// 了解到游戏初始化时出现的两个数一定会有个 2，所以先随机生成一个 2，其他均为 0 
	int n = rand() % 16;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[i][j] = (n-- == 0 ? 2 : 0);
		}
	}

	// 前面已经生成了一个2，这里再生成一个随机的2或者4，且设定生成2的概率是4的两倍
	add_rand_num();

	// 在这里刷新界面并显示的时候，界面上已经默认出现了两个数字，其他的都为空（值为0）
	system("cls");
	refresh_show();
}

// 生成随机数 函数定义
void add_rand_num()
{
	srand(time(0));
	int n = rand() % get_null_count();// 确定在何处空位置生成随机数
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == 0)
			{
				if (n-- == 0) {//定位待生成的位置
					board[i][j] = (rand() % 3 ? 2 : 4);//rand() % 3的值为真（1或2）取前值2，反之，取 4 ，保证生成 2 的概率是 4 的 2 倍
					return;
				}
			}
		}
	}
}
// 获取空位置数量 函数定义
int get_null_count()
{
	int n = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[i][j] == 0 ? n++ : 1;
		}
	}
	return n;
}
// 检查游戏是否结束 函数定义
void check_game_over()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// 横向和纵向比较挨着的两个元素是否相等，若有相等则游戏不结束
			if (board[i][j] == board[i][j + 1] || board[j][i] == board[j + 1][i])
			{
				if_game_over = 0;
				return;
			}
		}
	}
	if_game_over = 1;
}

/*
* 如下四个函数，实现上下左右移动时数字面板的变化算法
* 左和右移动的本质一样，区别仅仅是列项的遍历方向相反
* 上和下移动的本质一样，区别仅仅是行项的遍历方向相反
* 左和上移动的本质也一样，区别仅仅是遍历时行和列互换
*/

// 左移 函数定义
void move_left()
{
	// 变量i用来遍历行项的下标，并且在移动时所有行相互独立，互不影响
	for (int i = 0; i < 4; i++)
	{
		// 变量j为列下标，变量k为待比较（合并）项的下标，循环进入时k<j 
		for (int j = 1, k = 0; j < 4; j++)
		{
			if (board[i][j] > 0) // 找出k后面第一个不为空的项，下标为j，之后分三种情况
			{
				if (board[i][k] == board[i][j]) // 情况1：k项和j项相等，此时合并方块并计分
				{
					score += board[i][k++] <<= 1;//相当于score += board[i][k++] * 2;
					board[i][j] = 0;
					if_need_add_num = 1; // 需要生成随机数和刷新界面
				}
				else if (board[i][k] == 0) // 情况2：k项为空，则把j项赋值给k项，相当于j方块移动到k方块
				{
					board[i][k] = board[i][j];
					board[i][j] = 0;
					if_need_add_num = 1;
				}
				else // 情况3：k项不为空，且和j项不相等，此时把j项赋值给k+1项，相当于移动到k+1的位置 
				{
					board[i][++k] = board[i][j];
					if (j != k) // 判断j项和k项是否原先就挨在一起，若不是则把j项赋值为空（值为0）
					{
						board[i][j] = 0;
						if_need_add_num = 1;
					}
				}
			}
		}
	}
}
// 上移 函数定义 
void move_up()
{
	// 仿照左移操作，区别仅仅是行列互换后遍历
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1, k = 0; j < 4; j++)
		{
			if (board[j][i] > 0)
			{
				if (board[k][i] == board[j][i])
				{
					score += board[k++][i] <<= 1;
					board[j][i] = 0;
					if_need_add_num = 1;
				}
				else if (board[k][i] == 0)
				{
					board[k][i] = board[j][i];
					board[j][i] = 0;
					if_need_add_num = 1;
				}
				else
				{
					board[++k][i] = board[j][i];
					if (j != k)
					{
						board[j][i] = 0;
						if_need_add_num = 1;
					}
				}
			}
		}
	}
}
// 右移 函数定义 
void move_right()
{
	// 仿照左移操作，区别仅仅是j和k都反向遍历
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2, k = 3; j >= 0; j--)
		{
			if (board[i][j] > 0)
			{
				if (board[i][k] == board[i][j])
				{
					score += board[i][k--] <<= 1;
					board[i][j] = 0;
					if_need_add_num = 1;
				}
				else if (board[i][k] == 0)
				{
					board[i][k] = board[i][j];
					board[i][j] = 0;
					if_need_add_num = 1;
				}
				else
				{
					board[i][--k] = board[i][j];
					if (j != k)
					{
						board[i][j] = 0;
						if_need_add_num = 1;
					}
				}
			}
		}
	}
}
// 下移 函数定义
void move_down()
{
	// 仿照左移操作，区别仅仅是行列互换后遍历，且j和k都反向遍历
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2, k = 3; j >= 0; j--)
		{
			if (board[j][i] > 0)
			{
				if (board[k][i] == board[j][i])
				{
					score += board[k--][i] <<= 1;
					board[j][i] = 0;
					if_need_add_num = 1;
				}
				else if (board[k][i] == 0)
				{
					board[k][i] = board[j][i];
					board[j][i] = 0;
					if_need_add_num = 1;
				}
				else
				{
					board[--k][i] = board[j][i];
					if (j != k)
					{
						board[j][i] = 0;
						if_need_add_num = 1;
					}
				}
			}
		}
	}
}


// 刷新界面 函数定义
void refresh_show()
{
	// 重设光标输出位置方式清屏可以减少闪烁，system("cls")为备用清屏命令，均为Windows平台相关
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	printf("\n\n\n\n");
	color(3);
	printf("                游戏名: 2048                     分数: %06d\n", score);
	printf("             --------------------------------------------------\n\n");

	// 绘制表格和数字
	printf("                        ┌──┬──┬──┬──┐\n");
	for (int i = 0; i < 4; i++)
	{
		printf("                        │");
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] != 0)
			{
				if (board[i][j] < 10)
				{
					color(2);
					printf("  %d ", board[i][j]);
				}
				else if (board[i][j] < 100)
				{
					color(0xA);
					printf(" %d ", board[i][j]);
				}
				else if (board[i][j] < 1000)
				{
					color(0xE);
					printf(" %d", board[i][j]);
				}
				else if (board[i][j] < 10000)
				{
					color(2);
					printf("%4d", board[i][j]);
				}
				else
				{
					int n = board[i][j];
					for (int k = 1; k < 20; k++)
					{
						n >>= 1;
						if (n == 1)
						{
							printf("2^%02d", k); // 超过四位的数字用2的幂形式表示，如2^13形式 
							break;
						}
					}
				}
				color(3);
				printf("│");
			}
			else {
				color(3);
				printf("    │");
			}
		}
		color(3);
		if (i < 3)
		{
			printf("\n                        ├──┼──┼──┼──┤\n");
		}
		else
		{
			printf("\n                        └──┴──┴──┴──┘\n");
		}
	}

	printf("\n");
	printf("             --------------------------------------------------\n");
	color(6);
	printf("                            W↑  A←  →D  ↓S");

	if (get_null_count() == 0)
	{
		check_game_over();
		if (if_game_over) //判断是否输掉游戏
		{
			color(4);
			printf("\r                    游戏结束，重新开始游戏[Y/N]");
		}
	}
}
void color(int m) {
	HANDLE consolehend;
	consolehend = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consolehend, m);
}