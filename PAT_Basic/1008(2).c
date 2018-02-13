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
    int i,j;


    scanf("%d %d", &n, &remove);

    for (i = 0; i<n; i++) {
        remove = remove % n;
        scanf("%d", &arr[remove]);
        remove++;
    }

    for (j = 0; j < n-1; j++) {
        printf("%d ",arr[j]);
    }
    printf("%d", arr[n-1]);
    return 0;
}