#include <stdio.h>

int main() {
    int n;
    int num[1001];
    int i,j=1;
    int a1=0;
    int a2[1001];
    int A2=0;
    int k;
    int a3=0;
    int sum=0;
    float count=0;
    float a4;
    int a5=0;

    scanf("%d",&n);
    for (i = 0; i <n ; i++) {
        scanf("%d",&num[i]);
    }

    for(i=0;i<n;i++){
        if(num[i]%5==0 && num[i]%2==0)
            a1+=num[i];
    }

    for (i=0;i<n;i++){
        if (num[i]%5 == 1){
            a2[j] = num[i];
            j++;
        }
    }

    k = j;
    for (j = 1;j < k ; j++){
        if (j%2 == 1)
            A2 += a2[j];
        else
            A2-= a2[j];
    }

    for(i=0;i<n;i++){
        if (num[i]%5==2)
            a3++;
    }

    for(i=0;i<n;i++){
        if(num[i]%5==3) {
            sum += num[i];
            count++;
        }
    }
    a4=sum / count;

    for (i=0;i<n;i++){
        if (num[i]%5 ==4&&num[i]>a5){
            a5=num[i];
        }
    }

    if (a1 == 0)
        printf("N");
    else
        printf("%d",a1);
    if (k == 1)
        printf(" N");
    else
        printf(" %d",A2);
    if (a3 == 0)
        printf(" N");
    else
        printf(" %d",a3);
    if (sum == 0)
        printf(" N");
    else
        printf(" %.1f",a4);
    if (a5 == 0)
        printf(" N");
    else
        printf(" %d",a5);

    return 0;
}
