#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *insert(const char *s1, const char *s2, int n)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int len = len1 + len2;
	// 为新字符串分配内存
	char *result = (char *)malloc((len + 1) * sizeof(char));
	// 复制 s1 的前半部分到新字符串
	strncpy(result, s1, n);
	// 插入 s2
	strcpy(result + n, s2);
	// 复制 s1 的后半部分到新字符串
	strcpy(result + n + len2, s1 + n);
	return result;
}

int main()
{
	char s1[100], s2[100];
	int n;

	scanf("%d", &n);
	scanf("%s%s", s1, s2);
	char *result = insert(s1, s2, n);

	// 输出结果
	printf("插入后得到的字符串为: %s\n", result);

	free(result);

	return 0;
}