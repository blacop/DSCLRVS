//引用二叉树
#ifndef CBo_BTBLink_c //二叉树的二叉链表存储表示
#define CBo_BTBLink_c
#include "CBo_BTBLink.c" //引用此文件
#endif // !"CBo_BTBLink_c"

//外部指定 ElemType
typedef BiTree SElemType; //手动指定 ElemType

//自身
//#ifndef CBo_SqStack_c //顺序栈 的基本操作 （9个）
//#define CBo_SqStack_c //#ifndef 代码超过长度了，包不住
//#include"CBo_SqStack.c" //引用此文件
//#endif // !CBo_SqStack_c

#ifndef C_C_h //通用的预定义
#define C_C_h 
#include "C_C.h" //引用此文件
#endif // !C_C_h

/* 栈的顺序存储表示 */
#define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
#define STACKINCREMENT 2 /* 存储空间分配增量 */

typedef struct {
	SElemType *base; /* 在栈构造之前和销毁之后，base的值为NULL */
	SElemType *top; /* 栈顶指针 */
	int stacksize; /* 当前已分配的存储空间，以元素为单位 */
}SqStack;  /* 顺序栈 */

/* 顺序栈（存储结构由c3-1.h定义）的基本操作（9个） */
Status InitStack(SqStack *S) { /* 构造一个空栈S */
	(*S).base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!(*S).base)
		exit(OVERFLOW); /* 存储分配失败 */
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	return OK;
}
Status DestroyStack(SqStack *S) { /* 销毁栈S，S不再存在 */
	free((*S).base);
	(*S).base = NULL;
	(*S).top = NULL;
	(*S).stacksize = 0;
	return OK;
}/* 销毁栈S，S不再存在 */

Status ClearStack(SqStack *S) {
	/* 把S置为空栈 */
	(*S).top = (*S).base;
	return OK;
}

Status StackEmpty(SqStack S) {
	/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

int StackLength(SqStack S) {
	/* 返回S的元素个数，即栈的长度 */
	return S.top - S.base;
}

Status GetTop(SqStack S, SElemType *e) {
	/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
	if (S.top > S.base) {
		*e = *(S.top - 1);
		return OK;
	} else
		return ERROR;
}

Status Push(SqStack *S, SElemType e) { /* 插入元素e为新的栈顶元素 */
	if ((*S).top - (*S).base >= (*S).stacksize) /* 栈满，追加存储空间 */
	{
		(*S).base = (SElemType *)realloc((*S).base, ((*S).stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!(*S).base)
			exit(OVERFLOW); /* 存储分配失败 */
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	*((*S).top)++ = e;
	return OK;
}

Status Pop(SqStack *S, SElemType *e) {
	/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
	if ((*S).top == (*S).base)
		return ERROR;
	*e = *--(*S).top;
	return OK;
}

Status StackTraverse(SqStack S, Status(*visit)(SElemType)) {
	/* 从栈底到栈顶依次对栈中每个元素调用函数visit()。 */
	/* 一旦visit()失败，则操作失败 */
	while (S.top > S.base)
		visit(*S.base++);
	printf("\n");
	return OK;
}
#endif //!Bo_SqStack_c

