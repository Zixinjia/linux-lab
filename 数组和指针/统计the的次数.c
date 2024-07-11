#include <stdio.h>
int main()
{
	char str[101];
	// 可能有空格
	fgets(str, sizeof str, stdin);
	int i = 0, ans = 0;
	for (i = 2; str[i] != '\0'; i++)
	{
		if (str[i - 2] == 't' && str[i - 1] == 'h' && str[i] == 'e')
		{
			ans++;
		}
	}
	printf("the出现的次数为 %d", ans);
	return 0;
}
