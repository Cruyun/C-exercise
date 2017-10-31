#ifndef _STACK_H
#define _STACK_H

typedef struct Node Stack;
typedef int ElemType;

typedef struct Node {
    ElemType data;
    Node *next;
    Node(): next(NULL) {};
    Node(ElemType iValue): data(iValue), next(NULL) {};
}Node;

void InitStack(Stack *S);
void DestroyStack(Stack *S);
void ClearStack(Stack *S);
bool StackEmpty(Stack S);
int StackLength(Stack *S);
void GetTop(Stack S, ElemType e);
void Push(Stack *S, ElemType e);
ElemType Pop(Stack *S, ElemType &e);
void StackTraverse(Stack S);
bool OpMember(char ch);
int evaluation(char suffix[ ]);
ElemType Operate(ElemType a, char ch, ElemType b);

#endif