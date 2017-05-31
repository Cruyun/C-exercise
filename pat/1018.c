#include <stdio.h>
//C锤子 B布 J剪刀
int main() {
    int num;
    scanf("%d", &num);

    char a, b;
    int a_win=0;
    int a_lose=0;
    int no_win=0;
    int a_B_win=0, a_J_win=0, a_C_win=0;
    int b_B_win=0, b_J_win=0, b_C_win=0;

    while (num--){
        getchar();
        scanf("%c %c",&a, &b);

        if(a==b)
            no_win++;
        if(a=='C' && b=='J'){
            a_C_win++;
            a_win++;
        }
        if(a=='J' && b=='B'){
            a_J_win++;
            a_win++;
        }
        if(a=='B' && b=='C'){
            a_B_win++;
            a_win++;
        }
        if(b=='B' && a=='C'){
            b_B_win++;
            a_lose++;
        }
        if(b=='C' && a=='J'){
            b_C_win++;
            a_lose++;
        }
        if(b=='J' && a=='B'){
            b_J_win++;
            a_lose++;
        }
    }
    printf("%d %d %d\n",a_win,no_win,a_lose);
    printf("%d %d %d\n",a_lose,no_win,a_win);

    char aMax = 'B';
    char bMax = 'B';

    if(a_C_win >= a_J_win && a_C_win > a_B_win)
        aMax = 'C';
    if(a_J_win > a_C_win && a_J_win > a_B_win)
        aMax = 'J';
    if(b_C_win >= b_J_win && b_C_win > b_B_win)
        bMax = 'C';
    if(b_J_win >= b_C_win && b_J_win > b_B_win)
        bMax = 'J';

    printf("%c %c\n", aMax, bMax);
    return 0;
}