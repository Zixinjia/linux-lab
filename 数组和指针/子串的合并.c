#include <stdio.h>
#include <string.h>
void merge(char *s1, char *s2, char *res)
{
	char *temp = res;
	while (*s1 != '\0' && *s2 != '\0')
	{
		*temp = *s1;
		temp++;
		*temp = *s2;
		temp++;
		s1++;
		s2++;
	}
	while (*s1 != '\0')
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*temp = *s2;
		temp++;
		s2++;
	}
}
int main()
{
	char s1[27];
	char s2[27];
	char res[60];
	// 不用在merge里加上终止符了
	memset(res, '\0', sizeof res);
	fgets(s1, sizeof s1, stdin);
	fgets(s2, sizeof s2, stdin);
	merge(s1, s2, res);
	printf("合并后的串为: %s\n", res);
	return 0;
}
