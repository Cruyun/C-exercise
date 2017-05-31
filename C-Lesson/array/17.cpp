//17．从键盘输入一个字符，用折半查找法找出该字符在已排序的字符串a中的位置。若该字符不在a中，则打印出**

#include <stdio.h>
int main() {
    char c,a[10]="abcdefghi";
    int top,bot,mid;
    printf("input c:\n");
    scanf("%c",&c);
    printf("c=\'%c\'\n",c);
    for(top=0,bot=10;top<=bot;)  {
        mid=(top+bot)/2;
        if(c==a[mid])   {
            printf("The position is %d\n",mid+1);
            break;
        }
        else if(c>a[mid])
            top=mid+1;
        else bot=mid-1;
    }  if(top>bot)
        printf("**\n");
    return 0;
}
