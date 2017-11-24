#ifndef _TREE_H
#define _TREE_H

#define SIZE 100
typedef char TElemType;


typedef struct BiNode {
    TElemType data;
    struct BiNode *lchild, *rchild;
}BiNode, *BiTree;

typedef struct {
    BiTree Q[SIZE];
    int front;
    int rear;
}Queue;


void CreatebiTree(BiTree &T);
void InOrder(BiTree T);
void traverse(BiTree &T);
void InitQueue(Queue &q);
void EnQueue(Queue &q, BiTree &p);
void DeQueue(Queue &q, BiTree &p);
#endif