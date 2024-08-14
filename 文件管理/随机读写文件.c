#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_RECORD_LEN 100

struct Student
{
    char name[MAX_NAME_LEN];
    int age;
    char major[MAX_NAME_LEN];
};

int main()
{
    char filename[50];
    struct Student students[100];
    int num_students, i;
    FILE *fp;

    // 输入文件名
    scanf("%s", filename);

    // 输入学生信息
    scanf("%d", &num_students);
    for (i = 0; i < num_students; i++)
    {
        printf("请输入第 %d 个学生的姓名、年龄、专业（以空格隔开）：", i + 1);
        scanf("%s %d %s", students[i].name, &students[i].age, students[i].major);
    }

    // 保存学生信息到文件
    fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        printf("打开文件失败！\n");
        return 1;
    }
    fwrite(students, sizeof(struct Student), num_students, fp);
    fclose(fp);

    // 读取奇数条学生信息并显示
    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("打开文件失败！\n");
        return 1;
    }
    for (i = 0; i < num_students; i += 2)
    {
        fread(&students[i], sizeof(struct Student), 1, fp);
        printf("姓名：%s，年龄：%d，专业：%s\n", students[i].name, students[i].age, students[i].major);
    }
    fclose(fp);

    return 0;
}