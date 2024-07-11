#include <stdio.h>
const int MaxLen = 500;
char *my_strcpy_end(char *dest, char *src)
{
	int len = 0;
	while (*src != '\0' && len < MaxLen - 1)
	{

		*dest = *src;
		dest++;
		src++;
		len++;
	}
	// 添加终止符
	*dest = '\0';
	return dest;
}
int main()
{
	char dest[MaxLen], src[MaxLen];
	memset(dest, '\0', sizeof dest);
	scanf("%s", src);
	char *p = my_strcpy_end(dest, src);
	return 0;
}
