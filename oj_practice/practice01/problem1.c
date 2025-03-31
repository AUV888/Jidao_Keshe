#include <stdio.h>
#include <malloc.h>
/*
##题目描述
已知一个正整数序列，个数未知，但至少有一个元素，你的任务是建立一个单链表，并使用该链表存储这个正整数序列，然后统计这个序列中元素的最大值与最小值，计算序列全部元素之和。正整数的输入用-1作为结束标志，注意-1不算这个正整数序列中的元素（不要统计-1）。
##输入
一个正整数序列，正整数序列元素的个数未知，但以输入“-1”结束，输入“-1”前至少输入一个正整数。序列中的元素范围在1—999999999之间。
##输出
三个正整数，即最大值、最小值、所有元素之和。
数据最多的测试用例节点数在1000这个数量级，所有整数可以用int型存储。
请注意输入输出格式。
*/
struct NODE
{
    int val;
    struct NODE *next;
};
typedef struct NODE nd;
typedef struct NODE *ndptr;
void cr(ndptr *hd)
{
    int num;
    ndptr cur, las = NULL;
    scanf("%d", &num);
    while (num != -1)
    {
        cur = (ndptr)malloc(sizeof(nd));
        cur->val = num;
        if (*hd == NULL)
        {
            *hd = cur;
            cur->next = NULL;
            las = cur;
        }
        else
        {
            las->next = cur;
            las = cur;
            cur->next = NULL;
        }
        scanf("%d", &num);
    }
}
void get(ndptr hd, int *ma, int *mi, int *su)
{
    ndptr cur = hd;
    while (cur != NULL)
    {
        *ma = (cur->val > *ma) ? cur->val : *ma;
        *mi = (cur->val < *mi) ? cur->val : *mi;
        *su += cur->val;
        cur = cur->next;
    }
}
int main(void)
{
    ndptr head = NULL;
    int ma = -1, mi = 999999999, su = 0;
    cr(&head);
    get(head, &ma, &mi, &su);
    printf("The maximum,minmum and the total are:%d %d %d\n", ma, mi, su);
    return 0;
}