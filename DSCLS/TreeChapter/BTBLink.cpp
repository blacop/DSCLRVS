//#ifndef 说明
//这样一个工程文件里同时包含两个test.h时，就不会出现重定义的错误了。
//分析:
//当第一次包含test.h时，由于没有定义_TEST_H，条件为真，这样就会包含（执行）#ifndef _TEST_H和
//#endif之间的代码，当第二次包含test.h时前面一次已经定义了_TEST_H，条件为假，#ifndef _TEST_H和
//#endif之间的代码也就不会再次被包含，这样就避免了重定义了.
//还是把头文件的内容都放在#ifndef和#endif中吧。不管你的头文件会不会被多个文件引用，你都要加上这个。一般格式是这样的：

/* bo6-2.c 二叉树的二叉链表存储(存储结构由c6-2.h定义)的基本操作(22个) */
#ifndef _CMD_H //通用定义
#define _CMD_H //一般是文件名的大写 头文件结尾写上一行：
#include<string.h> //c1.h (程序名)
#include<ctype.h>
#include<malloc.h> /* malloc()等 */
#include<limits.h> /* INT_MAX等 */
#include<stdio.h> /* EOF(=^Z或F6),NULL */
#include<stdlib.h> /* atoi() */
#include<io.h> /* eof() */
#include<math.h> /* floor(),ceil(),abs() */
#include<process.h> /* exit() */
#define TRUE 1 /* 函数结果状态代码 */
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE  -1
typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */
#endif // //通用定义

#ifndef _BTBLink_H //二叉树的二叉链表存储表示
#define _BTBLink_H 
//#include "BTBLink.H";
typedef int TElemType; //泛型结构的数据域类型
typedef struct BiTNode { /* 二叉树的二叉链表存储表示 */
	TElemType data;
	struct BiTNode *lchild, *rchild; /* 左右孩子指针 */
}BiTNode, *BiTree; //二叉树的二叉链表存储表示
#endif //二叉树的二叉链表存储表示

//#ifndef _Nil_H //定义Nil为空的二叉树 //不能定义为类型
//#define _Nil_H
//#define Nil BiTreeEmpty(BiTree T)
//#endif //定义Nil为空的二叉树

//#define Nil BiTreeEmpty(BiTree T) //不能定义为类型
//typedef bool Nil; //不能定义为类型
#define Nil TRUE //具体应该调用 BiTreeEmpty(BiTree T) 函数。这里做个简化

//#ifndef Nil_H //直接运行语句，Nil做成变量
//#define Nil_H
//BiTree T; //实际这里的 BiTree T 还有问题，引用 T 应该从函数外部传入，不应该在内部生成
//bool Nil = BiTreeEmpty(T); //这样写会报错
//#else 
////程序段2
//#endif //直接运行语句，Nil做成变量

Status InitBiTree(BiTree *T) { /* 操作结果: 构造空二叉树T */
	*T = NULL;
	return OK;
}//构造空二叉树
void DestroyBiTree(BiTree *T) { //销毁二叉树
	/* 初始条件: 二叉树T存在。操作结果: 销毁二叉树T */	
	if (*T) /* 非空树 */
	{
		if ((*T)->lchild) /* 有左孩子 */
			DestroyBiTree(&(*T)->lchild); /* 销毁左孩子子树 */
		if ((*T)->rchild) /* 有右孩子 */
			DestroyBiTree(&(*T)->rchild); /* 销毁右孩子子树 */
		free(*T); /* 释放根结点 */
		*T = NULL; /* 空指针赋0 */
	}
}//销毁二叉树
void CreateBiTree(BiTree *T) { //构造二叉链表表示的二叉树T
	/* 算法6.4:按先序次序输入二叉树中结点的值（可为字符型或整型，在主程中 */
	/* 定义），构造二叉链表表示的二叉树T。变量Nil表示空（子）树。有改动 */
	TElemType ch;
#ifdef CHAR
	scanf("%c", &ch);
#endif
#ifdef INT
	scanf("%d", &ch);
#endif
	if (ch == Nil) /* 空 */
		*T = NULL;
	else {
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
			exit(OVERFLOW);
		(*T)->data = ch; /* 生成根结点 */
		CreateBiTree(&(*T)->lchild); /* 构造左子树 */
		CreateBiTree(&(*T)->rchild); /* 构造右子树 */
	}
}////构造二叉链表表示的二叉树T

Status BiTreeEmpty(BiTree T) { //二叉树T为空
	/* 初始条件: 二叉树T存在 */							  
	/* 操作结果: 若T为空二叉树,则返回TRUE,否则FALSE */
	if (T)
		return FALSE;
	else
		return TRUE;
}//二叉树T为空

