max_value(int arr[2][4])
{
    int i,j,maxarr;
    maxarr=arr[0][0];
    for(i=0;i<2;i++){
        for(j=0;j<4;j++){
            if(arr[i][j]>maxarr)
                maxarr=arr[i][j];
        }
    }
    return(maxarr);
}
