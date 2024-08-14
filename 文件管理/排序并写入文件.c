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
    float average;
};

// 比较函数，用于排序
int compare(const void *a, const void *b)
{
    const struct Student *stu1 = (const struct Student *)a;
    const struct Student *stu2 = (const struct Student *)b;
    if (stu1->average > stu2->average)
    {
        return -1;
    }
    else if (stu1->average < stu2->average)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int num_students;
    char filename[50];
    struct Student students[MAX_STUDENTS];

    // 从文件读取学生数据
    FILE *fp = fopen("stu", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    num_students = 0;
    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        sscanf(line, "NO%d %s %d %d %d %d", NULL, students[num_students].name, &students[num_students].number, &students[num_students].china, &students[num_students].math, &students[num_students].english);
        students[num_students].average = (students[num_students].china + students[num_students].math + students[num_students].english) / 3.0;
        num_students++;
    }
    fclose(fp);

    // 对学生数据进行排序
    qsort(students, num_students, sizeof(struct Student), compare);

    // 将排序后的学生数据写入新文件
    fp = fopen("stu_sort", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    for (int i = 0; i < num_students; i++)
    {
        fprintf(fp, "NO%d %s %d %d %d %d %.2f\n", i + 1, students[i].name, students[i].number, students[i].china, students[i].math, students[i].english, students[i].average);
    }
    fclose(fp);

    printf("Students sorted by average score and saved to stu_sort.\n");

    return 0;
}