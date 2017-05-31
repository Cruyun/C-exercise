#include <stdio.h>
#include <conio.h>

void main()
{
    char x, c, d;
	x = getch();
	scanf("%c", &x);

	if(x == 'a')
	  c = 'z';
	  else c = x - 1;
	if(x == 'z')
	d = 'a';
	else d = x + 1;

	printf("%c的前一位为%c,后一位字母为%c\n", x, c, d);
}
