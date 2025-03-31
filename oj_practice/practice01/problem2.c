#include <stdio.h>
#include <malloc.h>
/*
题目描述
已知一个正整数组成的无序序列，个数未知，但至少有一个元素，你的任务是建立一个单链表，并使用该链表存储这个正整数序列，然后将这个链表进行排序，使得排序后的链表为递增序列。正整数的输入用-1作为结束标志，注意-1不算这个正整数序列中的元素（不要统计-1）。在排序的过程中，你可以自己选择排序算法（冒泡排序、选择排序等），但必须是通过修改结点的指针域来进行排序，而不是对结点的数据域进行修改。程序结束后要释放所有节点占据的空间。
输入
一个元素个数未知的正整数序列，以输入“-1”结束，输入“-1”前至少输入一个正整数。
输出
经过排序后的链表，每个元素后有一个空格，注意最后一个元素后只有换行符。
数据最多的测试用例节点数在1000这个数量级，所有整数可以用int型存储。
请注意输入输出格式。
*/
//本题的问题在于cr函数中last的不正确更新
struct NODELST
{
    int val;
    struct NODELST *next;
};
typedef struct NODELST nd;
typedef struct NODELST *ndp;

void out(ndp hd)
{
    printf("The new list is:");
    while (hd->next != NULL)
    {
        printf("%d ", hd->val);
        hd = hd->next;
    }
    printf("%d\n", hd->val);
    return;
}

ndp getpos(ndp hd, int x)
{
    ndp cur = hd;
    if (x < cur->val)
    {
        return NULL;
    }
    while (cur->next != NULL)
    {
        if (cur->val <= x && cur->next->val > x)
        {
            break;
        }
        else
        {
            cur = cur->next;
        }
    }
    return cur;
}

void cr(ndp *hd)
{
    ndp current = NULL, last = NULL;
    int num;
    scanf("%d", &num);
    while (num != -1)
    {
        current = (ndp)malloc(sizeof(nd));
        current->val = num;
        if (*hd == NULL)
        {
            *hd = current;
            last = current;
            current->next = NULL;
        }
        else
        {
            ndp pos = getpos(*hd, num);
            if (pos == NULL)
            {
                ndp tmp=(*hd);
                *hd = current;
                current->next = tmp;
            }
            else if (pos->next == NULL)
            {
                last->next = current;
                current->next = NULL;
                last = current;
            }
            else
            {
                ndp tmp = pos->next;
                pos->next = current;
                current->next = tmp;
            }
        }
        scanf("%d", &num);
    }
    return;
}
int main(void)
{
    ndp head = NULL;
    cr(&head);
    out(head);
    return 0;
}