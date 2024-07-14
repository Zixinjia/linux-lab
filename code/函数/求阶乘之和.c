#include <stdio.h>
int f(int x)
{
	int sum = 1;
	int i = 0;
	for (i = x; i >= 1; i--)
	{
		sum *= i;
	}
	return sum;
}

int main()
{
	int m, n, k;
	scanf("%d %d %d", &m, &n, &k);
	int S = f(m) + f(n) + f(k);
	printf("S = %d\n", S);
	return 0;
}
