//11．(14分)从键盘输入若干整数（数据个数应至少于50），其值在0至4的范围内，用-1作为输入结束的标志。统计每个整数的个数。试编程。

#include <stdio.h>

int main() {
    int num[51];
    int i;

    for(i=0;i<=51;i++){
        scanf("%d",&num[i]);

        if(num[i]==-1)
            break;
        else if (num[i]<0||num[i]>4){
            printf("值在0至4的范围内");
            break;
        }
    }
    printf("个数%d",i);
    return 0;
}
