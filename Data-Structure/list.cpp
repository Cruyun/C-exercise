//
// Created by Cai Ruyun on 2017/9/12.
//
#include <iostream>
using namespace std;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;
typedef struct {
    ElemType * elem;
    int len;
    int listsize;
    int incrementsize;
} Sqlist;

void InitList(Sqlist * L, int maxsize, int incresize);
void DestroyList(Sqlist * L);
void ClearList(Sqlist * L);
bool ListEmpty(Sqlist L);
int ListLength(Sqlist L);
void GetElem(Sqlist L, int i, ElemType * e);
int LocateElem(Sqlist L, ElemType e);
void PriorElem(Sqlist L, ElemType cur_e, ElemType * pre_e);
void NextElem(Sqlist L, ElemType cur_e, ElemType * next_e);
void ListInsert(Sqlist * L, int i, ElemType e);
void ListDelete(Sqlist * L, int i, ElemType * e);
void ListTraverse(Sqlist L); // 依次输出每个元素
void unionList(Sqlist * La, Sqlist * Lb);

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

void InitList(Sqlist * L, int maxsize, int incresize) {
    L->elem = new ElemType[maxsize];
    L->len = 0;
    L->listsize = LIST_INIT_SIZE;
    L->incrementsize = LISTINCREMENT;
    cout << "list init" << endl;
}

void DestroyList(Sqlist * L) {
    if (L->listsize != 0) {
        delete[] L->elem;
        L->listsize = 0;
        L->len = 0;
        cout << "list is destroyed" << endl;
    } else {
        cout << "Error: this list is not exit" << endl;
    }
}

void ClearList(Sqlist * L) {
    if (L->listsize != 0) {
        for (int i = 0; i < L->len; ++i) {
            L->elem[i] = 0;
        }
        L->len = 0;
    } else {
        cout << "Error: this list is not exit" << endl;
    }
    cout << "list clear" << endl;
}

bool ListEmpty(Sqlist L) {
    if (L.len != 0) {
        cout << "this list is not empty" << endl;
        return true;
    }
    cout << "this list is empty" << endl;
    return false;
}
int ListLength(Sqlist L) {
    cout << "the length of this list is " << L.len << endl;
    return L.len;
}

void GetElem(Sqlist L, int i, ElemType * e) {
    if (L.listsize != 0) {
        e = &L.elem[i];
        cout << "the " << i+1 << " element is " << *e << endl;
    } else {
        cout << "error" << endl;
    }
}

int LocateElem(Sqlist L, ElemType e) {
    int flag = 0;
    if (L.listsize != 0) {
        for (int i = 1; i <= L.len; i++) {
            if (e == L.elem[i-1]) {
                cout << e << " is located at " << i << endl;
                flag = 1;
            }
        }
        if (!flag) {
            cout << e << " is not exist" << endl;
        }
    }
    return flag;
}

void PriorElem(Sqlist L, ElemType cur_e, ElemType * pre_e) {
    if (L.elem[0] != cur_e) {
        for (int i = 0; i < L.len; i++) {
            if (L.elem[i] == cur_e) {
                pre_e = &L.elem[i - 1];
                cout << cur_e << " follows " << *pre_e << endl;
            }
        }
    } else {
        cout << "error" << endl;
    }
}

void NextElem(Sqlist L, ElemType cur_e, ElemType * next_e){
    if (L.elem[L.len-1] != cur_e) {
        for (int i = 0; i < L.len; i++) {
            if (L.elem[i] == cur_e) {
                next_e = &L.elem[i + 1];
                cout << *next_e << " follows " << cur_e << endl;
            }
        }
    }else {
        cout << "error" << endl;
    }
}

void ListInsert(Sqlist * L, int i, ElemType e) {
    if (i < 1 || i > L->len+1 || L->len == LIST_INIT_SIZE) {
        cout << "i error" << endl;
    } else {
        for (int j = L->len - 1; j >= i - 1; j--) {
            L->elem[j + 1] = L->elem[j];
        }
        L->elem[i - 1] = e;
        L->len += 1;
    }
}

void ListDelete(Sqlist * L, int i, ElemType * e) {
    if (i < 1 || i > L->len+1 || L->len == LIST_INIT_SIZE) {
        cout << "i error" << endl;
    } else {
        * e = L->elem[i - 1];
        if (i < L->len) {
            for (int j = i; j < L->len; j++) {
                L->elem[j - 1] = L->elem[j];
            }
        }
        cout << "delete the " << i << " element which is " << *e << endl;
        L->len --;
    }
}

void ListTraverse(Sqlist L) {
    cout << "traverse list's elememts:" << endl;
    for (int i = 0; i < L.len; i++) {
        cout << "[" << i << "]: " << L.elem[i] << endl;
    }
}

void unionList(Sqlist * La, Sqlist * Lb) {
    int la_len = ListLength(*La);
    int e = 0;
    while(ListEmpty(*Lb)) {
        ListDelete(Lb, 1, &e);
        if (!LocateElem(*La, e))
            ListInsert(La, ++la_len, e);
    }
    DestroyList(Lb);
}