#ifndef Capt_LinkQueue_h //�������� �洢�ṹ ����
#define Capt_LinkQueue_h
//#include"Capt_LinkQueue.h"
/* c3-2.h �������У������е���ʽ�洢�ṹ ���� */
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front, rear; /* ��ͷ����βָ�� */
}LinkQueue;
#endif //!Capt_LinkQueue_h
