#include <stdio.h>
#include <math.h>
double f(double x)
{
	return (exp(x) - exp(-x)) / 2;
}
int main()
{
	printf("input x:\n");
	double x = 0;
	scanf("%lf", &x);
	printf("result is %.6f", f(1 + f(x)) / (f(2 * x) + f(3 * x)));
	return 0;
}
