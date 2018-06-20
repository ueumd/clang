#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#define MaxSize 50
typedef struct
{
	float data[MaxSize];
	int top;
}OpStack;
typedef struct
{
	char data[MaxSize];
	int top;
}SeqStack;

void InitStack(SeqStack *S);         //初始化栈
int StackEmpty(SeqStack S);         //判断栈是否为空
int PushStack(SeqStack *S, char e);   //进栈
int PopStack(SeqStack *S, char *e);   //删除栈顶元素
int GetTop(SeqStack S, char *e);     //取栈顶元素
void TranslateExpress(char s1[], char s2[]);     //将中缀表达式转为后缀表达式
float ComputeExpress(char s[]);                 //计算后缀表达式

typedef struct BiThrNode
{
	char data;
	struct BiThrNode *lchild;
	struct BiThrNode *rchild;
	unsigned ltag;
	unsigned rtag;
}BiTNode, *BiTree;

void CreateBiTree(BiTree *T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '0')
		(*T) = NULL;
	else
	{
		(*T) = new BiTNode;
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}
//前序
void InOrderOut_1(BiTree T)
{
	if (T)
	{
		printf("%3c", T->data);
		InOrderOut_1(T->lchild);
		InOrderOut_1(T->rchild);
	}
}
//中序
void InOrderOut_2(BiTree T)
{
	if (T)
	{
		InOrderOut_2(T->lchild);
		printf("%3c", T->data);
		InOrderOut_2(T->rchild);
	}
}
//后序
void InOrderOut_3(BiTree T)
{
	if (T)
	{
		InOrderOut_3(T->lchild);
		InOrderOut_3(T->rchild);
		printf("%3c", T->data);
	}
}

void InitStack(SeqStack *S)     //初始化栈
{
	S->top = 0;
}

int StackEmpty(SeqStack S)      //判断栈是否为空
{
	if (S.top == 0)
		return 1;
	else
		return 0;
}

int PushStack(SeqStack *S, char e)   //进栈
{
	if (S->top >= MaxSize)
	{
		printf("栈已满，不能进栈!");
		return 0;
	}
	else
	{
		S->data[S->top] = e;
		S->top++;
		return 1;
	}
}

int PopStack(SeqStack *S, char *e)      //删除栈顶元素
{
	if (S->top == 0)
	{
		printf("栈已空!\n");
		return 0;
	}
	else
	{
		S->top--;
		*e = S->data[S->top];
		return 1;
	}
}

int GetTop(SeqStack S, char *e)     //取栈顶元素
{
	if (S.top <= 0)
	{
		printf("栈已空\n");
		return 0;
	}
	else
	{
		*e = S.data[S.top - 1];
		return 1;
	}
}

void TranslateExpress(char str[], char exp[])   //把中缀表达式转换为后缀表达式
{
	SeqStack S;
	char ch;
	char e;
	int i = 0, j = 0;
	InitStack(&S);
	ch = str[i];
	i++;
	while (ch != '\0')     //依次扫描中缀表达式
	{
		switch (ch)
		{
		case'(':
			PushStack(&S, ch);
			break;
		case')':
			while (GetTop(S, &e) && e != '(')
			{
				PopStack(&S, &e);
				exp[j] = e;
				j++;
			}
			PopStack(&S, &e);
			break;
		case'+':
		case'-':
			while (!StackEmpty(S) && GetTop(S, &e) && e != '(')
			{
				PopStack(&S, &e);
				exp[j] = e;
				j++;
			}
			PushStack(&S, ch);
			break;
		case'*':
		case'/':
			while (!StackEmpty(S) && GetTop(S, &e) && e == '/' || e == '*')
			{
				PopStack(&S, &e);
				exp[j] = e;
				j++;
			}
			PushStack(&S, ch);
			break;              //是空格就忽略
		case' ':
			break;
		default:
			while (ch >= '0' && ch <= '9')
			{
				exp[j] = ch;
				j++;
				ch = str[i];
				i++;
			}
			i--;
			exp[j] = ' ';
			j++;
		}
		ch = str[i];
		i++;
	}
	while (!StackEmpty(S))       //将栈中剩余运算符出栈
	{
		PopStack(&S, &e);
		exp[j] = e;
		j++;
	}
	exp[j] = '\0';
}

float ComputeExpress(char a[])     //计算后缀表达式的值
{
	OpStack S;
	int i = 0;
	float x1, x2, value;
	float result;
	S.top = -1;
	while (a[i] != '\0')            //依次扫描后缀表达式
	{
		if (a[i] != ' '&& a[i] >= '0' && a[i] <= '9')    //如果是数字
		{
			value = 0;
			while (a[i] != ' ')     //如果不是空格
			{
				value = 10 * value + a[i] - '0';
				i++;
			}
			S.top++;
			S.data[S.top] = value;    //处理后进栈
		}
		else                        //如果是运算符
		{
			switch (a[i])
			{
			case'+':
				x1 = S.data[S.top];
				S.top--;
				x2 = S.data[S.top];
				S.top--;
				result = x1 + x2;
				S.top++;
				S.data[S.top] = result;
				break;
			case'-':
				x1 = S.data[S.top];
				S.top--;
				x2 = S.data[S.top];
				S.top--;
				result = x2 - x1;
				S.top++;
				S.data[S.top] = result;
				break;
			case'*':
				x1 = S.data[S.top];
				S.top--;
				x2 = S.data[S.top];
				S.top--;
				result = x1*x2;
				S.top++;
				S.data[S.top] = result;
				break;
			case'/':
				x1 = S.data[S.top];
				S.top--;
				x2 = S.data[S.top];
				S.top--;
				result = x2 / x1;
				S.top++;
				S.data[S.top] = result;
				break;
			}
			i++;
		}
	}
	if (!S.top != -1)       //如果栈不为空，将结果出栈并返回
	{
		result = S.data[S.top];
		S.top--;
		if (S.top == -1)
			return result;
		else
		{
			printf("表达式错误!\n");
			exit(-1);
		}
	}
	return 0;
}
void main()
{
	int m;
	do
	{
		printf("     --------------------------------------------\n");
		printf("     ----                                    ----\n");
		printf("                  算术表达式求值系统             \n");
		printf("     ----                                    ----\n");
		printf("     --------------------------------------------\n");
		printf("     1.算术表达式求值    -----    2.二叉树遍历 \n\n");
		printf("     请选择操作:    ");
		scanf("%d", &m);
		switch (m)
		{
		case 1:
			char a[MaxSize], b[MaxSize];
			float f;
			printf("\n     请输入一个算术表达式: ");
			getchar();
			gets(a);
			printf("     中缀表达式为:%2s\n", a);
			TranslateExpress(a, b);
			printf("     后缀表达式为:%2s\n", b);
			f = ComputeExpress(b);
			printf("     计算结果为:%f\n", f);
			break;
		case 2:
			BiTree bt;
			printf("\n     输入所建立的二叉树：");
			getchar();
			CreateBiTree(&bt);
			printf("     前序输出为：");
			InOrderOut_1(bt);
			printf("\n");
			printf("     中序输出为：");
			InOrderOut_2(bt);
			printf("\n");
			printf("     后序输出为：");
			InOrderOut_3(bt);
			printf("\n");
			break;
		}
	} while (m != 2);


	system("pause");
}
