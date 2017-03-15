#ifndef Capt_BinTreeBinLink_h 
#define Capt_BinTreeBinLink_h //二叉树的二叉链表存储表示

typedef int TElemType; //泛型结构的数据域类型
typedef struct BiTNode { /* c6-2.h 二叉树的二叉链表存储表示 */
	TElemType data;
	struct BiTNode *lchild, *rchild; /* 左右孩子指针 */
}BiTNode, *BiTree; //二叉树的二叉链表存储表示

#endif // !Capt_BinTreeBinLink_h

