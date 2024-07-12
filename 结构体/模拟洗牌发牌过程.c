#include <stdio.h>
#include <time.h>
char suit[4][10] = {
	"spades", "hearts",
	"clubs", "diamonds"};
char face[13][10] = {
	"A", "2", "3", "4", "5",
	"6", "7", "8", "9", "10",
	"Jack", "Queen", "King"};
typedef struct
{
	char s[10];
	char f[10];
	int order;
} card;
void wash_card(card c[])
{
	int i;
	srand(time(NULL)); // 使用当前时间作为随机数种子
	for (i = 51; i > 0; i--)
	{
		int j = rand() % (i + 1); // 生成一个0到i的随机数
		card temp = c[j];
		c[j] = c[i];
		c[i] = temp;
	}
}
int main()
{
	// 定义结构体数组存储52张牌
	card c[53];
	int k = 0;
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 13; j++)
		{
			strcpy(c[k].s, suit[i]);
			strcpy(c[k].f, face[j]);
			k++;
		}
	}
	// 洗牌
	wash_card(c);
	// 洗牌后的扑克牌
	printf("\n洗牌后的扑克牌：\n");
	for (i = 0; i < 52; i++)
	{
		printf("%s of %s\n", c[i].f, c[i].s);
	}
	// 发牌	题目没看懂，下面应该是错的
	for (int i = 0; i < 5; i++)
	{
		printf("%s %s\n", c[i].f, c[i].s);
	}
	return 0;
}
