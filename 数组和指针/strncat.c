#include <stdio.h>
const int MaxLen = 10;
void strncat(char *dest, char *src, int n)
{
	// cnt1统计不超过n
	int cnt1 = 0;
	int len1 = 0, len2 = 0;
	while (dest[len1] != '\0' && len1 < 2 * MaxLen)
	{
		len1++;
	}
	while (src[len2] != '\0' && len2 < MaxLen)
	{
		len2++;
	}
	// cnt2使不越界
	int cnt2 = 0;
	while ((*dest) != '\0')
	{
		dest++;
		cnt2++;
	}
	// 考虑终止符
	while ((*src) != '\0' && cnt2 < MaxLen - 1 && cnt1 < n)
	{
		*dest = *src;
		dest++;
		src++;
		cnt1++;
		cnt2++;
	}
	// 加上终止符
	*dest = '\0';
}
int main()
{
	char dest[2 * MaxLen], src[MaxLen];
	int n;
	scanf("%d", &n);
	scanf("%s%s", dest, src);
	strncat(dest, src, n);
	printf("最终字符串str == %s\n", dest);
	return 0;
}