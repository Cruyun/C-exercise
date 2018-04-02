#include <iostream>
using namespace std;

int main()
{
	int sum = 1;
	int num = 1;
	
	while(sum % 2013) {
		num++;
		sum = (sum % 2013) * 10 + 1; 
	}
	cout << num;
	return 0;
}
