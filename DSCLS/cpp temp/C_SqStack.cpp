#ifndef C_SqStack_h 
#define C_SqStack_h //ջ��˳��洢��ʾ

//#include"C_SqStack.h" //���ô��ļ�
/* c3-1.h ջ��˳��洢��ʾ */

#define STACK_INIT_SIZE 10 /* �洢�ռ��ʼ������ */
#define STACKINCREMENT 2 /* �洢�ռ�������� */
typedef void* SElemType; //���������û��д
template <typename SElemType> //����QElemType
typedef struct SqStack {
	SElemType *base; /* ��ջ����֮ǰ������֮��base��ֵΪNULL */
	SElemType *top; /* ջ��ָ�� */
	int stacksize; /* ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ */
}SqStack; /* ˳��ջ */

#endif // !C_SqStack_h