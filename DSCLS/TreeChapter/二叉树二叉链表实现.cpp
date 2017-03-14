#include<string.h>/* c1.h (程序名) */
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
//#define OVERFLOW -2 因为在math.h中已定义OVERFLOW的值为3,故去掉此行
//#define Node TypeNode //泛型结构结点
//#define LEN  sizeof(Node) //泛型结构结点长度
//#define MLCS (Node *)malloc(sizeof(Node)) //泛型结构结点开内存
typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */
//typedef int ElemType; //泛型结构的数据域类型
typedef int TElemType; //泛型结构的数据域类型
typedef struct BiTNode { /* c6-2.h 二叉树的二叉链表存储表示 */
	TElemType data;
	struct BiTNode *lchild, *rchild; /* 左右孩子指针 */
}BiTNode, *BiTree;//二叉树的二叉链表存储表示