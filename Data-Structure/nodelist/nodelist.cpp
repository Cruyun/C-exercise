#include <iostream>
#include "nodelist.h"
using namespace std;

void ListTravers(LinkList L) {
    cout << "traverse list's elememts:" << endl;
    L = L->next;
    while (L != NULL) {
        cout << L->data << " ";
        L = L->next;
    }
}

int ListLength(LinkList L) {
    int k = 0;
    while(L->next != NULL) {
        k++;
        L = L->next;
    }
    return k;
}

LNode * LocatedElem(LinkList L, ElemType e) {
    while (L && L->data != e) {
        L = L->next;
    }
    if (L!= NULL)
        return L;
    else
        return NULL;
}

void ListInsert(LinkList * L, LNode *p, LNode *s) {
    if (p == *L) {
        s->next = (*L)->next;
        (*L)->next = s;
    } else {
        while ((*L)->next != p)
            *L = (*L)->next;
        (*L)->next = s;
        s->next = p;
    }
}

void ListDelete(LinkList * L, LNode *p, ElemType *e) {
    cout << "delete " << p->data << endl;
    LinkList temp; // 临时变量
    if (p == (*L)->next) {
        *e = p->data;
        (*L)->next = (*L)->next->next;
    } else {
        temp = *L;
        while (temp->next!= p) {
            temp = temp->next;
        }
        *e = temp->next->data;
        temp->next = temp->next->next;
    }

}

void InvertLinkList(LinkList *L) {
    LinkList p = *L;
    *L = new LNode;
    p = p->next;

    while (p!=NULL) {
        LNode *newL = new LNode;
        newL->data = p->data;
        // cout << newL->data << endl;
        if((*L) -> next == NULL) {
            (*L)->next = newL;
            // cout << newLn->data << endl;
        }
        else{
            newL->next = (*L)->next;
            // cout << newL->data << endl;
            (*L) -> next = newL;
        }
        p = p->next;
    }
}