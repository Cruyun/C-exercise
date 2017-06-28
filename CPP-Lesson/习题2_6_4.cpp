// 习题2_6_4.cpp : Defines the entry point for the console application.
#include <iostream>

using namespace std;

template <class T>

void fun(T n)
{

	T result(1), pre(1),result2(1),r(1);

	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		pre *= (i-1);
		result *= i;
		if ((result / i) != pre ){
		result2 = pre;
		r = i;
		break;
		}
	}

	if (result2) {
			cout << "溢出" <<endl;
			cout << result2 << endl;
			cout << "溢出前n为"<< r << endl;
	}
}
int main ()
{
	fun<int>(32);
	fun<long int>(32);
	fun<short int>(32);
	fun<char>(1000);
	return 0;
}