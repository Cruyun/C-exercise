//20．(15分)通过循环按行顺序为一个5×5的二维数组a赋1到25的自然数，然后输出该数组的左下半三角。试编程。

#include <stdio.h>

#define H 3
#define L 4
void main()
{
    int i,j,k;
    int a[H][L],min[H];
    int max[H],col=0;
    int super[H];

    for(i=0;i<H;i++)
        for(j=0;j<L;j++)
            scanf("%d",&a[i][j]);

    for(i=0;i<H;i++)
        max[i]=a[i][0];

    for(i=0;i<H;i++) {
        {
            for(j=0;j<L;j++)
                if(a[i][j]>max[i])
                {
                    max[i]=a[i][j];
                    col=j;
                }
        }
        super[i]=col;
    }
    for(i=0;i<H;i++)
        for(k=0;k<H;k++) {
            if(max[i]<=a[k][super[i]])
                min[k]=max[i];
            else
                break;
        }
    printf("鞍点=%d\n",min[H-1]);
}
