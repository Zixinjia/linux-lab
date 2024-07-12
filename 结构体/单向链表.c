#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
	int id;
	char name[20];
	struct Node *next;
} node;
node *Create(int id, char name[])
{
	node *newNode = (node *)malloc(sizeof(node));
	newNode->id = id;
	strcpy(newNode->name, name);
	newNode->next = NULL;
	return newNode;
}
void Push_Back(node *phead, int id, char name[])
{
	node *newNode = Create(id, name);
	if (phead == NULL)
	{
		phead = newNode;
	}
	else
	{
		node *tail = phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

node *bubbleSortById(node *head)
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
			if (current->id > current->next->id)
			{

				char temp[20];
				strcpy(temp, current->id);
				strcpy(current->id, current->next->id);
				strcpy(current->next->id, temp);

				strcpy(temp, current->name);
				strcpy(current->name, current->next->name);
				strcpy(current->next->name, temp);

				swapped = 1;
			}
			current = current->next;
		}
		tail = current;
	} while (swapped);

	return head;
}
int count(node *phead)
{
	int cnt = 0;
	node *cur = phead;
	while (cur != NULL)
	{
		cur = cur->next;
		cnt++;
	}
	return cnt;
}
node *reverse(node *head)
{
	node *prev = NULL;
	node *cur = head;
	node *next = NULL;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}
void list(node *head)
{
	node *cur = head;
	while (cur != NULL)
	{
		printf("学号: %d 姓名: %s \n", cur->id, cur->name);
		cur = cur->next;
	}
}

node *search(node *head, int id)
{
	node *cur = head;
	while (cur != NULL)
	{
		if (cur->id == id)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
int main()
{
	int id;
	char name[20];
	int n;
	node *phead1 = Create();
	printf("请输入数据条数n: \n");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %s", &id, name);
		Push_Back(phead1, id, name);
	}
	// 按照学号升序排序
	bubbleSortById(phead1);
	printf("节点的数量:\n");
	printf("%d\n", count(phead1->next));
	reverse(phead1);
	list(phead1->next);
	printf("输入你要查找的学号\n");
	scanf("%d", &id);
	node *student = search(phead1->next, id);
	if (student != NULL)
	{
		printf("%d %s\n", student->id, student->name);
	}
	else
	{
		printf("不存在该学生记录\n");
	}
	return 0;
}
