#include <stdio.h>
void reverse(int a[], int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		int temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}
int main()
{
	int a[100], n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	reverse(a, n);
	// 输出逆序后结果
	for (int i = 0; i < n; i++)
	{
		printf("a[%d] == %d\n", i, a[i]);
	}
}
