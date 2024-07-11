/**
5.�����ֵ���±�
�Ӽ���������10�����ݵ�һά�����У�Ȼ���ҳ������е����ֵ�͸�ֵ���ڵ�Ԫ���±ꡣ
Ҫ������Ӻ���search(int *pa,int n,int *pmax,int *pflag)��ɣ���������Ϊʵ�Σ�ָ����Ϊ�βΣ����ֵ���±����β�����ָ�����ʽ���ء�
**/
#include <stdio.h>
const int Min = -1e6;
void search(int *pa, int n, int *pmax, int *pflag)
{
	*pmax = pa[0];
	*pflag = 0;
	int i = 0;
	for (i = 1; i < n; i++)
	{
		if (pa[i] > *pmax)
		{
			*pmax = pa[i];
			*pflag = i;
		}
	}
}
int main()
{
	int a[10] = {0};
	int max, flag;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	search(a, 10, &max, &flag);
	printf("pmax == %d, pflag == %d\n", max, flag);
	return 0;
}
