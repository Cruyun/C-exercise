isprime(int a)
{
    int b,i;
    b=sqrt(a);
    for(i=b;i>1;i--){
        if(a%i==0)
            return 0;
    }
    return 1;

}