#define ClearBiTree DestroyBiTree

int BiTreeDepth(BiTree T) { /* 初始条件: 二叉树T存在。操作结果: 返回T的深度 */
	int i, j;
	if (!T)
		return 0;
	if (T->lchild)
		i = BiTreeDepth(T->lchild);
	else
		i = 0;
	if (T->rchild)
		j = BiTreeDepth(T->rchild);
	else
		j = 0;
	return i > j ? i + 1 : j + 1;
}

TElemType Root(BiTree T) { /* 初始条件: 二叉树T存在。操作结果: 返回T的根 */
	if (BiTreeEmpty(T))
		return Nil;
	else
		return T->data;
}

TElemType Value(BiTree p) { 
	/* 初始条件: 二叉树T存在，p指向T中某个结点 */							
	/* 操作结果: 返回p所指结点的值 */
	return p->data;
}

void Assign(BiTree p, TElemType value) { /* 给p所指结点赋值为value */
	p->data = value;
}

typedef BiTree QElemType; /* 设队列元素为二叉树的指针类型 */

#ifndef QueueLink_H //单链队列 存储结构 定义
#define QueueLink_H
//#include"c3-2.h"
/* c3-2.h 单链队列－－队列的链式存储结构 定义 */
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front, rear; /* 队头、队尾指针 */
}LinkQueue;
#endif //QueueLink_H

