// 习题2_6_4.cpp : Defines the entry point for the console application.
#include <iostream>

using namespace std;

int main ()
{
	int n;
	int result(1), pre(1),result2(1),r(1);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		pre *= i;
		result = pre * ( i + 1);
		if (result < 0 && pre > 0) {
		result2 = pre;
		r = i;
		}
	}

	if (result2) {
			cout << "溢出" <<endl;
			cout << result2 << endl;
			cout << "溢出前n为"<< r << endl;
	}
	return 0;
}