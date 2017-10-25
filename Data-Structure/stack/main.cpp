#include <iostream>
#include "stack.cpp"
#include "stack.h"

using namespace std;
int main() {
    Node * S = new Node(0);
    InitStack(S);
    int n;
    cout << "let's add some data:" << endl;
    cout << "how many numbers do you want to add:";
    cin >> n;
    Node * temp = S;
    for (int i = 0; i < n; i++) {
        Node * t = new Node(0);
        cout <<"input data：";
        cin >> t->data;
        t->next = NULL;
        temp->next = t;
        temp = temp->next;
    }
    temp = NULL;
    StackTraverse(S);
    int e1 = 3;
    int e2;
   Push(S, e1);
    StackTraverse(S);
    cout << "pop data is " << Pop(S, e2) << endl;
    StackTraverse(S);
    StackEmpty(S);
    cout << "this length of this stack is " << StackLength(S) << endl;
    cout << "this top data of this stack is " << GetTop(S, e2)<< endl;
    ClearStack(S);
    DestroyStack(S);

    return 0;
}