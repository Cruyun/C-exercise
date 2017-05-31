#include <stdio.h>

#define number 5
#define failed -1

int search(int v[], int key, int n)
{
    int i = 0;

    v[n] = key;

    while(1) {
        if (v[i] == key)
            break;
        i++;
    }

    return (i < n ? i :failed);
}

int main(void)
{
    int i, ky, idx;
    int vx[number + 1];

    for (int i = 0; i < number; i++) {
        printf("vx[%d]", i);
        scanf("%d", &vx[i]);
    }
    printf("要查找的值：");
    scanf("%d", &ky);

    if ((idx = search(vx, ky, number)) == failed)
        puts("\a失败");
    else
        printf("%d是数组的第%d号元素 \n", ky, idx + 1);

    return 0;

}
