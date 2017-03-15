//���ö�����
#ifndef CBo_BTBLink_c //�������Ķ�������洢��ʾ
#define CBo_BTBLink_c
#include "CBo_BTBLink.c" //���ô��ļ�
#endif // !"CBo_BTBLink_c"

//�ⲿָ�� ElemType
typedef BiTree SElemType; //�ֶ�ָ�� ElemType

//����
//#ifndef CBo_SqStack_c //˳��ջ �Ļ������� ��9����
//#define CBo_SqStack_c //#ifndef ���볬�������ˣ�����ס
//#include"CBo_SqStack.c" //���ô��ļ�
//#endif // !CBo_SqStack_c

#ifndef C_C_h //ͨ�õ�Ԥ����
#define C_C_h 
#include "C_C.h" //���ô��ļ�
#endif // !C_C_h

/* ջ��˳��洢��ʾ */
#define STACK_INIT_SIZE 10 /* �洢�ռ��ʼ������ */
#define STACKINCREMENT 2 /* �洢�ռ�������� */

typedef struct {
	SElemType *base; /* ��ջ����֮ǰ������֮��base��ֵΪNULL */
	SElemType *top; /* ջ��ָ�� */
	int stacksize; /* ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ */
}SqStack;  /* ˳��ջ */

/* ˳��ջ���洢�ṹ��c3-1.h���壩�Ļ���������9���� */
Status InitStack(SqStack *S) { /* ����һ����ջS */
	(*S).base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!(*S).base)
		exit(OVERFLOW); /* �洢����ʧ�� */
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	return OK;
}
Status DestroyStack(SqStack *S) { /* ����ջS��S���ٴ��� */
	free((*S).base);
	(*S).base = NULL;
	(*S).top = NULL;
	(*S).stacksize = 0;
	return OK;
}/* ����ջS��S���ٴ��� */

Status ClearStack(SqStack *S) {
	/* ��S��Ϊ��ջ */
	(*S).top = (*S).base;
	return OK;
}

Status StackEmpty(SqStack S) {
	/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

int StackLength(SqStack S) {
	/* ����S��Ԫ�ظ�������ջ�ĳ��� */
	return S.top - S.base;
}

Status GetTop(SqStack S, SElemType *e) {
	/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
	if (S.top > S.base) {
		*e = *(S.top - 1);
		return OK;
	} else
		return ERROR;
}

Status Push(SqStack *S, SElemType e) { /* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
	if ((*S).top - (*S).base >= (*S).stacksize) /* ջ����׷�Ӵ洢�ռ� */
	{
		(*S).base = (SElemType *)realloc((*S).base, ((*S).stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!(*S).base)
			exit(OVERFLOW); /* �洢����ʧ�� */
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	*((*S).top)++ = e;
	return OK;
}

Status Pop(SqStack *S, SElemType *e) {
	/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
	if ((*S).top == (*S).base)
		return ERROR;
	*e = *--(*S).top;
	return OK;
}

Status StackTraverse(SqStack S, Status(*visit)(SElemType)) {
	/* ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()�� */
	/* һ��visit()ʧ�ܣ������ʧ�� */
	while (S.top > S.base)
		visit(*S.base++);
	printf("\n");
	return OK;
}
#endif //!Bo_SqStack_c

