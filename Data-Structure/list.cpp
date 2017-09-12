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
bool GetElem(Sqlist L, int i, ElemType * e);
int LocateElem(Sqlist L, ElemType e);
bool PriorElem(Sqlist L, ElemType cur_e, ElemType * pre_e);
bool NextElem(Sqlist L, ElemType cur_e, ElemType * next_e);
void ListInsert(Sqlist * L, int i, ElemType e);
void ListDelete(Sqlist * L, int i, ElemType * e);
void ListTraverse(Sqlist L); // 依次输出每个元素

int main() {
    Sqlist L;
    InitList(&L, LIST_INIT_SIZE, LISTINCREMENT);
    L.len = 5;
    for (int i = 0; i < L.len; i++) {
        L.elem[i] = 0;
    }


}

void InitList(Sqlist * L, int maxsize, int incresize) {
    L->elem = new ElemType[maxsize];
    L->len = 0;
    L->listsize = LIST_INIT_SIZE;
    L->incrementsize = LISTINCREMENT;
}

void DestroyList(Sqlist * L) {
    if (L->listsize != 0) {
        delete[] L->elem;
        L->listsize = 0;
        L->len = 0;
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
        L->listsize = 0;
    } else {
        cout << "Error: this list is not exit" << endl;
    }
}

bool ListEmpty(Sqlist L) {
    if (L.listsize != 0) {
        return true;
    }
    return false;
}

int ListLength(Sqlist L) {
    return L.len;
}

bool GetElem(Sqlist L, int i, ElemType * e) {
    if (L.listsize != 0) {
        e = &L.elem[i];
        return true;
    }
    return false;
}

int LocateElem(Sqlist L, ElemType e) {
    if (L.listsize != 0) {
        for (int i = 1; i <= L.len; i++) {
            if (e == L.elem[i-1])
                return i;
            else
                return 0;
        }
    }
    return 0;
}

bool PriorElem(Sqlist L, ElemType cur_e, ElemType * pre_e) {
    if (L.elem[0] != cur_e) {
        for (int i = 0; i < L.len; i++) {
            if (L.elem[i] == cur_e) {
                pre_e = &L.elem[i - 1];
                return true;
            } else {
                cout << "error" << endl;
                return false;
            }
        }
    }
}

bool NextElem(Sqlist L, ElemType cur_e, ElemType * next_e){
    if (L.elem[L.len-1] != cur_e) {
        for (int i = 0; i < L.len; i++) {
            if (L.elem[i] == cur_e) {
                next_e = &L.elem[i + 1];
                return true;
            } else {
                cout << "error" << endl;
                return false;
            }
        }
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
        L->len --;
    }
}

void ListTraverse(Sqlist L) {
    for (int i = 0; i < L.len; i++) {
        if (i != L.len - 1)
            cout << L.elem[i] << " ";
        else
            cout << L.elem[i-1];
    }
}