//说反话
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sentence[100]={0};
    int flag = 0;
    int len = 0;
    int i = 0;
    int j = 0;

    gets(sentence);

    //计算句子的长度
    while (sentence[i]!= '\0'){
        len++;
        i++;
    }
    flag = len;

    //从句子结尾往前扫描
    for(i=len; i>=0; i--){
        if (sentence[i]==' '){
            for (j = i+1; j < flag; j++) {
                printf("%c", sentence[j]);
            }
            printf(" ");
            flag=i;
        }
    }
    for (j = 0; j < flag; j++) {
        printf("%c", sentence[j]);
    }
    return 0 ;
}