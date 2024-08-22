#include <stdio.h>
typedef ElemType int;
//构造节点
typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPrt;
//构造链表
typedef struct LinkStack
{
    LinkStackPrt top;
    int count;
} LinkStack;

//链栈的进栈
bool push(linkStack *S, ElemType e)
{
    LinkStackPrt p = (LinkStack)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S->top;
    S->top = p;
    S->count++;
    return true;
}
//链栈的出栈
bool pop(LinkStack *S, ElemType *e)
{
    LinkStackPrt p;
    if (StackEmpty(*S))
    {
        return false;
    }
    *e = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    return true;
}
//栈销毁
void DestoryStack(LinkStack &S)
{
    StackNode p;
    while (S)
    {
        p = S;
        S = S->next;
        delete p;
    }
    s = NULL;
}