//����
//#ifndef C_BTBLink_h //�������Ķ�������洢��ʾ
//#define C_BTBLink_h 
//#include "C_BTBLink.h" //���ô��ļ�
//#endif // !C_BTBLink_h

typedef int TElemType; //�������ṹ �� ����������
typedef struct BiTNode { /* c6-2.h �������Ķ�������洢��ʾ */
	TElemType data;
	struct BiTNode *lchild, *rchild; /* ���Һ���ָ�� */
}BiTNode, *BiTree; //�������Ķ�������洢��ʾ

