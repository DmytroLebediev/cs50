#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

int main()
{
	byte a = 1;  // 0000 0001
	byte b = 9;  // 0000 1001

	printf("%d\n", a&b);
	printf("%d\n", a&&b);

	printf("%d\n", a|b);
	printf("%d\n", a||b);

	printf("%d\n", !b);
	printf("%d\n", ~b);

	printf("%d\n", a^b);

	printf("%d\n", a << 2);
	printf("%d\n", b << 2);

	return 0;
}