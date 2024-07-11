#include <stdio.h>
#include <string.h>
void sort(char (*str)[6], int size)
{
	char temp[6];
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
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
	char str[10][6];
	int i = 0;
	while ((scanf("%5s", str[i])) && !strcmp(str[i], "*****"))
	{
		i++;
	}
	sort(str, i);
	printf("%s\n", str[i - 1]);
	return 0;
}
