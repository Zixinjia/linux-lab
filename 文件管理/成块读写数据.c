#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_STUDENTS 100

struct Student
{
    char name[MAX_NAME_LEN];
    int number;
    int china;
    int math;
    int english;
};

int main()
{
    int num_students;
    char filename[50];
    struct Student students[MAX_STUDENTS];

    // 获取学生人数
    scanf("%d", &num_students);

    // 获取文件名
    scanf("%s", filename);

    // 输入学生信息
    for (int i = 0; i < num_students; i++)
    {
        scanf("%s %d %d %d %d", students[i].name, &students[i].number, &students[i].china, &students[i].math, &students[i].english);
    }

    // 将学生信息写入文件
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        exit(1);
    }
    for (int i = 0; i < num_students; i++)
    {
        fprintf(fp, "NO%d %s %d %d %d %d\n", i + 1, students[i].name, students[i].number, students[i].china, students[i].math, students[i].english);
    }
    fclose(fp);

    // 读取文件并输出学生信息
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        exit(1);
    }
    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        // 使用sscanf函数解析字符串
        char name[MAX_NAME_LEN];
        int number, china, math, english;
        sscanf(line, "NO%d %s %d %d %d %d", NULL, name, &number, &china, &math, &english);
        printf("%s\n", name);
        printf("%d %d %d %d\n", number, china, math, english);
    }
    fclose(fp);

    getchar();
    getchar();

    return 0;
}