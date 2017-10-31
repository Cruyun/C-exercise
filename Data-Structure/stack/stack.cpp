#include <iostream>
#include "stack.h"
using namespace std;

void InitStack(Stack *S) {
    S = NULL;
}

void DestroyStack(Stack *S) {
    S = S->next;
    if (S != NULL)
        delete(S);
    cout << "destroy stack"<< endl;
}
void ClearStack(Stack *S) {
    S = S->next;
    if (S != NULL) {
        S->data = 0;
        S->next = NULL;
        cout << "clear stack"<< endl;
    }
}
int StackLength(Stack *S) {
    int length = 0;
    S = S->next;
    if (S == NULL)
        return 0;
    else {
        while (S != NULL) {
            length++;
            S = S->next;
        }
        return length;
    }
}
bool StackEmpty(Stack *S) {
    if (S == NULL) {
        cout << "this stack is empty" << endl;
        return true;
    } else {
        cout << "this stack is not empty" << endl;
        return false;
    }
}

void Push(Stack *S, ElemType e) {
    //cout << S->data;
    Node *p = new Node(0);
    p->data = e;
    p->next = S->next;
    S->next = p;
    //cout << "push data is " << S->next->data << endl;
    delete p;
}

ElemType Pop(Stack *S, ElemType &e) {
    if (S->next == NULL) {
        cout << "this stack is empty" << endl;
    } else {
        e = S->next->data;
        S->next = S->next->next;
        //cout << "pop data is " << e << endl;
    }
    return e;
}
int GetTop(Stack *S, ElemType &e) {
    S = S->next;
    if (S!= NULL) {
        e = S->data;
        return e;
    } else {
        cout << "this stack is empty" << endl;
        return -1;
    }
}

void StackTraverse(Stack *S) {
    cout << "traverse stack's elememts:" << endl;
    S = S->next;
    while (S != NULL) {
        cout << S->data << " ";
        S = S->next;
    }
    cout << endl;
}

bool OpMember(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else 
        return false;
}

ElemType Operate(ElemType a, char ch, ElemType b) {
    ElemType m = 0;
    if (ch == '+') {
        m = a + b;
    } else if (ch == '-') {
        m = a - b;
    } else if (ch == '*') {
        m = a * b;
    } else if (ch == '/') {
        m = a / b;
    }
    return m;
}

int evaluation(char suffix[ ])
{
    Node * S = new Node(0);
    char ch;
    int result;
    ch = *suffix++;
    ElemType a,b,c;
    InitStack(S);
    while(ch!= '#'){
        if(!OpMember(ch)) {
            c = ch -'0';
            Push(S,c);
        }
        else{
            //Pop(S,b);
            //Pop(S,a);
            b = Pop(S, b);
            a = Pop(S, a);
            Push(S,Operate(a,ch,b));
        }
        ch=*suffix++;
    }
    ElemType e;
    result = Pop(S, e);
    //Pop(S,result);
    return result;
}