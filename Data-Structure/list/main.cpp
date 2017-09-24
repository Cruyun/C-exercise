#include <iostream>
#include "list.cpp"
#include "list.h"
using namespace std;

int main() {
    Sqlist L;
    L.len = 5;
    InitList(&L, L.len, LISTINCREMENT);
    cout << "----------" << endl;
    for (int i = 0; i < L.len; i++) {
        L.elem[i] = 0;
    }
    for (int i = 1; i < 6; i++) {
        ListInsert(&L, 1, i);
    }
    ListTraverse(L);

    cout << "----------" << endl;
    int next_e;
    int pre_e;
    PriorElem(L, 1, &pre_e);
    NextElem(L, 4, &next_e);

    cout << "----------" << endl;
    ListEmpty(L);
    ListLength(L);

    cout << "----------" << endl;
    int e;
    GetElem(L, 2, &e);
    LocateElem(L,2);
    ListDelete(&L,2,&e);
    cout << "----------" << endl;
    cout << "the new list is:" << endl;
    ListTraverse(L);
    cout << "----------" << endl;
    //ClearList(&L);
    //LDestroyList(&L);

    cout << "----------" << endl;
    Sqlist B;
    B.len = 5;
    InitList(&B, B.len, LISTINCREMENT);
    cout << "----------" << endl;
    for (int i = 0; i < B.len; i++) {
        B.elem[i] = 0;
    }
    for (int i = 7; i <= 11; i++) {
        ListInsert(&B, 1, i);
    }
    ListTraverse(B);
    unionList(&L, &B);
    cout << "the new list A is:" << endl;
    ListTraverse(L);

    ClearList(&L);
    DestroyList(&L);
    return 0;
}
