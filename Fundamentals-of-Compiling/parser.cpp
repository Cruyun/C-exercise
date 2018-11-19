#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

typedef struct {
    int typenum;
    char word[255];
} WORD ;

WORD one;
WORD input[100];

int windex = 0;
int kk = 0;

void scannext();
void lrparser();
void yucu();
void statement();
void expression();
void term();
void factor();

int main() {
    FILE* f = fopen("result.txt", "r");
    int count = 0;
    while( fscanf(f, "(%d, %s )\n", &input[count].typenum, input[count].word ) != -1) {
		count++;
	}
	scannext();
	lrparser();
    return 0;
}


void scannext() {
    one = input[windex];
    windex += 1;
}

void lrparser() {
    if (one.typenum == 1) {
        scannext();
        yucu();
        if(one.typenum == 6) {
            scannext();
            if(one.typenum == 0 && kk == 0) {
                cout << "success" << endl;
            }
        }
        else {
            if(kk != 1) {
                cout << "end error" << endl;
                kk = 1;
            }
        }
    }
    else {
        cout << "begin error" << endl;
        kk = 1;
    }
    return;
}

void yucu() {
    statement();
    while(one.typenum == 34) {
        scannext();
        statement();
    }
    return;
}

void statement() {
    if(one.typenum == 10) {
        scannext();
        if(one.typenum == 18) {
            scannext();
            expression();
        }
        else {
            cout << "赋值号 error" << endl;
            kk = 1;
        }
    }
    else {
        cout << "statement error" << endl;
        kk = 1;
    }
    return;
}


void expression() {
    term();
    while(one.typenum == 22 || one.typenum == 23) {
        scannext();
        term();
    }
    return;
}

void term() {
    factor();
    while(one.typenum == 24 || one.typenum == 25) {
        scannext();
        factor();
    }
    return;
}

void factor() {
    if(one.typenum == 10 || one.typenum == 11) {
        scannext();
    }
    else if(one.typenum == 26) {
        scannext();
        expression();
        if(one.typenum == 27) {
            scannext();
        }
        else {
            cout << ") error" << endl;
            kk = 1;
        }
    }
    else {
        cout << "factor error" <<endl;
        kk = 1;
    }
    return;
}

