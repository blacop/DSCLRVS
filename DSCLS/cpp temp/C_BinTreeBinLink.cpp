#ifndef Capt_BinTreeBinLink_h 
#define Capt_BinTreeBinLink_h //�������Ķ�������洢��ʾ

typedef int TElemType; //���ͽṹ������������
typedef struct BiTNode { /* c6-2.h �������Ķ�������洢��ʾ */
	TElemType data;
	struct BiTNode *lchild, *rchild; /* ���Һ���ָ�� */
}BiTNode, *BiTree; //�������Ķ�������洢��ʾ

#endif // !Capt_BinTreeBinLink_h

