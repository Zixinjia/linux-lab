#include<stdio.h>
const int n = 2;
const int m = 3;
int FindMax(int p[][3], int m, int n, int *pRow, int *pCol)
{
	int max = p[0][0];	
	int i = 0, j = 0;
	for(i = 0; i < n; i ++)
	{
		for(j = 0; j < m; j ++)
		{
			if(p[i][j] > max)
			{ 
				max = p[i][j];
				*pRow = i;
				*pCol = j;
			}
		}
	}
	return max;
}
int main()
{
	int a[n][m];
	int row, col, mmax, i, j;
	//n ÐÐ m ÁÐ 
	for(i = 0; i < n; i ++)
	{
		for(j = 0; j < m; j ++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	mmax = FindMax(a, m, n, &row, &col);
	printf("max == %d, maxRow == %d, maxCol == %d\n",mmax, row, col);	
	return 0;
}
