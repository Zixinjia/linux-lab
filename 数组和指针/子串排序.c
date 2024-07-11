#include <stdio.h>
#include <string.h>
void sort(char *str[])
{
	int size = 5;
	char temp[100];
	int i = 0, j = 0;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (strcmp(str[j], str[j + 1]) > 0)
			{
				strcpy(temp, str[j + 1]);
				strcpy(str[j + 1], str[j]);
				strcpy(str[j], temp);
			}
		}
	}
}
int main()
{
	char str[5][30];
	// Ö¸ÕëÊý×é
	char *pstr[5];
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%19s", str[i]);
		pstr[i] = str[i];
	}
	sort(pstr);
	printf("*******\n");
	for (i = 0; i < 5; i++)
	{
		printf("%s\n", pstr[i]);
	}
	return 0;
}
