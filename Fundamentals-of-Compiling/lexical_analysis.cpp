// t1.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <fstream>
#include <string>
#define _KEY_WORD_END "waiting for your expanding"
using namespace std;
typedef struct
{
    int typenum;
    char* word;
}WORD;

char ch;
char input[255];
char token[255] = "";
int p_input;
int p_token;
char* rwtab[] = {"begin","if","then","while","do","end",_KEY_WORD_END};
WORD finalR[255];
int m = 0;
char str[20] = "";
char result[255];
void readFromFile();
void writeToFile();
WORD* scaner();
void retract();
char m_getch();
void getbc();
void concat();
int letter();
int digit();
int reserve();
int dtb(int d,char str[]);
// void readLexical();
int main(){
    int over = 1;
    WORD* oneword = new WORD;
	readFromFile();
    p_input = 0;
	printf("Your words: \n %s\n",input);
    while(over < 1000 && over != -1){
        oneword = scaner();
        if(oneword->typenum < 1000){
			finalR[m].typenum = oneword->typenum;
			finalR[m].word = oneword->word;
			printf("(%d,%s)\n",finalR[m].typenum,finalR[m].word);
			m++;
        }
        over = oneword->typenum;
    }
	writeToFile();

    // readLexical();
    // printf("result: \n %c \n", result[0]);
	return 0;
}
//read file
void readFromFile(){
	int x;
	FILE *fp;
	printf("please choose one file(1/2):\n");
	printf("----1.data1.txt----\n");
	printf("----2.data2.txt----\n");
	scanf("%d",&x);
	if(x == 1)
		fp = fopen("data1.txt","r");
	else if(x == 2)
		fp = fopen("data2.txt","r");
	else{
		printf("The file doesn't exist!!");
		return;
	}
	int i = 0;
    if (!fp) 
        return;
    while (!feof(fp)){ 
		fread(input, sizeof( char ),250,fp);
	}
    fclose(fp);
}

// write to file
void writeToFile(){
	FILE *fp = fopen("result.txt","w");
	for(int i = 0; i < m; i++)
		fprintf(fp,"(%d,%s)\n",finalR[i].typenum,finalR[i].word);
	fclose(fp);
}

char m_getch(){
	if(ch == '#')
		ch = ' ';
    ch = input[p_input];
    p_input = p_input + 1;
    return (ch);
}

void getbc(){
    while(ch == ' ' || ch == 10){
        ch = input[p_input];
        p_input = p_input + 1;
    }
}

void concat(){
    token[p_token] = ch;
    p_token = p_token + 1;
    token[p_token] = '\0';
}

int letter(){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1;
    else
        return 0;
}

int digit(){
    if(ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}

int reserve(){
    int i = 0;
    while(strcmp(rwtab[i],_KEY_WORD_END)){
        if(!strcmp(rwtab[i],token)){
            return i+1;
        }
        i= i + 1;
    }
    return 10;
}

void retract(){
	p_input = p_input-1; 
}

int dtb(int d,char str[]){
	char tmp,temp[2] = "";
	for(int p = 0;p < 20;p++)
		str[p] = 0;
	int i = 0;
	while(d){
		// itoa(d%2,temp,10);
		str[i] = temp[0];
		d = d/2;
		i++;
	}
	i--;
	int len = i + 1;
	for(int j = 0; j < len / 2;j++,i--){
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
	}
	return len;
}

WORD* scaner(){
    WORD* myword = new WORD;
    myword->typenum = 10;
    myword->word = "";
    p_token = 0;
    m_getch();
    getbc();
    if(letter()){
        while(letter() || digit()){
            concat();
            m_getch();
        }
        retract();
        myword->typenum = reserve();
        myword->word = token;
        return(myword);
    }
	else if(digit()){
        while(digit()){
            concat();
            m_getch();
        }
        retract();
        myword->typenum = 11;
		// int d = atoi(token);
		// int len = dtb(d,str);
		// str[len] = '\0';
        myword->word = token;
        return(myword);
    }
    else switch(ch){
        case '=':
            m_getch();
            if(ch == '='){
                myword->typenum = 39;
                myword->word = "==";
                return(myword);
            }
            retract();
            myword->word = "=";
            myword->typenum = 21;
            return(myword);
            break;
        case '+':
            myword->typenum = 22;
            myword->word = "+";
            return(myword);
            break;
        case '-':
            myword->typenum = 23;
            myword->word = "-";
            return(myword);
            break;
        case '*':
            myword->typenum = 24;
            myword->word = "*";
            return(myword);
            break;
        case '/':
            myword->typenum = 25;
            myword->word = "/";
            return(myword);
            break;
        case '(':
            myword->typenum = 26;
            myword->word = "(";
            return(myword);
            break;
        case ')':
            myword->typenum = 27;
            myword->word = ")";
            return(myword);
            break;
        case '[':
            myword->typenum = 28;
            myword->word = "[";
            return(myword);
            break;
        case ']':
            myword->word = "]";
            myword->typenum = 29;
            return(myword);
            break;
        case '{':
            myword->typenum = 30;
            myword->word = "{";
            return(myword);
            break;
        case '}':
            myword->typenum = 31;
            myword->word = "}";
            return(myword);
            break;
        case ',':
            myword->typenum = 32;
            myword->word = ",";
            return(myword);
            break;
        case ':':
            m_getch();
            if (ch == '=') {
                myword->typenum = 18;
            myword->word = ":=";
            return myword;
            break;
            }
            retract();
            myword->typenum = 17;
            myword->word = ":";
            return(myword);
            break;
            
        case ';':
            myword->typenum = 34;
            myword->word = ";";
            return(myword);
            break;
        case '>':
            m_getch();
            if(ch == '='){
                myword->word = ">=";
                myword->typenum = 37;
                return(myword);
            }
            retract();
            myword->typenum = 35;
            myword->word = ">";
            return(myword);
            break;
        case '<':
            m_getch();
            if(ch == '='){
                myword->word = "<=";
                myword->typenum = 38;
                return(myword);
            }
            retract();
            myword->typenum = 36;
            myword->word = "<";
            return(myword);
            break;
        case '!':
            m_getch();
            if(ch == '='){
                myword->word = "!=";
                myword->typenum = 40;
                return(myword);
            }
            retract();
            myword->typenum = -1;
            myword->word = "ERROR";
            return(myword);
            break;
        case '\0':
            myword->typenum = 1000;
            myword->word = "OVER";
            return (myword);
            break;
        default:
            printf("%c error", ch);
            myword->typenum = -1;
            myword->word = "Error";
            return(myword);
    }
}

// void readLexical(){
//     ifstream fin("result.txt");  
//     string s;  
//     while( getline(fin,s) )
//     {    
//         cout << "Read from file: " << s << endl; 
//     }
// }