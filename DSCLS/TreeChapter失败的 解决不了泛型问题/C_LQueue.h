//����
//#ifndef C_LQueue_h //�������� �洢�ṹ ����
//#define C_LQueue_h 
//#include"C_LQueue.h"
//#endif //!C_LQueue_h

/* c3-2.h �������У������е���ʽ�洢�ṹ ���� */

#ifndef C_BTBLink_h //�������Ķ�������洢��ʾ
#define C_BTBLink_h 
#include "C_BTBLink.h" //���ô��ļ�
#endif // !C_BTBLink_h

typedef BiTree QElemType; //���������û��д

typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front, rear; /* ��ͷ����βָ�� */
}LinkQueue;


