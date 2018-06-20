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

void InitStack(SeqStack *S);         //��ʼ��ջ
int StackEmpty(SeqStack S);         //�ж�ջ�Ƿ�Ϊ��
int PushStack(SeqStack *S, char e);   //��ջ
int PopStack(SeqStack *S, char *e);   //ɾ��ջ��Ԫ��
int GetTop(SeqStack S, char *e);     //ȡջ��Ԫ��
void TranslateExpress(char s1[], char s2[]);     //����׺���ʽתΪ��׺���ʽ
float ComputeExpress(char s[]);                 //�����׺���ʽ

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
//ǰ��
void InOrderOut_1(BiTree T)
{
	if (T)
	{
		printf("%3c", T->data);
		InOrderOut_1(T->lchild);
		InOrderOut_1(T->rchild);
	}
}
//����
void InOrderOut_2(BiTree T)
{
	if (T)
	{
		InOrderOut_2(T->lchild);
		printf("%3c", T->data);
		InOrderOut_2(T->rchild);
	}
}
//����
void InOrderOut_3(BiTree T)
{
	if (T)
	{
		InOrderOut_3(T->lchild);
		InOrderOut_3(T->rchild);
		printf("%3c", T->data);
	}
}

void InitStack(SeqStack *S)     //��ʼ��ջ
{
	S->top = 0;
}

int StackEmpty(SeqStack S)      //�ж�ջ�Ƿ�Ϊ��
{
	if (S.top == 0)
		return 1;
	else
		return 0;
}

int PushStack(SeqStack *S, char e)   //��ջ
{
	if (S->top >= MaxSize)
	{
		printf("ջ���������ܽ�ջ!");
		return 0;
	}
	else
	{
		S->data[S->top] = e;
		S->top++;
		return 1;
	}
}

int PopStack(SeqStack *S, char *e)      //ɾ��ջ��Ԫ��
{
	if (S->top == 0)
	{
		printf("ջ�ѿ�!\n");
		return 0;
	}
	else
	{
		S->top--;
		*e = S->data[S->top];
		return 1;
	}
}

int GetTop(SeqStack S, char *e)     //ȡջ��Ԫ��
{
	if (S.top <= 0)
	{
		printf("ջ�ѿ�\n");
		return 0;
	}
	else
	{
		*e = S.data[S.top - 1];
		return 1;
	}
}

void TranslateExpress(char str[], char exp[])   //����׺���ʽת��Ϊ��׺���ʽ
{
	SeqStack S;
	char ch;
	char e;
	int i = 0, j = 0;
	InitStack(&S);
	ch = str[i];
	i++;
	while (ch != '\0')     //����ɨ����׺���ʽ
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
			break;              //�ǿո�ͺ���
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
	while (!StackEmpty(S))       //��ջ��ʣ���������ջ
	{
		PopStack(&S, &e);
		exp[j] = e;
		j++;
	}
	exp[j] = '\0';
}

float ComputeExpress(char a[])     //�����׺���ʽ��ֵ
{
	OpStack S;
	int i = 0;
	float x1, x2, value;
	float result;
	S.top = -1;
	while (a[i] != '\0')            //����ɨ���׺���ʽ
	{
		if (a[i] != ' '&& a[i] >= '0' && a[i] <= '9')    //���������
		{
			value = 0;
			while (a[i] != ' ')     //������ǿո�
			{
				value = 10 * value + a[i] - '0';
				i++;
			}
			S.top++;
			S.data[S.top] = value;    //������ջ
		}
		else                        //����������
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
	if (!S.top != -1)       //���ջ��Ϊ�գ��������ջ������
	{
		result = S.data[S.top];
		S.top--;
		if (S.top == -1)
			return result;
		else
		{
			printf("���ʽ����!\n");
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
		printf("                  �������ʽ��ֵϵͳ             \n");
		printf("     ----                                    ----\n");
		printf("     --------------------------------------------\n");
		printf("     1.�������ʽ��ֵ    -----    2.���������� \n\n");
		printf("     ��ѡ�����:    ");
		scanf("%d", &m);
		switch (m)
		{
		case 1:
			char a[MaxSize], b[MaxSize];
			float f;
			printf("\n     ������һ���������ʽ: ");
			getchar();
			gets(a);
			printf("     ��׺���ʽΪ:%2s\n", a);
			TranslateExpress(a, b);
			printf("     ��׺���ʽΪ:%2s\n", b);
			f = ComputeExpress(b);
			printf("     ������Ϊ:%f\n", f);
			break;
		case 2:
			BiTree bt;
			printf("\n     �����������Ķ�������");
			getchar();
			CreateBiTree(&bt);
			printf("     ǰ�����Ϊ��");
			InOrderOut_1(bt);
			printf("\n");
			printf("     �������Ϊ��");
			InOrderOut_2(bt);
			printf("\n");
			printf("     �������Ϊ��");
			InOrderOut_3(bt);
			printf("\n");
			break;
		}
	} while (m != 2);


	system("pause");
}
