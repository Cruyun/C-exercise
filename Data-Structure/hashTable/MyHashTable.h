#include <iostream>
using namespace std;

typedef int Elemtype;
typedef int Keytype;
typedef int Status;

const int NULLKEY = INT_MAX; //NULLKEY表示该位置无值
const int SUCCESS = 1;
const int UNSUCCESS = 0;
const int DUPLICATE = -1;
const int OK = 1;

//unsigned int hashsize[] = {3, 7, 11, 17, 23};
unsigned int hashsize[] = {11, 17, 19, 29, 37, 47, 59};

typedef struct {
    Keytype key;
    Elemtype value;
} Element;

typedef struct {
    Element *elem;
    int count;
    int sizeindex;
} HashTable;

void initHashTable(HashTable &hTable);
void delHashTable(HashTable &hTable);
unsigned Hash(HashTable &hTable, Keytype k);
void Collision(HashTable &hTable, int &p, int c);
void Traverse_HashTable(HashTable hTable);
Status InsertHash(HashTable &H, Element e);
void RecreateHashTable(HashTable &H);
Status SearchHash(HashTable H, Keytype kval, int &p, int &c);
void ReadData(HashTable H, int p);

//初始化
void initHashTable(HashTable &hTable){

    hTable.sizeindex = 0;
    hTable.count = 0;
    unsigned int tableSize = hashsize[hTable.sizeindex];
    hTable.elem = new Element[tableSize];
    if (hTable.elem == NULL) {
        cout << "内存申请失败" << endl;
        exit(0);
    }
    else {
        for (unsigned int i = 0; i < tableSize; i++) {
            hTable.elem[i].key = NULLKEY;
        }
    }
}

void delHashTable(HashTable &hTable){
    hTable.sizeindex = 0;
    hTable.count = 0;
    delete hTable.elem;
    hTable.elem = NULL;
}

unsigned Hash(HashTable &hTable, Keytype k){
    unsigned int Hash_length = hashsize[hTable.sizeindex];
    return k % Hash_length;
}

void Collision(HashTable &hTable, int &p, int c)
{
    unsigned int Hash_length = hashsize[hTable.sizeindex];
    p = (p + c) % Hash_length; 
}


void Traverse_HashTable(HashTable hTable)
{
    unsigned int Hash_length = hashsize[hTable.sizeindex];
    cout << "hash_length: " << Hash_length << endl;
    cout << "hash address: 0->" << Hash_length - 1 << endl;
    for (int i = 0; i< Hash_length; i++)
        if (hTable.elem[i].key != NULLKEY)
            cout << "the element's key and value are: " << hTable.elem[i].key << "  " << hTable.elem[i].value << endl;
}

Status InsertHash(HashTable &H, Element e) {
    int c;
    int j;
    if (SearchHash(H, e.key, j, c) == SUCCESS) {
        return DUPLICATE;
    } else if (c < hashsize[H.sizeindex] / 2) {
        H.elem[j] = e;
        H.count++;
        return OK;
    } else {
        RecreateHashTable(H);
        return 0;
    }
}

void RecreateHashTable(HashTable &H) {
    int i;
    int num = H.count;
    Element  *p, *elm2;
    elm2 = new Element[num];
    p = elm2;
    cout << "Recreate: " << endl;
    unsigned int Hash_length = hashsize[H.sizeindex];
    for (i = 0; i < Hash_length; ++i) {
        if (H.elem[i].key != NULLKEY) {
            *p++ = *(H.elem + i);
        }
    }
    H.count = 0;
    delete []H.elem;
    H.sizeindex++;
    Hash_length = hashsize[H.sizeindex];
    p = new Element[Hash_length];
    if (!p) {
        cout << "fail" << endl;
        exit(0);
    }
    H.elem = p;
    for (i = 0; i < Hash_length; ++i) {
        H.elem[i].key = NULLKEY;
    }
    for (p = elm2; p < elm2 + num; ++p) {
        InsertHash(H,*p);
    }
}

Status SearchHash(HashTable H, Keytype kval, int &p, int &c) {
    p = Hash(H, kval);
    c = 0;
    while (H.elem[p].key != NULLKEY && (H.elem[p].key != kval)) {
        Collision(H, p, ++c);
    }
    if (H.elem[p].key == kval)
        return SUCCESS;
    else
        return UNSUCCESS;
}

void ReadData(HashTable H, int p) {
    cout << "the element's key and value are: " << H.elem[p].key << "  "<<H.elem[p].value<<endl;
}