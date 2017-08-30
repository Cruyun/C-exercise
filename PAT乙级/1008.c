//数组元素循环右移问题
//输入样例：
//6 2
//1 2 3 4 5 6
//输出样例：
//5 6 1 2 3 4

#include <stdio.h>

int main() {
    int arr[200]={0};
    int n;
    int remove;
    int i;

    scanf("%d %d", &n, &remove);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        arr[n+i]=arr[i];
    }

    for (i = 0; i < n; i++) {
        arr[i]=arr[n-remove+i];
        if(i!=n-1){
        printf("%d ", arr[i]);
        }else printf("%d", arr[i]);
    }
    return 0;
}
