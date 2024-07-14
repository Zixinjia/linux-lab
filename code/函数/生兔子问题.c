#include <stdio.h>
int a[100];
int f(int n)
{
	if (a[n])
		return;
	if (n == 1 || n == 2)
		a[n] = 1;
	else
		a[n] = f(n - 1) + f(n - 2);
	return a[n];
}
int main()
{
	int n, i;
	a[1] = a[2] = 1;

	scanf("%d", &n);
	int sum = f(n);

	for (i = 0; i < n; i++)
	{
		printf("第%d月兔子的兔子的总数: %d\n", i + 1, 2 * a[i + 1]);
	}
	return 0;
}
