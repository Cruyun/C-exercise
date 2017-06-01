//部分正确
#include <stdio.h>
typedef struct info{
    int saveNum;
    int sum;
    double price;
} mooncake;

//比较单价
void sort(mooncake *get,int N)
{
    int i = 0, j = 0;
    mooncake t;
    for(i = 0;i < N - 1;i++)
    {
        for(j = i + 1;j < N; j++) {
            if(get[i].price < get[j].price) {
                t = get[i];
                get[i] = get[j];
                get[j] = t;
            }
        }
    }
}

int main()
{
    int N;
    int need;
    mooncake get[1000];
    double money = 0;
    int i;

    scanf("%d %d",&N,&need);

    for(i = 0;i < N;i++) {
        scanf("%d",&get[i].saveNum);
    }
    for(i = 0;i < N;i++) {
        scanf("%d",&get[i].sum);
        get[i].price = (double)get[i].sum / (double)get[i].saveNum;
    }

    sort(get,N);

    i = 0;

    while(need)
    {
        if(need > get[i].saveNum) {
            money += get[i].sum;
            need -= get[i].saveNum;
            } else {
            money += need * get[i].price;
            need = 0;
            }
        i++;
        }
    printf("%.2lf\n",money);
    return 0;
}
