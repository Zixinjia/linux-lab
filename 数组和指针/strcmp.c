#include <stdio.h>

int strcmp(char *p1, char *p2)
{

	while (*p1 != '\0' && *p2 != '\0')
	{
		if (*p1 != *p2)
		{
			return *p1 - *p2;
		}
		p1++;
		p2++;
	}
	// 前缀相同且长度相同
	if (*p1 == '\0' && *p2 == '\0')
	{
		return 0;
	}
	else
	{
		// 前缀相同，长度不同
		if (*p2 == '\0')
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
}

int main()
{
	char s1[100], s2[100];
	scanf("%s%s", s1, s2);
	printf("%d\n", strcmp(s1, s2));
	return 0;
}
