#include <stdio.h>
int main()
{
	double max = 0;
	int x1, x2, x3, x5, x8;
	int cnt1, cnt2, cnt3, cnt5, cnt8;
	for (x8 = 0; x8 <= 2; x8++)
	{
		for (x5 = 0; x5 <= (20 - 8 * x8) / 5; x5++)
		{
			for (x3 = 0; x3 <= (20 - 8 * x8 - 5 * x5) / 2; x3++)
			{
				for (x2 = 0; x2 <= (20 - 8 * x8 - 5 * x5 - 3 * x3) / 2; x2++)
				{
					for (int x1 = 0; x1 <= 20 - 8 * x8 - 5 * x5 - 3 * x3 - 2 * x2; x1++)
					{
						double res = 2000 * pow(1 + 0.063, x1) * pow(1 + 0.066, x2) * pow(1 + 0.069, x3) * pow(1 + 0.075, x5) * pow(1 + 0.084, x8);
						if (res > max)
						{
							max = res;
							cnt1 = x1;
							cnt2 = x2;
							cnt3 = x3;
							cnt5 = x5;
							cnt8 = x8;
						}
					}
				}
			}
		}
	}
	printf("max == %.4f 1年期限存%d次，2年期限存%d次，3年期限存%d次，5年期限存%d次，8年期限存%d次\n", max, cnt1, cnt2, cnt3, cnt5, cnt8);
	return 0;
}