#ifndef QueueLink_Body//单链队列 存储结构 操作方法 实现
#define QueueLink_Body
//#include"bo3-2.c"
/* bo3-2.c 链队列(存储结构由c3-2.h定义)的基本操作(9个) */
Status InitQueue(LinkQueue *Q) { /* 构造一个空队列Q */
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if (!(*Q).front)
		exit(OVERFLOW);
	(*Q).front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue *Q) { /* 销毁队列Q(无论空否均可) */
	while ((*Q).front) {
		(*Q).rear = (*Q).front->next;
		free((*Q).front);
		(*Q).front = (*Q).rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue *Q) { /* 将Q清为空队列 */
	QueuePtr p, q;
	(*Q).rear = (*Q).front;
	p = (*Q).front->next;
	(*Q).front->next = NULL;
	while (p) {
		q = p;
		p = p->next;
		free(q);
	}
	return OK;
}

Status QueueEmpty(LinkQueue Q) { /* 若Q为空队列,则返回TRUE,否则返回FALSE */
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

int QueueLength(LinkQueue Q) { /* 求队列的长度 */
	int i = 0;
	QueuePtr p;
	p = Q.front;
	while (Q.rear != p) {
		i++;
		p = p->next;
	}
	return i;
}

Status GetHead_Q(LinkQueue Q, QElemType *e) /* 避免与bo2-6.c重名 */
{ /* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->data;
	return OK;
}

Status EnQueue(LinkQueue *Q, QElemType e) { /* 插入元素e为Q的新的队尾元素 */
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) /* 存储分配失败 */
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	(*Q).rear->next = p;
	(*Q).rear = p;
	return OK;
}

Status DeQueue(LinkQueue *Q, QElemType *e) { /* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
	QueuePtr p;
	if ((*Q).front == (*Q).rear)
		return ERROR;
	p = (*Q).front->next;
	*e = p->data;
	(*Q).front->next = p->next;
	if ((*Q).rear == p)
		(*Q).rear = (*Q).front;
	free(p);
	return OK;
}

Status QueueTraverse(LinkQueue Q, void(*vi)(QElemType)) { /* 从队头到队尾依次对队列Q中每个元素调用函数vi()。一旦vi失败,则操作失败 */
	QueuePtr p;
	p = Q.front->next;
	while (p) {
		vi(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
#endif //QueueLink_Body
//正文---
TElemType Parent(BiTree T, TElemType e) { /* 初始条件: 二叉树T存在,e是T中某个结点 */
										  /* 操作结果: 若e是T的非根结点,则返回它的双亲,否则返回＂空＂ */
	LinkQueue q;
	QElemType a;
	if (T) /* 非空树 */
	{
		InitQueue(&q); /* 初始化队列 */
		EnQueue(&q, T); /* 树根入队 */
		while (!QueueEmpty(q)) /* 队不空 */
		{
			DeQueue(&q, &a); /* 出队,队列元素赋给a */
			if (a->lchild&&a->lchild->data == e || a->rchild&&a->rchild->data == e)
				/* 找到e(是其左或右孩子) */
				return a->data; /* 返回e的双亲的值 */
			else /* 没找到e,则入队其左右孩子指针(如果非空) */
			{
				if (a->lchild)
					EnQueue(&q, a->lchild);
				if (a->rchild)
					EnQueue(&q, a->rchild);
			}
		}
	}
	return Nil; /* 树空或没找到e */
}

BiTree Point(BiTree T, TElemType s) { /* 返回二叉树T中指向元素值为s的结点的指针。另加 */
	LinkQueue q;
	QElemType a;
	if (T) /* 非空树 */
	{
		InitQueue(&q); /* 初始化队列 */
		EnQueue(&q, T); /* 根结点入队 */
		while (!QueueEmpty(q)) /* 队不空 */
		{
			DeQueue(&q, &a); /* 出队,队列元素赋给a */
			if (a->data == s)
				return a;
			if (a->lchild) /* 有左孩子 */
				EnQueue(&q, a->lchild); /* 入队左孩子 */
			if (a->rchild) /* 有右孩子 */
				EnQueue(&q, a->rchild); /* 入队右孩子 */
		}
	}
	return NULL;
}

TElemType LeftChild(BiTree T, TElemType e) { /* 初始条件: 二叉树T存在,e是T中某个结点 */
											 /* 操作结果: 返回e的左孩子。若e无左孩子,则返回＂空＂ */
	BiTree a;
	if (T) /* 非空树 */
	{
		a = Point(T, e); /* a是结点e的指针 */
		if (a&&a->lchild) /* T中存在结点e且e存在左孩子 */
			return a->lchild->data; /* 返回e的左孩子的值 */
	}
	return Nil; /* 其余情况返回空 */
}

TElemType RightChild(BiTree T, TElemType e) { /* 初始条件: 二叉树T存在,e是T中某个结点 */
											  /* 操作结果: 返回e的右孩子。若e无右孩子,则返回＂空＂ */
	BiTree a;
	if (T) /* 非空树 */
	{
		a = Point(T, e); /* a是结点e的指针 */
		if (a&&a->rchild) /* T中存在结点e且e存在右孩子 */
			return a->rchild->data; /* 返回e的右孩子的值 */
	}
	return Nil; /* 其余情况返回空 */
}

TElemType LeftSibling(BiTree T, TElemType e) { /* 初始条件: 二叉树T存在,e是T中某个结点 */
											   /* 操作结果: 返回e的左兄弟。若e是T的左孩子或无左兄弟,则返回＂空＂ */
	TElemType a;
	BiTree p;
	if (T) /* 非空树 */
	{
		a = Parent(T, e); /* a为e的双亲 */
		p = Point(T, a); /* p为指向结点a的指针 */
		if (p->lchild&&p->rchild&&p->rchild->data == e) /* p存在左右孩子且右孩子是e */
			return p->lchild->data; /* 返回p的左孩子(e的左兄弟) */
	}
	return Nil; /* 树空或没找到e的左兄弟 */
}

TElemType RightSibling(BiTree T, TElemType e) { /* 初始条件: 二叉树T存在,e是T中某个结点 */
												/* 操作结果: 返回e的右兄弟。若e是T的右孩子或无右兄弟,则返回＂空＂ */
	TElemType a;
	BiTree p;
	if (T) /* 非空树 */
	{
		a = Parent(T, e); /* a为e的双亲 */
		p = Point(T, a); /* p为指向结点a的指针 */
		if (p->lchild&&p->rchild&&p->lchild->data == e) /* p存在左右孩子且左孩子是e */
			return p->rchild->data; /* 返回p的右孩子(e的右兄弟) */
	}
	return Nil; /* 树空或没找到e的右兄弟 */
}

Status InsertChild(BiTree p, int LR, BiTree c) /* 形参T无用 */
{ /* 初始条件: 二叉树T存在,p指向T中某个结点,LR为0或1,非空二叉树c与T */
  /*           不相交且右子树为空 */
  /* 操作结果: 根据LR为0或1,插入c为T中p所指结点的左或右子树。p所指结点的 */
  /*           原有左或右子树则成为c的右子树 */
	if (p) /* p不空 */
	{
		if (LR == 0) {
			c->rchild = p->lchild;
			p->lchild = c;
		} else /* LR==1 */
		{
			c->rchild = p->rchild;
			p->rchild = c;
		}
		return OK;
	}
	return ERROR; /* p空 */
}

Status DeleteChild(BiTree p, int LR) /* 形参T无用 */
{ /* 初始条件: 二叉树T存在,p指向T中某个结点,LR为0或1 */
  /* 操作结果: 根据LR为0或1,删除T中p所指结点的左或右子树 */
	if (p) /* p不空 */
	{
		if (LR == 0) /* 删除左子树 */
			ClearBiTree(&p->lchild);
		else /* 删除右子树 */
			ClearBiTree(&p->rchild);
		return OK;
	}
	return ERROR; /* p空 */
}

void PreOrderTraverse(BiTree T, Status(*Visit)(TElemType)) { /* 初始条件: 二叉树T存在,Visit是对结点操作的应用函数。算法6.1，有改动 */
															 /* 操作结果: 先序递归遍历T,对每个结点调用函数Visit一次且仅一次 */
	if (T) /* T不空 */
	{
		Visit(T->data); /* 先访问根结点 */
		PreOrderTraverse(T->lchild, Visit); /* 再先序遍历左子树 */
		PreOrderTraverse(T->rchild, Visit); /* 最后先序遍历右子树 */
	}
}

void InOrderTraverse(BiTree T, Status(*Visit)(TElemType)) { /* 初始条件: 二叉树T存在,Visit是对结点操作的应用函数 */
															/* 操作结果: 中序递归遍历T,对每个结点调用函数Visit一次且仅一次 */
	if (T) {
		InOrderTraverse(T->lchild, Visit); /* 先中序遍历左子树 */
		Visit(T->data); /* 再访问根结点 */
		InOrderTraverse(T->rchild, Visit); /* 最后中序遍历右子树 */
	}
}

typedef BiTree SElemType; /* 设栈元素为二叉树的指针类型 */
#ifndef _SqStack_H //栈的顺序存储表示
#define _SqStack_H
//#include"c3-1.h"
/* c3-1.h 栈的顺序存储表示 */
#define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
#define STACKINCREMENT 2 /* 存储空间分配增量 */
typedef struct SqStack {
	SElemType *base; /* 在栈构造之前和销毁之后，base的值为NULL */
	SElemType *top; /* 栈顶指针 */
	int stacksize; /* 当前已分配的存储空间，以元素为单位 */
}SqStack; /* 顺序栈 */
#endif // !_SqStack_H
#include"bo3-1.c"
Status InOrderTraverse1(BiTree T, Status(*Visit)(TElemType)) { 
	/* 采用二叉链表存储结构，Visit是对数据元素操作的应用函数。算法6.3 */															   
	/* 中序遍历二叉树T的非递归算法(利用栈)，对每个数据元素调用函数Visit */
	SqStack S;
	InitStack(&S);
	while (T || !StackEmpty(S)) {
		if (T) { /* 根指针进栈,遍历左子树 */
			Push(&S, T);
			T = T->lchild;
		} else { /* 根指针退栈,访问根结点,遍历右子树 */
			Pop(&S, &T);
			if (!Visit(T->data))
				return ERROR;
			T = T->rchild;
		}
	}
	printf("\n");
	return OK;
}

Status InOrderTraverse2(BiTree T, Status(*Visit)(TElemType)) { 
	/* 采用二叉链表存储结构，Visit是对数据元素操作的应用函数。算法6.2 */															   
	/* 中序遍历二叉树T的非递归算法(利用栈)，对每个数据元素调用函数Visit */
	SqStack S;
	BiTree p;
	InitStack(&S);
	Push(&S, T); /* 根指针进栈 */
	while (!StackEmpty(S)) {
		while (GetTop(S, &p) && p)
			Push(&S, p->lchild); /* 向左走到尽头 */
		Pop(&S, &p); /* 空指针退栈 */
		if (!StackEmpty(S)) { /* 访问结点,向右一步 */
			Pop(&S, &p);
			if (!Visit(p->data))
				return ERROR;
			Push(&S, p->rchild);
		}
	}
	printf("\n");
	return OK;
}

void PostOrderTraverse(BiTree T, Status(*Visit)(TElemType)) { 
	/* 初始条件: 二叉树T存在,Visit是对结点操作的应用函数 */															  
	/* 操作结果: 后序递归遍历T,对每个结点调用函数Visit一次且仅一次 */
	if (T) /* T不空 */
	{
		PostOrderTraverse(T->lchild, Visit); /* 先后序遍历左子树 */
		PostOrderTraverse(T->rchild, Visit); /* 再后序遍历右子树 */
		Visit(T->data); /* 最后访问根结点 */
	}
}

void LevelOrderTraverse(BiTree T, Status(*Visit)(TElemType)) { 
	/* 初始条件：二叉树T存在,Visit是对结点操作的应用函数 */															   
	/* 操作结果：层序递归遍历T(利用队列),对每个结点调用函数Visit一次且仅一次 */
	LinkQueue q;
	QElemType a;
	if (T) {
		InitQueue(&q);
		EnQueue(&q, T);
		while (!QueueEmpty(q)) {
			DeQueue(&q, &a);
			Visit(a->data);
			if (a->lchild != NULL)
				EnQueue(&q, a->lchild);
			if (a->rchild != NULL)
				EnQueue(&q, a->rchild);
		}
		printf("\n");
	}
}
