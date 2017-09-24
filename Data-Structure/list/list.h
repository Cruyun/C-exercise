#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#include <iostream>
using namespace std;

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
