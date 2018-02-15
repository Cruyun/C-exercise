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

const int vexnum = 9;
const int arcnum = 15;
VTable vTable[arcnum] = { {'A','B',32.8},{'A','C',44.6},{'A','H',12.1},{'A','I',18.2},
                          {'B','C',5.9} ,{'C','G',56.4},{'C','E',41.1},{'C','D',21.3},
                          {'D','E',67.3},{'D','F',98.7},{'E','F',85.6},{'E','G',10.5},
                          {'F','I',79.2},{'G','H',52.5},{'H','I',8.7} };

VertexType vexTable[vexnum + 1] = {'A','B','C','D','E','F','G','H','I'};

void CreateGraph(MGraph *g, VTable *vTable, VertexType *vexTable) {
    int i, j, k;

    g->arcnum = arcnum;
    g->vexnum = vexnum;

    for (i = 0; i < g->vexnum; ++i) {
        g->vex[i] = vexTable[i];
    }

    // 矩阵初始化
    for (i = 0; i < g->vexnum; ++i) {
        for (j = 0; j < g->vexnum; ++j) {
            if (i == j)
                g->adjMatrix[i][j] = 0;
            else
                g->adjMatrix[i][j] = INFINITY;
        }
    }

    for (k = 0; k < g->arcnum; ++k) {
        VertexType v1, v2;
        InfoType weight;
        v1 = vTable[k].V1;
        v2 = vTable[k].V2;
        weight = vTable[k].adj;

        g->adjMatrix[v1 - 'A'][v2 - 'A'] = weight;
        g->adjMatrix[v2 - 'A'][v1 - 'A'] = weight;
    }
}

void ShowMatrix(MGraph *g) {
    int i, j;
    for (i = 0; i < g->vexnum; i++) {
        for (j = 0; j < g->vexnum; j++) {
            if (g->adjMatrix[i][j] == INFINITY) {
                g->adjMatrix[i][j] = 0;
            }
            cout << setw(4) << g->adjMatrix[i][j] << "  ";
            if (j == g->vexnum - 1)
                cout << endl;
        }
    }
}
bool visited[vexnum];
void DFS(MGraph &G, int i) {
    int j;
    visited[i] = true;
    cout << G.vex[i] << " ";

    for (j = 0; j < G.vexnum; ++j) {
        if (!G.adjMatrix[i][j]  &&  !visited[j])
            DFS(G, j);
    }
}

void DFSTraverse(MGraph &G) {
    for (int i = 0; i < G.vexnum; ++i)
        visited[i] = false;

    for (int i = 0; i < G.vexnum; ++i) {
        if (!visited[i])
            DFS(G, i);
    }
}

int main() {
    MGraph *g = new MGraph;
    CreateGraph(g, vTable, vexTable);
    cout << "the Adjacency matrix of this graph:" << endl;
    ShowMatrix(g);
    cout << endl;
    cout << "show this graph:" << endl;
    DFSTraverse(*g);
    return 0;
}
