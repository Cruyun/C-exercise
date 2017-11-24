#include <iostream>
#include "tree.h"
using namespace std;

void CreatebiTree(BiTree &T) {
    TElemType data;
    cin >> data;
    if (data == '#') {
        T = NULL;
    } else {
        T = new BiNode;
        T->data = data;
        CreatebiTree(T->lchild);
        CreatebiTree(T->rchild);
    }
}

void InOrder(BiTree T) {
    if (T) {
        InOrder(T->lchild);
        cout << T->data;
        InOrder(T->rchild);
    }
}

void traverse(BiTree &T) {
    BiTree tree;
    Queue q;

    tree = T;
    InitQueue(q);

    if(tree){
        EnQueue(q, tree);

        while(q.front != q.rear){
            DeQueue(q,tree);
            cout << tree->data;
            if(tree->lchild)
                EnQueue(q, tree->lchild);
            if(tree->rchild)
                EnQueue(q, tree->rchild);
        }
    }
}

void InitQueue(Queue &q){
    q.front = 0;
    q.rear = 0;
}

void EnQueue(Queue &q, BiTree &p){
    if((q.rear + 1) % SIZE != q.front){
        q.Q[q.rear] = p;
        q.rear = (q.rear+1) % SIZE;
    }
}

void DeQueue(Queue &q, BiTree &p){
    if(q.front != q.rear){
        p = q.Q[q.front];
        q.front = (q.front + 1) % SIZE;
    }
}
