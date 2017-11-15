#pragma once

#include "stdafx.h"

//函数结果状态代码 
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
	SElemType *base;    //在栈构造之前和销毁之后，base的值为NULL
	SElemType *top;     //栈顶指针
	int stacksize;      //当前已分配的存储空间，以元素为单位
}SqStack;

//构造一个空栈
inline ElemType InitStack(SqStack &S)
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

//插入元素e为新的栈顶元素
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

//若栈不空，删除S的栈顶元素，用e返回其值
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

//显示顺序栈元素值
inline void StackTraverse(SqStack S)
{
	while (S.top != S.base)
	{
		cout << "(" << S.base->x << ", " << S.base->y << "), color: " << S.base->color << endl;
		++S.base;
	}
	printf("\n");
}

//弹栈输出顺序栈元素值
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
//	//使用运算符栈S，当遇到'('、'['时进栈，遇到')'、']'出栈并判断出栈元素是否为相应的符号，
//	//若是则继续下一个，否则算法结束
//	SqStack S;
//	InitStack(S);      // 构造空栈
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
	cout << "输出顺序栈元素值" << endl;
	StackTraverse(S);
	cout << "\n弹栈输出顺序栈元素值" << endl;
	Stackoutput(S);
	getch();
}