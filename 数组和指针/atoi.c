#include <stdio.h>
int atoi(char *s)
{
	int res = 0;
	while (*s != '\0')
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return res;
}
int main(int argc, char *argv[])
{
	int val;
	char str[20];
	scanf("%s", str);
	val = atoi(str);
	printf("val == %d\n", val);
	return 0;
}
