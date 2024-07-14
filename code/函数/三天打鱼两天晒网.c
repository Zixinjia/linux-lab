#include <stdio.h>
#include <stdbool.h>

int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool is_RN(int yy)
{
	if ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0)
	{
		return true;
	}
	return false;
}
int year_year_dis(int yy)
{
	int sum = 0;
	for (int i = 1990; i <= yy; i++)
	{
		if (is_RN(i))
			sum += 366;
		else
			sum += 365;
	}
	return sum;
}
int day_dis(int yy, int mm, int dd)
{
	if (is_RN(yy))
	{
		months[2] = 29;
	}
	int sum = 0;
	for (int i = 1; i < mm; i++)
	{
		sum += months[i];
	}
	sum += dd;
	return sum;
}
int main()
{
	int yy, mm, dd;

	int bet1 = year_year_dis(yy);

	int bet2 = day_dis(yy, mm, dd);
	int total = bet1 + bet2;
	total %= 5;
	if (total >= 1 && total <= 3)
	{
		printf("´òÓã\n");
	}
	else
	{
		printf("É¹Íø\n");
	}
	return 0;
}
