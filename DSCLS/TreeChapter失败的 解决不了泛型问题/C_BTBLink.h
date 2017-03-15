//自身
//#ifndef C_BTBLink_h //二叉树的二叉链表存储表示
//#define C_BTBLink_h 
//#include "C_BTBLink.h" //引用此文件
//#endif // !C_BTBLink_h

typedef int TElemType; //二叉树结构 的 数据域类型
typedef struct BiTNode { /* c6-2.h 二叉树的二叉链表存储表示 */
	TElemType data;
	struct BiTNode *lchild, *rchild; /* 左右孩子指针 */
}BiTNode, *BiTree; //二叉树的二叉链表存储表示

