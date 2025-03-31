/*
题目描述
已知有两个递增的正整数序列A和B，序列中元素个数未知，同一序列中不会有重复元素出现，有可能某个序列为空。
现要求将序列B归并到序列A中，且归并后序列A的数据仍然按递增顺序排列。如果序列B中某些数据在序列A中也存在，
则这些数据所在节点仍然留在序列B中，而不被归并到序列A中；
否则这些数据所在节点将从序列B中删除，添加到序列A中。

要求：
建立两个单链表A、B用于存储两个正整数序列，然后按照题目的要求，将链表B中的元素归并到链表A中。
在归并的过程中，不要释放B中的节点空间、然后建立新节点，而要改变指针的指向，使元素从B中删除并添加到A中。
正整数序列按照递增顺序输入，用-1作为结束标志，注意-1不算这个正整数序列中的元素（不要统计-1）。
在程序结束前要释放链表A、B中的所有节点。
输入
依次输入两个递增的正整数序列A和B，序列元素的个数未知，但以输入“-1”结束，每个正整数序列占一行。
输出
处理后的链表A中的元素，占一行；然后是处理后的链表B中的元素，占一行。每行的每个元素后有一个空格，注意最后一个元素后只有换行符，
如果某个链表为空则，则输出“There is no item in X list.”
*/
//本题的问题主要在于如果A是一个空链表且B不是一个空链表，就要将B全部复制给A再输出。但是此时可能出现Segmentation Fault
//于是我们仅仅将B以A的名字输出，并不执行merge函数，就不会出现Segmentation Fault了
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
void out(ndp head, char x)
{
    if (head != NULL)
    {
        printf("The new list %c:", x);
    }
    else
    {
        printf("There is no item in %c list.\n", x);
        return;
    }
    while (head->next != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("%d\n", head->val);
    return;
}
int isIn(ndp hd, int x)
{
    int flg = 0;
    while (hd != NULL)
    {
        flg += hd->val == x ? 1 : 0;
        hd = hd->next;
    }
    return flg;
}
ndp prev_pos(ndp hd, int x)
{
    if (x < hd->val) // at the first
    {
        return NULL;
    }
    while (hd != NULL) // other situations
    {
        if (hd->next != NULL)
        {
            if (x > hd->val && x < hd->next->val)
            {
                return hd;
            }
        }
        else if (hd->next == NULL && x > hd->val)
        {
            return hd;
        }
        hd = hd->next;
    }
    return NULL;
}
void merge(ndp *ha, ndp *hb)
{
    ndp cur_b = *hb, curbprev = NULL;
    while (cur_b != NULL)
    {
        ndp curbnext = cur_b->next;
        if (!isIn(*ha, cur_b->val))
        {
            // find position
            ndp prev = prev_pos(*ha, cur_b->val);
            // cut link between A and its next
            // cut link between B and its front and next
            // link B and A and A's next
            // link B's front and B's next
            if (curbprev != NULL) // B is not the 1st
            {
                if (prev == NULL) // should insert at first place
                {
                    cur_b->next = *ha;
                    *ha = cur_b;
                    curbprev->next = curbnext;
                }
                else
                {
                    cur_b->next = prev->next;
                    prev->next = cur_b;
                    curbprev->next = curbnext;
                }
            }
            else // B is the 1st
            {
                if (prev == NULL)
                {
                    cur_b->next = *ha;
                    *ha = cur_b;
                    *hb = curbnext;
                }
                else
                {
                    cur_b->next = prev->next;
                    prev->next = cur_b;
                    *hb = curbnext;
                }
            }
        }
        else
        {
            curbprev = cur_b;
        }

        cur_b = curbnext;
    }
    return;
}
int main(void)
{
    ndp h1 = NULL, l1 = NULL, h2 = NULL, l2 = NULL;
    create(&h1, &l1);
    create(&h2, &l2);
    if (h1 == NULL && h2 != NULL)
    {
        out(h2, 'A');
        out(h1, 'B');
    }
    else
    {
        merge(&h1, &h2);
        out(h1, 'A');
        out(h2, 'B');
    }

    return 0;
}