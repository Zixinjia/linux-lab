#include <stdio.h>

struct Student
{
    int id;
    char name[50];
    float scores[3];
    float average;
};

int main()
{
    struct Student students[5];

    for (int i = 0; i < 5; i++)
    {
        printf("输入第 %d 个学生的信息:\n", i + 1);
        scanf("%d %s %f %f %f", &students[i].id, students[i].name,
              &students[i].scores[0], &students[i].scores[1], &students[i].scores[2]);
        students[i].average = (students[i].scores[0] + students[i].scores[1] + students[i].scores[2]) / 3.0;
    }

    FILE *file = fopen("stdu.txt", "w");
    if (file == NULL)
    {
        printf("无法打开文件。\n");
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        fprintf(file, "学号: %d, 姓名: %s, 成绩: %.2f, %.2f, %.2f, 平均分: %.2f\n",
                students[i].id, students[i].name,
                students[i].scores[0], students[i].scores[1], students[i].scores[2],
                students[i].average);
    }

    fclose(file);
    return 0;
}