#include <stdio.h>
const int MaxLen = 10;
void strcat(char *dest, char *src)
{
	int len1 = 0, len2 = 0;
	while (dest[len1] != '\0' && len1 < 2 * MaxLen)
	{
		len1++;
	}
	while (src[len2] != '\0' && len2 < MaxLen)
	{
		len2++;
	}
	int cnt = 0;
	while ((*dest) != '\0')
	{
		dest++;
		cnt++;
	}
	// ¿¼ÂÇÖÕÖ¹·û
	while ((*src) != '\0' && cnt < MaxLen - 1)
	{
		*dest = *src;
		dest++;
		src++;
		cnt++;
	}
	// ¼ÓÉÏÖÕÖ¹·û
	*dest = '\0';
}
int main()
{
	char dest[2 * MaxLen], src[MaxLen];
	scanf("%s%s", dest, src);
	strcat(dest, src);
	printf("×îÖÕ×Ö·û´®str == %s\n", dest);
	return 0;
}