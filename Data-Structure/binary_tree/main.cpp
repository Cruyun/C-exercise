#include <iostream>
#include "tree.cpp"
#include "tree.h"

int main() {
    BiNode *T = new BiNode;
    cout << "Create a binary tree:";
    CreatebiTree(T);
    cout << "list datas in order:";
    InOrder(T);
    cout << endl;
    cout << "list datas by floor:";
    traverse(T);

    return 0;
}