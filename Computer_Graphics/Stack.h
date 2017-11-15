#pragma once

#include "stdafx.h"

//�������״̬���� 
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int ElemType;

// Define pixel type
typedef struct
{
	int x;	// x coordinate
	int y;	// y coordinate
	int color;	// color
}PixelType;

typedef PixelType SElemType;	// The PixelType

typedef struct
{
	SElemType *base;    //��ջ����֮ǰ������֮��base��ֵΪNULL
	SElemType *top;     //ջ��ָ��
	int stacksize;      //��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;

//����һ����ջ
inline ElemType InitStack(SqStack &S)
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

//����Ԫ��eΪ�µ�ջ��Ԫ��
inline ElemType Push(SqStack &S, SElemType e)
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

//��ջ���գ�ɾ��S��ջ��Ԫ�أ���e������ֵ
inline ElemType Pop(SqStack &S, SElemType &e)
{
	if (S.top == S.base)
	{
		e.x = ERROR;
		e.y = ERROR;
		e.color = ERROR;
		cout << "ERROR: stack read violently!" << endl;
		return ERROR;
	}
	else e = *--S.top;
	return OK;
}

//��ʾ˳��ջԪ��ֵ
inline void StackTraverse(SqStack S)
{
	while (S.top != S.base)
	{
		cout << "(" << S.base->x << ", " << S.base->y << "), color: " << S.base->color << endl;
		++S.base;
	}
	printf("\n");
}

//��ջ���˳��ջԪ��ֵ
inline void Stackoutput(SqStack &S)
{
	SElemType e;
	while (S.top != S.base)
	{
		Pop(S, e);
		cout << "(" << e.x << ", " << e.y << "), color: " << e.color << endl;
	}
	printf("\n");
}

//inline ElemType Correct(SElemType str[]) {
//	//ʹ�������ջS��������'('��'['ʱ��ջ������')'��']'��ջ���жϳ�ջԪ���Ƿ�Ϊ��Ӧ�ķ��ţ�
//	//�����������һ���������㷨����
//	SqStack S;
//	InitStack(S);      // �����ջ
//	int i, state = 1;
//	SElemType e;
//	for (i = 0; str[i] != '\0'; i++)
//	{
//		switch (str[i])
//		{
//		case '(':Push(S, '('); break;
//		case '[':Push(S, '['); break;
//		case ')':
//			Pop(S, e);
//			if (e != '(')
//				state = 0; break;
//		case ']':
//			Pop(S, e);
//			if (e != '[')
//				state = 0; break;
//		}
//		if (!state) break;//if(state==0) break;
//	}
//	if (S.top == S.base&& state == 1)
//		return OK;
//	else
//		return ERROR;
//}//Correct


// The test function

inline void StackTest()
{
	int n, x, y;
	int color;
	SElemType e;
	SqStack S;
	e.x = e.y = -1;	// Initial
	InitStack(S);
	cout << "Please enter n:" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		e.x = i * 100;	e.y = i * 99;
		e.color = RED;
		Push(S, e);
	}
	cout << "���˳��ջԪ��ֵ" << endl;
	StackTraverse(S);
	cout << "\n��ջ���˳��ջԪ��ֵ" << endl;
	Stackoutput(S);
	getch();
}