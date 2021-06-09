#include <stdio.h>

int main()
{
	int i = 0;
	unsigned char c;

	c = 200;
	while (i < 100)
	{
		printf("%lc",c);
		i++;
	}
	printf("\n");
}
