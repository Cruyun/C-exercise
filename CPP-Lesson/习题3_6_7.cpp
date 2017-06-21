// œ∞Ã‚3_6_7.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;


int **Make2DArray(int m, int n)
{
    int ** dm, i, j;
    dm = new int * [m];

    for (i = 0; i < m; i++)
        if ((dm[i] = new int [n]) == NULL)
            exit(0);
    return dm;
}


void Delete2DArray(int m, int **dm)
{
    for(int i =0; i < m; i++)
        delete[]dm[i];
    delete[]dm;
}

int main()
{
    int m,n,k, i,j,p;
    cout << "input matrix size m,n,k:";
    cin >> m >> n >> k;

    int ** d1, **d2, **d3;
    d1 = Make2DArray(m,n);
    for (i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            cin >> d1[i][j];
    }
    
    d2 = Make2DArray(n,k);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
            cin >> d2[i][j];
    }

    d3 = Make2DArray(m,k);

    for (i = 0; i < m; i++)
        for ( j = 0; j < k; j++)
            for (p = 0; p < n; p++)
                d3[i][j]+=d1[i][p]*d2[p][j];

    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++)
            cout << d3[i][j] << "\t";
        cout << endl;
    }
        Delete2DArray(m,d1);
        Delete2DArray(n,d2);
        Delete2DArray(m,d3);

        return 0;
    }
