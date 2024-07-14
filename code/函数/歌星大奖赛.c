#include <stdio.h>
int main()
{
	int a[10], mx, mn;
	double sum = 0;
	int i;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	mx = a[0];
	mn = a[0];
	for (i = 1; i < 10; i++)
	{
		if (mx < a[i])
		{
			mx = a[i];
		}
		if (mn > a[i])
		{
			mn = a[i];
		}
	}
	sum = (sum - mn - mx) * 1.0 / 8;
	printf("sum == %.2f", sum);
	return 0;
}
