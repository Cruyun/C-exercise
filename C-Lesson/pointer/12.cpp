// 下面findmax函数将计算数组中的最大元素及其下标值和地址值，请编写* findmax( )函数。
# include <stdio. h>

int *findmax(int *s, int t, int *k) {
    *k = 0;
    for (int i = 0; i < t; i++) {
        if (*(s + *k) < *(s + i)) {
            *k = i;
        }
    }
    return (s + *k);
}

int main( ) {
    int a[10] = {12, 23, 34, 45, 56, 67, 78, 89, 11, 22}, k, *add;
    add = findmax(a, 10, &k);
    printf("%d, %d, %o\n", a[k], k, add);
    return(0);
}
