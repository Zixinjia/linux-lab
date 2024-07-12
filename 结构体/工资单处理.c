<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
	char id[20];
	char name[20];
	char salary[20];
	struct Node *next;
} node;
// 创建
node *create(char id[], char name[], char salary[])
{
	node *newNode = (node *)malloc(sizeof(node));
	strcpy(newNode->id, id);
	strcpy(newNode->name, name);
	strcpy(newNode->salary, salary);
	newNode->next = NULL;
	return newNode;
}
// 尾插
void push_back(node **phead, char id[], char name[], char salary[])
{
	node *newNode = create(id, name, salary);
	if (*phead == NULL)
	{
		*phead = newNode;
	}
	else
	{
		node *tail = *phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
// 冒泡排序
node *bubbleSort(node *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	int swapped;
	node *current;
	node *tail = NULL;

	do
	{
		swapped = 0;
		current = head;

		while (current->next != tail)
		{
			if (strcmp(current->id, current->next->id) > 0)
			{
				// 交换节点的id、name和salary
				char temp[20];
				strcpy(temp, current->id);
				strcpy(current->id, current->next->id);
				strcpy(current->next->id, temp);

				strcpy(temp, current->name);
				strcpy(current->name, current->next->name);
				strcpy(current->next->name, temp);

				strcpy(temp, current->salary);
				strcpy(current->salary, current->next->salary);
				strcpy(current->next->salary, temp);

				swapped = 1;
			}
			current = current->next;
		}
		tail = current;
	} while (swapped);

	return head;
}
// 合并 成一个新的，返回新的合并后的指针
node *merge(node *phead1, node *phead2)
{
	node *list3 = create(" ", " ", " ");
	node *cur3 = list3;
	node *cur1 = phead1;
	node *cur2 = phead2;
	while (cur1 != NULL)
	{
		cur3->next = cur1;
		cur1 = cur1->next;
		cur3 = cur3->next;
	}
	while (cur2 != NULL)
	{
		cur3->next = cur2;
		cur2 = cur2->next;
		cur3 = cur3->next;
	}
	cur3->next = NULL;
	return list3;
}
//(2)
// 冒泡排序
void bubbleSort2(node **list, int size)
{
	int i, j;
	node *temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (strcmp(list[j]->salary, list[j + 1]->salary) > 0)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}
void print(node *list)
{
	while (list != NULL)
	{
		printf("%s %s %s\n", list->id, list->name, list->salary);
		list = list->next;
	}
}
int main()
{
	char id[20], name[20], salary[20];
	node *list1 = create(" ", " ", " ");
	node *list2 = create(" ", " ", " ");

	int n, m; // n是list1 m是list2 节点
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{

		scanf("%s%s%s", id, name, salary);
		push_back(&list1, id, name, salary);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%s%s%s", id, name, salary);
		push_back(&list2, id, name, salary);
	}

	// 合并
	node *list3 = merge(list1->next, list2->next);
	// 打印链表
	//	while(list1!=NULL)
	//	{
	//		printf("%s %s %s\n",list1->id,list1->name,list1->salary);
	//		list1 = list1->next;
	//	}

	// 按照员工号排序
	node *sortedList = bubbleSort(list3);
	print(sortedList);
	// 按照工资排序 （指针数组）
	bubbleSort2(&list3, n + m);
	print(sortedList);
	return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
	char id[20];
	char name[20];
	char salary[20];
	Node *next;
} node;
// 创建
node *create(char id[], char name[], char salary[])
{
	node *newNode = (node *)malloc(sizeof(node));
	strcpy(newNode->id, id);
	strcpy(newNode->name, name);
	strcpy(newNode->salary, salary);
	newNode->next = NULL;
	return newNode;
}
// 尾插
void push_back(node **phead, char id[], char name[], char salary[])
{
	node *newNode = create(id, name, salary);
	if (*phead == NULL)
	{
		*phead = newNode;
	}
	else
	{
		node *tail = *phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
// 冒泡排序
node *bubbleSort(node *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	int swapped;
	node *current;
	node *tail = NULL;

	do
	{
		swapped = 0;
		current = head;

		while (current->next != tail)
		{
			if (strcmp(current->id, current->next->id) > 0)
			{
				// 交换节点的id、name和salary
				char temp[20];
				strcpy(temp, current->id);
				strcpy(current->id, current->next->id);
				strcpy(current->next->id, temp);

				strcpy(temp, current->name);
				strcpy(current->name, current->next->name);
				strcpy(current->next->name, temp);

				strcpy(temp, current->salary);
				strcpy(current->salary, current->next->salary);
				strcpy(current->next->salary, temp);

				swapped = 1;
			}
			current = current->next;
		}
		tail = current;
	} while (swapped);

	return head;
}
// 合并 成一个新的，返回新的合并后的指针
node *merge(node *phead1, node *phead2)
{
	node *list3 = create(" ", " ", " ");
	node *cur3 = list3;
	node *cur1 = phead1;
	node *cur2 = phead2;
	while (cur1 != NULL)
	{
		cur3->next = cur1;
		cur1 = cur1->next;
		cur3 = cur3->next;
	}
	while (cur2 != NULL)
	{
		cur3->next = cur2;
		cur2 = cur2->next;
		cur3 = cur3->next;
	}
	cur3->next = NULL;
	return list3;
}
//(2)
// 冒泡排序
void bubbleSort2(node **list, int size)
{
	int i, j;
	node *temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (strcmp(list[j]->salary, list[j + 1]->salary) > 0)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}
void print(node *list)
{
	while (list != NULL)
	{
		printf("%s %s %s\n", list->id, list->name, list->salary);
		list = list->next;
	}
}
int main()
{
	char id[20], name[20], salary[20];
	node *list1 = create(" ", " ", " ");
	node *list2 = create(" ", " ", " ");

	int n, m; // n是list1 m是list2 节点
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{

		scanf("%s%s%s", id, name, salary);
		push_back(&list1, id, name, salary);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%s%s%s", id, name, salary);
		push_back(&list2, id, name, salary);
	}

	// 合并
	node *list3 = merge(list1->next, list2->next);
	// 打印链表
	//	while(list1!=NULL)
	//	{
	//		printf("%s %s %s\n",list1->id,list1->name,list1->salary);
	//		list1 = list1->next;
	//	}

	// 按照员工号排序
	node *sortedList = bubbleSort(list3);
	print(sortedList);
	// 按照工资排序 （指针数组）
	bubbleSort2(&list3, n + m);
	print(sortedList);
	return 0;
}
>>>>>>> 6319aa0c07bd657e7ed639217d155fb1b315f651
