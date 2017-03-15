#ifndef C_BTBLink_h //二叉树的二叉链表存储表示
#define C_BTBLink_h 
#include "C_BTBLink.h" //引用此文件
#endif // !C_BTBLink_h

//自身
//#ifndef C_SqStack_h //栈的顺序存储表示 定义
//#define C_SqStack_h  
//#include"C_SqStack.h" //引用此文件
//#endif // !C_SqStack_h

/* c3-1.h 栈的顺序存储表示 */
typedef BiTree SElemType; //这个泛型真没法写

#define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
#define STACKINCREMENT 2 /* 存储空间分配增量 */
typedef struct SqStack {
	SElemType *base; /* 在栈构造之前和销毁之后，base的值为NULL */
	SElemType *top; /* 栈顶指针 */
	int stacksize; /* 当前已分配的存储空间，以元素为单位 */
}SqStack; /* 顺序栈 */

