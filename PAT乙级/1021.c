#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s",s);

    int num[10]={0};
    int i;

    for(i=0;i<strlen(s);i++){
        num[s[i]-'0']++;
    }

    for(i=0;i<10;i++){
        if (num[i]!=0)
            printf("%d:%d\n",i,num[i]);
    }

    return 0;
}

// #include <stdio.h>
//
// int main() {
//     int s[1000];
//     int num;
//     int p=0;
//     int q=0;
//     int len=0;
//     int count=0;
//
//     scanf("%d",&num);
// if(num==0)
// printf("0:1");
//     while(num){
//         s[q]=num%10;
//         num = num / 10;
//         q++;
//         len=q;
//     }
//
//     for(p=0;p<=9;p++){
//         for (q=0; q < len ; q++) {
//             if (p == s[q])
//                 count++;
//         }
//         if(count!=0)
//         printf("%d:%d\n", p, count);
//         count=0;
//     }
//     return 0;
// }
