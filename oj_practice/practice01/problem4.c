/*
题目描述
已知一个正整数序列，序列元素个数未知，但至少有两个元素，你的任务是建立一个单链表用于存储这个正整数序列。然后实现交换此链表中任意指定的两段，
第一段为[s1,t1]，第二段[s2,t2]。s1、t1、s2、t2代表链表的第几个节点，且满足s1<=t1，s2<=t2，t1<s2，s2一定小于等于链表节点的总个数。
正整数的输入用-1作为结束标志，注意-1不算这个正整数序列中的元素（不要统计-1）。最后将链表的全部节点释放。
输入
输入一个正整数序列，以输入“-1”结束，序列中元素个数未知，但输入“-1”前至少输入两个正整数。然后是四个整数，即为s1、t1、s2、t2。
输出
经过处理后的新链表，每个元素后有一个空格，注意最后一个元素后只有换行符。
*/
//本题的问题在于要将t1=s2-1的情况进行单独讨论，因为此时可能会导致死循环
#include <stdio.h>
#include <malloc.h>
struct NODELIST
{
    int val;
    struct NODELIST *next;
};
typedef struct NODELIST nd;
typedef struct NODELIST *ndp;

void create(ndp *head, ndp *last)
{
    ndp current = NULL;
    int num;
    scanf("%d", &num);
    while (num != -1)
    {
        current = (ndp)malloc(sizeof(nd));
        current->val = num;
        if (*head == NULL)
        {
            *head = current;
            current->next = NULL;
            *last = current;
        }
        else
        {
            (*last)->next = current;
            current->next = NULL;
            *last = current;
        }
        scanf("%d", &num);
    }
    return;
}
void destroy(ndp head)
{
    ndp tmp = NULL;
    while (head != NULL)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
    return;
}
ndp position(ndp head, int num)
{
    if (num == 0)
    {
        return NULL;
    }
    int cnt = 1;
    while (head != NULL && cnt != num)
    {
        cnt++;
        head = head->next;
    }
    return head;
}
void out(ndp head)
{
    printf("The new list is:");
    while (head->next != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("%d\n", head->val);
    return;
}
void swp(ndp *head, ndp s1prev, ndp t1, ndp s2prev, ndp t2)
{
    ndp t1n = t1->next, t2n = t2->next, s1, s2 = s2prev->next;
    if (s1prev == NULL)
    {
        s1 = *head;
        (*head) = s2;
    }
    else
    {
        s1 = s1prev->next;
        s1prev->next = s2;
    }
    if (t1 == s2prev)
    {
        t2->next = s1;
        t1->next = t2n;
    }
    else
    {
        t2->next = t1n;
        s2prev->next = s1;
        t1->next = t2n;
    }
    return;
}

int main(void)
{
    ndp head = NULL, last = NULL;
    int s1, t1, s2, t2;
    create(&head, &last);
    scanf("%d%d%d%d", &s1, &t1, &s2, &t2);
    swp(&head, position(head, s1 - 1), position(head, t1), position(head, s2 - 1), position(head, t2));
    out(head);
    destroy(head);
    return 0;
}