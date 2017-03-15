//自身
//#ifndef C_LQueue_h //单链队列 存储结构 定义
//#define C_LQueue_h 
//#include"C_LQueue.h"
//#endif //!C_LQueue_h

/* c3-2.h 单链队列－－队列的链式存储结构 定义 */

#ifndef C_BTBLink_h //二叉树的二叉链表存储表示
#define C_BTBLink_h 
#include "C_BTBLink.h" //引用此文件
#endif // !C_BTBLink_h

typedef BiTree QElemType; //这个泛型真没法写

typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front, rear; /* 队头、队尾指针 */
}LinkQueue;


