#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_RECORD_LEN 100

int main()
{
    char filename[50], employee_name[MAX_NAME_LEN], delete_name[MAX_NAME_LEN];
    int salary, delete_salary;
    FILE *fp, *fp_temp;

    // 输入文件名
    scanf("%s", filename);

    // 打开文件
    fp = fopen(filename, "r+");
    if (fp == NULL)
    {
        printf("打开文件失败！\n");
        return 1;
    }

    // 输入员工姓名和工资
    scanf("%s %d", employee_name, &salary);

    // 显示文件内容
    char record[MAX_RECORD_LEN];
    while (fgets(record, MAX_RECORD_LEN, fp) != NULL)
    {
        printf("%s", record);
    }
    rewind(fp); // 将文件指针移回文件开头

    // 输入要删除的员工姓名
    scanf("%s", delete_name);

    // 创建临时文件
    fp_temp = fopen("temp.txt", "w");
    if (fp_temp == NULL)
    {
        fclose(fp);
        return 1;
    }

    // 删除记录
    while (fgets(record, MAX_RECORD_LEN, fp) != NULL)
    {
        if (strstr(record, delete_name) == NULL)
        { // 如果记录中不包含要删除的员工姓名
            fprintf(fp_temp, "%s", record);
        }
    }

    // 关闭文件
    fclose(fp);
    fclose(fp_temp);

    // 删除原文件并重命名临时文件
    remove(filename);
    rename("temp.txt", filename);

    // 打开文件并显示删除后的内容
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("打开文件失败！\n");
        return 1;
    }
    printf("删除后的文件内容：\n");
    while (fgets(record, MAX_RECORD_LEN, fp) != NULL)
    {
        printf("%s", record);
    }
    fclose(fp);

    return 0;
}