#ifndef linkbitree_h
#define linkbitree_h
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define Status int
#define TRUE 1
#define FALSE 0
#define LEFT 0
#define RIGHT 1
#define NUM 100			//栈和队列的长度(数组长度)
typedef int TElemType;
typedef struct _bitree{
	TElemType data;
	struct _bitree *lchild;
	struct _bitree *rchild;
}BiTNode;
typedef struct _stack{
	BiTNode **arr;
	int top;
	int base;
}TreeStack;
typedef TreeStack TreeQueue;
Status InitTreeStack(TreeStack *stack);
//初始化栈，为arr分配长度为NUM的数组，并设置top与base指向栈尾后一个单位
Status TreePop(TreeStack *stack,BiTNode **bitnode);
//出栈，将栈顶元素返回到bitnode中
Status TreePush(TreeStack *stack,BiTNode *bitnode);
//入栈，将bitnode的指针存到stack的栈顶
Status TStackEmpty(TreeStack stack);
//若栈Q为空栈，则返回TRUE，否则返回FALSE
Status TStackGetTop(TreeStack stack,BiTNode **bitnode);
//若栈不空，则用bitnode返回stack的栈顶元素，并返回OK，否则返回ERROR与NULL
Status InitTreeQueue(TreeQueue *queue);
//初始化队列
Status TreeEnQueue(TreeQueue *queue,BiTNode *node);
//入队列
Status TreeDeQueue(TreeQueue *queue,BiTNode **node);
//出队列
Status TQueueEmpty(TreeQueue queue);
//若队列为空，则返回TRUE,否则返回FALSE

Status CreateBiTree(BiTNode **root);
//先序创建二叉树
Status InitBiTree(BiTNode **root);
//初始化空树，创建空二叉树root
Status DestroyBiTree(BiTNode **root);
//销毁二叉树root，使其为空树
Status BiTreeEmpty(BiTNode *root);
//判断二叉树是否为空，若root为空二叉树，则返回TRUE，否则返回FALSE
int BiTreeDepth(BiTNode *root);
//返回二叉树root的深度
int BiTNodeLevel(BiTNode *root,BiTNode *node);
//求结点node在二叉树root中的层数
Status isSubBiTree(BiTNode *root,BiTNode *node);
//判断node是否为二叉树root的结点
TElemType Value(BiTNode *root,BiTNode *node);
//node是二叉树root的某个结点，返回结点node的数据值
Status Assign(BiTNode *root,BiTNode *node,TElemType data);
//node是二叉树root的某个结点，将结点node的数据值赋值为data
BiTNode *GetParent(BiTNode *root,BiTNode *node);
//返回结点node在二叉树root中的父结点
BiTNode *Parent(BiTNode *root,BiTNode *node);
//node是二叉树root中的节点，当node是root的非根结点时，返回node的父亲结点，否则返回空
BiTNode *LeftChild(BiTNode *root,BiTNode *node);
//node是二叉树root中的节点，返回node的左儿子结点，(若node无左儿子)否则返回空
BiTNode *RightChild(BiTNode *root,BiTNode *node);
//node是二叉树root中的节点，返回node的右儿子结点，(若node无右儿子)否则返回空
BiTNode *LeftSiblint(BiTNode *root,BiTNode *node);
//node是二叉树root中的节点，返回node的左兄弟结点，(若node无左兄弟或node是root的左孩子)否则返回空
BiTNode *RightSiblint(BiTNode *root,BiTNode *node);
//node是二叉树root中的节点，返回node的右兄弟结点，(若node无右兄弟或node是root的右孩子)否则返回空
Status InsertChild(BiTNode *root,BiTNode *node,int lr,BiTNode *newnode);
//二叉树root存在，node为root中的某个结点，lr为0(left)或1(right)，非空二叉树newnode与root不相交且
//右子树为空，根据lr的值插入newnode为root中node的左或右子树。node的原左或右子树则成为newnode的右子树
Status DeleteChile(BiTNode *root,BiTNode *node,int lr,BiTNode **newnode);
//二叉树root存在，node为root中的某个结点，lr为0(left)或1(right)，根据lr的值删除node的左或右子树，并赋给newnode
Status PreOrderTraverse(BiTNode *root,Status (*visit)(BiTNode *));
//先序遍历(递归法)二叉树root，对每个结点调用函数visit一次且仅一次，一旦调用失败，操作失败
Status PostOrderTraverse(BiTNode *root,Status (*visit)(BiTNode *));
//后序遍历(递归法)二叉树root，对每个结点调用函数visit一次且仅一次，一旦调用失败，操作失败
Status InOrderTraverse(BiTNode *root,Status (*visit)(BiTNode *));
//中序遍历(递归法)二叉树root，对每个结点调用函数visit一次且仅一次，一旦调用失败，操作失败
Status PreOrderTraverse_stack(BiTNode *root,Status (*visit)(BiTNode *));
//先序遍历(非递归法)二叉树root，对每个结点调用函数visit一次且仅一次，一旦调用失败，操作失败
Status InOrderTraverse_stack(BiTNode *root,Status (*visit)(BiTNode *));
//中序遍历(非递归法)二叉树root，对每个结点调用函数visit一次且仅一次，一旦调用失败，操作失败
Status PostOrderTraverse_stack(BiTNode *root,Status (*visit)(BiTNode *));
//后序遍历(非递归法)二叉树root，对每个结点调用函数visit一次且仅一次，一旦调用失败，操作失败
Status LevelOrderTraverse(BiTNode *root,Status (*visit)(BiTNode *));
//层序遍历(利用队列)二叉树root，对每个结点调用函数visit一次且仅一次，一旦调用失败，操作失败
Status PrintBiTree(BiTNode *node);
//遍历函数的功能函数，打印节点的数据值
#endif
