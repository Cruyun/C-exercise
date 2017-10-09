#include <iostream>
#include "nodelist.cpp"
#include "nodelist.h"

using namespace std;

int main() {
    LinkList L = new LNode;
    LinkList temp = L;
    for (int i = 0; i < 5; i++) {
        LNode * t = new LNode;
        t->data = i;
        t->next = NULL;
        temp->next = t;
        temp = temp->next;
    }
    temp = NULL;
    LNode *one = new LNode;
    one->data = 7;
    one->next = NULL;
    ListInsert(&L, L, one); // 插到链表的头部
    ListTravers(L);
    cout << endl;

    cout << "the length of list is " << ListLength(L) << endl;

    LNode *position = LocatedElem(L, one->data);
    cout << "one's data: " << position->data << endl;

    ElemType e = 0;
    ListDelete(&L, one, &e);
    ListTravers(L);
    InvertLinkdList(&L);
    cout << "after invert:" << endl;
    ListTravers(L);
    return 0;

}