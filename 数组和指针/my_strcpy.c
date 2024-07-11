#include <stdio.h>
const int MaxLen = 10;
void my_strcpy(char *dest, char *src)
{
	int len = 0;
	while (*src != '\0' && len < MaxLen - 1)
	{

		*(dest + len) = *src;
		len++;
		src++;
	}
	// 添加终止符
	*(dest + len) = '\0';
}
int main()
{
	char dest[MaxLen], src[MaxLen];
	scanf("%s", src);
	// 不会溢出目标数组
	my_strcpy(dest, src);
	printf("复制后的字符串 == %s\n", dest);
	return 0;
}
