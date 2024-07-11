#include <stdio.h>
void translation(char *res, char *str, int m)
{
	char *temp = res;
	// ָ��str����
	char *p1 = str + m;
	// ָ��strǰ��
	char *p2 = str;
	while (*p1 != '\0')
	{
		*temp = *p1;
		p1++;
		temp++;
	}
	int cnt = 0;
	while (cnt < m)
	{
		*temp = *p2;
		p2++;
		temp++;
		cnt++;
	}
}
int main()
{
	int m;
	char str[21], res[21];
	memset(res, '\0', sizeof res);
	memset(str, '\0', sizeof str);
	scanf("%d", &m);
	getchar();
	fgets(str, sizeof str, stdin);
	translation(res, str, m);
	printf("%s\n", res);
	return 0;
}
