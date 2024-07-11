#include <stdio.h>

int strncmp(char *s1, char *s2, int n)
{
	int cnt = 0;
	while (*s1 != '\0' && *s2 != '\0' && cnt < n)
	{
		if (*s1 != *s2)
		{
			return *s1 - *s2;
		}
		s1++;
		s2++;
		cnt++;
	}
	if (*s1 == '\0' && *s2 == '\0')
	{
		return 0;
	}
	else
	{
		// 前缀相同，长度不同
		if (*s2 == '\0')
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
	int n;
	scanf("%d", &n);
	scanf("%s%s", s1, s2);
	printf("%d\n", strncmp(s1, s2, n));
	return 0;
}
