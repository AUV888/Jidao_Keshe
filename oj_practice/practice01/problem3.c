/*
题目描述
已知两个由正整数组成的无序序列A、B，每个序列的元素个数未知，但至少有一个元素。
你的任务是判断序列B是否是序列A的连续子序列。假设B是“1 9 2 4 18”，A是“33 64 1 9 2 4 18 7”，B是A的连续子序列；
假设B是“1 9 2 4 18”，A是“33 1 9 64 2 4 18 7”，B不是A的连续子序列。
要求：
建立两个单链表A、B用于存储两个正整数序列，然后按照题目的要求，判断链表B是否是链表A的连续子序列。
正整数的输入用-1作为结束标志，注意-1不算这个正整数序列中的元素（不要统计-1）。在程序结束前要释放链表A、B中的所有节点。
输入
依次输入两个乱序的正整数序列A、B，序列中元素个数未知，但每个序列至少有一个元素，并以输入“-1”结束，每个序列占一行。
注意：样例中给的是两个样例，实际的输入只有两行。
输出
如果序列B是序列A的连续子序列，则输出“ListB is the sub sequence of ListA.”，否则输出“ListB is not the sub sequence of ListA.”。
*/
//本题问题出在issub函数中的第二个嵌套循环条件，倘若没有 tmp!=NULL，以下输入可能会导致错误
//1 2 3 6 5 4 -1
//6 5 4 3 2 -1
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
int length(ndp head)
{
    int cnt = 0;
    if (head == NULL)
    {
        return 0;
    }
    for (; head != NULL; head = head->next)
    {
        cnt++;
    }
    return cnt;
}
int issub(ndp h1, ndp l1, ndp h2, ndp l2)
{
    if (length(h2) > length(h1))
    {
        return 0;
    }
    else if (length(h2) == 0)
    {
        return 0;
    }
    ndp cur1 = h1;
    int cnt = 0;
    while (cur1 != NULL)
    {
        if (cur1->val == h2->val)
        {
            ndp cur2 = h2;
            ndp tmp = cur1;
            int i = length(h2);
            while (cur2 != NULL && tmp != NULL)
            {
                if (cur2->val == tmp->val)
                {
                    i--;
                }
                else
                {
                    break;
                }
                tmp = tmp->next;
                cur2 = cur2->next;
            }
            cnt += (i == 0) ? 1 : 0;
        }
        cur1 = cur1->next;
    }
    return (cnt == 0) ? 0 : 1;
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
int main(void)
{
    ndp h1 = NULL, h2 = NULL, l1 = NULL, l2 = NULL;
    create(&h1, &l1);
    create(&h2, &l2);
    if (issub(h1, l1, h2, l2))
    {
        printf("ListB is the sub sequence of ListA.\n");
    }
    else
    {
        printf("ListB is not the sub sequence of ListA.\n");
    }
    destroy(h1);
    destroy(h2);
    return 0;
}