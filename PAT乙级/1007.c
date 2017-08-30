#include<stdio.h>
#include<math.h>
int isprime(int n);
int main()
{
    int prime_pre,prime_next,i,j,n;
    int count = 0;

    scanf("%d",&n);

    for(i=2;i<=n;i++)
    {
        if(isprime(i))
        {
            prime_pre=i;
            for(j=i+1;j<=n;j++)
            {
                if(isprime(j))
                {
                    prime_next=j;
                    break;
                }
            }
            if(prime_next-prime_pre==2)
            {
                count++;
            }
            i=j-1;
        }
    }
    printf("%d\n",count);
    return 0;
}
int isprime(int n)
{
    int i;

    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
