#include <stdio.h>

void br(void);
void ic(void);
int main()
{
    printf("Brazil, Russia, India, China\n");
    ic();
    br();

    return 0;
}

void br(void)
{
    printf("Brazil, Russia\n");
}

void ic(void)
{
    printf("India, China\n");
}
