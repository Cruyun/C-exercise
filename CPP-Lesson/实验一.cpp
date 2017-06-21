// สตั้าป.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
using namespace std;

template <class T>

T **Make2DArray(T m, T n)
{
	int ** dm, i, j;
	dm = new int * [m];

	for (i = 0; i < m; i++)
		if ((dm[i] = new int [n]) == NULL)
			exit(0);
	for (i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
			cin >> dm[i][j];
	}
	for (i = 0; i < m; i++)
	{
		for (int j =0; j < n; j++)
			cout << dm[i][j]<<"\t";
		cout << endl;
	}

	return dm;
}

template <class T>

void Delete2DArray(int m, T **dm)
{
	for(int i =0; i < m; i++)
		delete[]dm[i];
	delete[]dm;
}

int main()
{
	int m,n;
	cout << "input matrix size m,n:";
	cin >> m >> n;

	int ** dm;
	dm = Make2DArray <int> (m,n);
	Delete2DArray <int> (m,dm);

	return 0;
}

