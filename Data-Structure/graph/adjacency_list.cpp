#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_VERTEX_NUM  20
#define INFINITY 65535

typedef double InfoType;
typedef char VertexType;

typedef enum {DG, DN, AG} GraphKind;

typedef struct AcNode {
    int      adjvex;
    struct   AcNode *nextarc;
    InfoType info;
} ArcNode;

typedef struct VNode {
    VertexType data;
    ArcNode *firstarc;
    InfoType info;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
    AdjList vertices;
    int     vexnum, arcnum;
    int     kind;
}ALGraph;

typedef struct {
    VertexType V1;
    VertexType V2;
    InfoType adj;
}VTable;

const int vexnum = 9;
const int arcnum = 8;
VTable vTable[arcnum] = { {'A','B',32.8},{'A','H',12.1},{'B','C',5.9},{'C','D',21.3},
                          {'C','E',41.1}, {'E','G',10.5}, {'F','I',79.2},{'H','I',8.7}};

VertexType vexTable[vexnum] = {'A','B','C','D','E','F','G','H','I'};

void CreateUDG(ALGraph &G, VTable *vTable, VertexType *vexTable) {
    VertexType v1, v2;

    G.vexnum = vexnum;
    G.arcnum = arcnum;

    for (int i = 0; i < G.vexnum; ++i) {
        G.vertices[i].data = vexTable[i];
        G.vertices[i].firstarc = NULL;
    }

    for (int k = 0; k < G.arcnum; ++k) {
        v1 = vTable[k].V1;
        v2 = vTable[k].V2;
        int i = vTable[k].V1 - 'A';
        int j = vTable[k].V2 - 'A';

        ArcNode *pi = new ArcNode;
        pi->adjvex = j;
        pi->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = pi;

        ArcNode *pj = new ArcNode;
        pj->adjvex = i;
        pj->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = pj;
    }
}

bool visited[vexnum];

void DFS(ALGraph &G, int i){
    visited[i] = true;
    cout << G.vertices[i].data << " ";

    ArcNode *p = G.vertices[i].firstarc;

    while(p){
        if(!visited[p->adjvex]){
            DFS(G,p->adjvex);
        }
        p = p->nextarc;
    }
}


void DFSTraverse(ALGraph &G){
    for (int i = 0; i < G.vexnum; ++i){
        visited[i] = false;
    }
    for (int i = 0; i < G.vexnum; ++i){
        if(!visited[i]){
            DFS(G,i);
        }
    }
}

int main() {
    ALGraph *G = new ALGraph;
    CreateUDG(*G, vTable, vexTable);
    DFSTraverse(*G);
    return 0;
}
