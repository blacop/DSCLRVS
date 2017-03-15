#ifndef Capt_LinkQueue_h //单链队列 存储结构 定义
#define Capt_LinkQueue_h

//#include"Capt_LinkQueue.h"
/* c3-2.h 单链队列－－队列的链式存储结构 定义 */
//typedef void* QElemType; //这个泛型真没法写
template <typename QElemType> //泛型QElemType
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front, rear; /* 队头、队尾指针 */
}LinkQueue;

#endif //!Capt_LinkQueue_h
