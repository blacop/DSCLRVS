#ifndef C_BTBLink_h //�������Ķ�������洢��ʾ
#define C_BTBLink_h 
#include "C_BTBLink.h" //���ô��ļ�
#endif // !C_BTBLink_h

//����
//#ifndef C_SqStack_h //ջ��˳��洢��ʾ ����
//#define C_SqStack_h  
//#include"C_SqStack.h" //���ô��ļ�
//#endif // !C_SqStack_h

/* c3-1.h ջ��˳��洢��ʾ */
typedef BiTree SElemType; //���������û��д

#define STACK_INIT_SIZE 10 /* �洢�ռ��ʼ������ */
#define STACKINCREMENT 2 /* �洢�ռ�������� */
typedef struct SqStack {
	SElemType *base; /* ��ջ����֮ǰ������֮��base��ֵΪNULL */
	SElemType *top; /* ջ��ָ�� */
	int stacksize; /* ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ */
}SqStack; /* ˳��ջ */

