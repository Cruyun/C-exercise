#include <iostream>
#include <iomanip>

using namespace std;

#define MAX_VERTEX_NUM  20
#define INFINITY 65535

typedef double InfoType;
typedef char VertexType;

typedef enum {DG, DN, AG} GraphKind;

typedef struct {
    VertexType vex[MAX_VERTEX_NUM]; //描述顶点的数组
    InfoType adjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵
    int       vexnum, arcnum; //图的当前顶点数和弧数
    GraphKind kind;
} MGraph;

typedef struct {
    VertexType V1;
    VertexType V2;
    InfoType adj;
}VTable;

typedef struct {
    VertexType V1;
    VertexType V2;
    InfoType adj;
    int flag;
}Edge;

typedef struct {
    int data;
    int set;
}VEX;


const int vexnum = 9;
const int arcnum = 15;
VTable vTable[arcnum] = { {'A','B',32.8},{'A','C',44.6},{'A','H',12.1},{'A','I',18.2},
                          {'B','C',5.9} ,{'C','G',56.4},{'C','E',41.1},{'C','D',21.3},
                          {'D','E',67.3},{'D','F',98.7},{'E','F',85.6},{'E','G',10.5},
                          {'F','I',79.2},{'G','H',52.5},{'H','I',8.7} };

VertexType vexTable[vexnum] = {'A','B','C','D','E','F','G','H','I'};

void sort(Edge *eSet,int N)
{
    int i = 0, j = 0;
    Edge t;
    for(i = 0;i < N - 1;i++) {
        for(j = i + 1;j < N; j++) {
            if(eSet[i].adj > eSet[j].adj) {
                t = eSet[i];
                eSet[i] = eSet[j];
                eSet[j] = t;
            }
        }
    }
}

void Krusal(MGraph *g,VTable *vTable, VertexType *vexTable){
    VEX vSet[g->vexnum];
    Edge eSet[g->arcnum];

    for (int i = 0; i < g->vexnum; ++i) {
        vSet[i].set = i;
        vSet[i].data = vexTable[i] - 'A';
    }
    for (int i = 0; i < g->arcnum; ++i) {
        eSet[i].V1 = vTable[i].V1;
        eSet[i].V2 = vTable[i].V2;
        eSet[i].adj = vTable[i].adj;
        eSet[i].flag = 0;
    }
    sort(eSet,g->arcnum);
    int count = 1;
    int j = 0; // 下标

    while(count < g->vexnum) {
        int s1 = vSet[eSet[j].V1 - 'A'].set;
        int s2 = vSet[eSet[j].V2 - 'A'].set;
        if (eSet[j].flag == 0) {
            if (s1 != s2) {
                cout << eSet[j].V1 << "---->" << eSet[j].adj << "----->" << eSet[j].V2<< endl;
                count++;
                for (int i = 0; i < g->vexnum; ++i) {
                    if (vSet[i].set == s2) {
                        vSet[i].set = s1;
                    }
                }
            } else{
                eSet[j].flag = 1;
            }
        }
        j++;
    }
}

int main() {
    MGraph *g = new MGraph;
    CreateGraph(g, vTable, vexTable);
    Krusal(g,vTable, vexTable);

    return 0;
}