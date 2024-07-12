#include <stdio.h>
#include <string.h>
typedef struct
{
	char name[20];
	char school_id[20];
	char location[20];
	char identify_id[20];
} student;
student s[10]; // 结构体数组s
int n;		   // 记录条数n
void input()
{

	for (int i = 0; i < n; i++)
	{
		scanf("%s %s %s %s", s[i].name, s[i].school_id, s[i].location, s[i].identify_id);
	}
}
void print()
{
	for (int i = 0; i < n; i++)
	{
		printf("%s %s %s %s\n", s[i].name, s[i].school_id, s[i].location, s[i].identify_id);
	}
}
// 通过学号查找
student search(char id[])
{
	student res;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(s[i].school_id, id) == 0)
		{
			res = s[i];
		}
	}
	return res;
}
int main()
{
	char id[10];
	printf("输入记录条数: \n");
	scanf("%d", &n);
	printf("\n输入%d条学生信息: \n", n);
	input(n);
	printf("\n输入你想找的学生学号: \n");
	scanf("%s", id);
	printf("\n你要找的学生信息如下: \n");
	student a = search(id);
	printf("%s %s %s %s\n", a.name, a.school_id, a.location, a.identify_id);
	printf("\n接下来显示所有人的信息: \n");
	print(); 	 
	return 0;
}
