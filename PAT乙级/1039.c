#include <stdio.h>
#include <string.h>

int main() {
    char a[1000];
    char b[1000];
    int lessNum=0;
    int flag;
    int len1,len2;
    int i,j;

    scanf("%s",a);
    scanf("%s",b);

    len1=strlen(a);
    len2=strlen(b);

    for(i=0;i<len2;i++){
        flag=0;
        for(j=0;j<len1;j++){
            if(b[i]==a[j]) {
                flag=1;
                a[j]='*';
                break;
            }
        }
        if(!flag)
         lessNum++;
    }
    if(lessNum)
        printf("No %d",lessNum);
    else
    printf("Yes %d",len1-len2);

    return 0;
}