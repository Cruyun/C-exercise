#include <iostream>
#include "MyHashTable.h"

using namespace std;

int main() {
    HashTable myHtable;
    Element ele[11] = {{17,1},{40,2},{19,3},{18,4},{1,0},{2,6},{4,8},{5,9},{6,10},{7,13},{8,12}};
    int i, p, j;
    int c = 0;
    Keytype find;
    initHashTable(myHtable);
    for (i = 0; i < 10; ++i) {
        j = InsertHash(myHtable, ele[i]);
        if (j == DUPLICATE) {
            cout << "The key has existed: key : " << ele[i].key << "  value: "<< ele[i].value << endl;
        }
    }

    cout << "Traverse the hash table:" << endl;
    Traverse_HashTable(myHtable);
    cout << endl;

    cout << "input the key you want to find：";
    cin >> find;
    j = SearchHash(myHtable, find, p, c);
    if (j == OK) {
        ReadData(myHtable, p);
    } else {
        cout << "it is not exist" << endl;
    }

    j = InsertHash(myHtable, ele[10]);
    if (j == UNSUCCESS) {
        cout << "insert fail" << endl;
        cout << "Recreate hash table" << endl;
        RecreateHashTable(myHtable);
    }
    cout << "Traverse the new hash table:" << endl;
    Traverse_HashTable(myHtable);
    cout << endl;

    cout << "input the key you want to find：";
    cin >> find;
    j = SearchHash(myHtable, find, p, c);
    if (j == OK)
        ReadData(myHtable, p);
    else
        cout << "it is not exist" << endl;

    cout << "delete hash table" << endl;
    delHashTable(myHtable);
    return 0;
}