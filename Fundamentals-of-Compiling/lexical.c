#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _KEY_WORD_END "waiting for your expanding"
typedef struct WORD{
    int typenum;
    char *word;
} WORD;
char input[255];
char token[255] = "";
int p_input;
int p_token;
char ch;
char *rwtab[] = {"begin", "if", "then", "while", "do", "end", _KEY_WORD_END};
WORD *scaner();

int main() {
  int over = 1;
  struct WORD *oneword;
  printf("Enter Your Word(end with #):");
  scanf("%[^#]s", input);
  p_input = 0;
  printf("Your words: \n%s\n", input);
  while (over < 1000 && over != -1) {
    oneword = scaner();
    if (oneword->typenum < 1000) {
      printf("(%d,%s)", oneword->typenum, oneword->word);
    }
    over = oneword->typenum;
  }
  printf("\npress # to exit");
  scanf("%[^#]s", input);
  return 0;
}

char m_getch() {
  ch = input[p_input];
  p_input = p_input + 1;
  return (ch);
}

void getbc() {
  while (ch == ' ' || ch == 10 ) {
    ch = input[p_input];
    p_input = p_input + 1;
  }
}

void concat() {
  token[p_token] = ch;
  p_token = p_token + 1;
  token[p_token] = '\0';
}

int letter() {
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
    return 1;
  }
  return 0;
}

int digit() {
  if (ch >= '0' && ch <= '9') {
    return 1;
  }
  return 0;
}

int reserve() {
  int i = 0;
  while (strcmp(rwtab[i], _KEY_WORD_END)) {
    if (!strcmp(rwtab[i], token)) {
      return i + 1;
    }
    i = i + 1;
  }
  return 10;
}

void retract() {
  p_input = p_input - 1;
}

char *dtb(int n) {
  int c, d, count;
  char *pointer;

  count = 0;
  pointer = (char*)malloc(32+1);

  if (pointer == NULL)
    exit(EXIT_FAILURE);

  for (c = 31 ; c >= 0 ; c--) {
    d = n >> c;

    if (d & 1)
      *(pointer+count) = 1 + '0';
    else
      *(pointer+count) = 0 + '0';

    count++;
  }
  *(pointer+count) = '\0';

  return pointer;
}

WORD *scaner() {
  struct WORD *myword;
  myword->typenum = 10;
  myword->word = "";
  p_token = 0;
  m_getch();
  getbc();
  if (letter()) {
    while (letter() || digit()) {
      concat();
      m_getch();
    }
    retract();
    myword->typenum = reserve();
    myword->word = token;
    return myword;
  } else if (digit()) {
    while (digit()) {
      concat();
      m_getch();
    }
    retract();
    myword->typenum = 20;
    myword->word = token;
    return myword;
  } else {
    switch (ch) {
      case '=': {
        m_getch();
        if (ch == '=') {
          myword->typenum = 39;
          myword->word = "==";
          return myword;
        }
        retract();
        myword->typenum = 21;
        myword->word = "=";
        return myword;
        break;
      }
      case '+': {
        myword->typenum = 22;
        myword->word = "+";
        return myword;
        break;
      }
      case '-': {
        myword->typenum = 23;
        myword->word = "-";
        return myword;
        break;
      }
      case '*': {
        myword->typenum = 24;
        myword->word = "*";
        return myword;
        break;
      }
      case '/': {
        myword->typenum = 25;
        myword->word = "/";
        return myword;
        break;
      }
      case '(': {
        myword->typenum = 26;
        myword->word = "(";
        return myword;
        break;
      }
      case ')': {
        myword->typenum = 27;
        myword->word = ")";
        return myword;
        break;
      }
      case '[': {
        myword->typenum = 28;
        myword->word = "[";
        return myword;
        break;
      }
      case ']': {
        myword->typenum = 29;
        myword->word = "]";
        return myword;
        break;
      }
      case '{': {
        myword->typenum = 30;
        myword->word = "{";
        return myword;
        break;
      }
      case '}': {
        myword->typenum = 31;
        myword->word = "}";
        return myword;
        break;
      }
      case ',': {
        myword->typenum = 32;
        myword->word = ",";
        return myword;
        break;
      }
      case ':': {
        myword->typenum = 33;
        myword->word = ":";
        return myword;
        break;
      }
      case ';': {
        myword->typenum = 34;
        myword->word = ";";
        return myword;
        break;
      }
      case '>': {
        m_getch();
        if (ch == '=') {
          myword->typenum = 37;
          myword->word = ">=";
          return myword;
        }
        retract();
        myword->typenum = 35;
        myword->word = ">";
        return myword;
        break;
      }
      case '<': {
        m_getch();
        if (ch == '=') {
          myword->typenum = 38;
          myword->word = "<=";
          return myword;
        }
        retract();
        myword->typenum = 36;
        myword->word = "<";
        return myword;
        break;
      }
      case '!': {
        m_getch();
        if (ch == '=') {
          myword->typenum = 40;
          myword->word = "!=";
          return myword;
        }
        retract();
        myword->typenum = -1;
        myword->word = "ERROR";
        return myword;
        break;
      }
      case '\0': {
        myword->typenum = 1000;
        myword->word = "OVER";
        return myword;
        break;
      }
      default: {
        myword->typenum = -1;
        myword->word = "ERROR";
        return myword;
      }
    }
  }
}