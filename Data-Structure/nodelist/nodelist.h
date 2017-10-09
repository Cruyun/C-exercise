#ifndef _NODELIST_H
#define _NODELIST_H

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

void ListTravers(LinkList L);
void ListInsert(LinkList * L, LNode *p, LNode *s);
void ListDelete(LinkList * L, LNode *p, ElemType *e);
void InvertLinkdList(LinkList * L);
int ListLength(LinkList L);
LNode * LocatedElem(LinkList L, ElemType e);

#endif