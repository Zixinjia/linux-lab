#include <stdio.h>
int a[100], b[100];
int c[200];
int h[10010]; //哈希表
int main()
{
	// Lc的大小
	int size = 0;
	//线性表元素个数
	int n1, n2;
	printf("请输入集合A和B的元素个数\n");
	scanf("%d %d", &n1, &n2);
	printf("请输入集合A的元素:\n");
	for (int i = 0; i < n1; i++)
	{
		scanf("%d", &a[i]);
		h[a[i]] = 1;
	}
	printf("请输入集合B的元素:\n");
	for (int i = 0; i < n2; i++)
	{
		scanf("%d", &b[i]);
		h[b[i]] = 1;
	}
	//合并
	for (int i = 0; i < 10010; i++)
	{
		if (h[i])
		{
			c[size++] = i;
		}
	}
	printf("线性表C的元素是:");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", c[i]);
	}
	return 0;
}
