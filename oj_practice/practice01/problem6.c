/*
题目描述
已知有一个乱序的字符序列L，序列中的字符可能是英文字母、数字字符或其它字符，字符的个数未知，每个字符之间用空格分开。
字符序列用“-1”作为输入结束标志，这里你要把-1当做一个字符串对待，并且不算作字符序列中的元素。
如下即为一个合法的字符序列：“a c 3 b a d 6 , & j m 8 7 2 V -1”。你的任务是将这个字符序列拆分为三个独立的序列A、B和C，
其中序列A存放序列L中的字母，序列B存放序列L中的数字，序列C存放序列L中的其他字符，然后，将序列A、B和C分别按照ASCII码的大小关系进行升序排序。
最终序列L将变为空序列。
要求：
建立四个单链表，分别存储序列L、A、B、C中的元素。字符序列的输入用“-1”作为结束标志。
建立链表L时，建议使用scanf(“%s”,s);来读取字符序列中的字符，即把单独的字符看做一个字符串读取。
当L建立后，你要按照问题描述中所述，将L拆分为A、B、C三个链表，然后对每个链表都进行排序，这部分的操作都应该是对指针进行修改，而不是删除节点与建立新节点。
在程序结束前要释放链表A、B、C中的所有节点。
输入
一个乱序的字符序列，序列元素的个数未知，以输入“-1”结束，输入“-1”前可能没有其它元素，每个字符序列占一行。
输出
链表A中的元素，占一行；然后是链表B中的元素，占一行。最后是链表C中的元素，占一行。
每行的每个元素后有一个空格，注意最后一个元素后只有换行符，如果某个链表为空则，则输出“There is no item in X list.”
*/
//本题没有什么难度，唯一可能出错的就是在merge函数之中对于tmp的设置，只要不出现Segmentation Fault即可
#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct NODELIST
{
    char data;
    struct NODELIST *next;
};
typedef struct NODELIST node;
typedef struct NODELIST *nodep;

void insert(nodep *h, nodep *l, char x)
{
    nodep current = (nodep)malloc(sizeof(node));
    current->data = x;
    if (*h == NULL)
    {
        *h = current;
        *l = current;
        current->next = NULL;
    }
    else
    {
        (*l)->next = current;
        current->next = NULL;
        *l = current;
    }
    return;
}
void out(nodep head, char x)
{
    if (head == NULL)
    {
        printf("There is no item in %c list.\n", x);
        return;
    }
    printf("The list %c is: ", x);
    while (head->next != NULL)
    {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("%c\n", head->data);
}
nodep find_prev_location(nodep head, char x)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (x < head->data) // smaller than head
    {
        return NULL;
    }
    while (head != NULL)
    {
        if (head->next != NULL) // in the middle of nodelist
        {
            if (head->data <= x && x < head->next->data)
            {
                return head;
            }
        }
        else if (head->next == NULL && head->data <= x) // at last of nodelist
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}
void merge(nodep prev_location, nodep *location_head, nodep *inserted_head)
{
    if (prev_location == NULL)
    {
        nodep tmp1 = *location_head, tmp2 = (*inserted_head)->next;
        *location_head = *inserted_head;
        (*location_head)->next = tmp1;
        *inserted_head = tmp2;
    }
    else
    {
        nodep tmp1 = prev_location->next, tmp2 = (*inserted_head)->next;
        prev_location->next = *inserted_head;
        prev_location->next->next = tmp1;
        *inserted_head = tmp2;
    }
}
int classify(char x)
{
    if (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z')) // is a character
    {
        return 1;
    }
    else if ('0' <= x && x <= '9') // is a number
    {
        return 2;
    }
    else // is other
    {
        return 3;
    }
}
int main(void)
{

    nodep h0 = NULL, l0 = NULL, ha = NULL, hb = NULL, hc = NULL, now = NULL;
    char tmp[2];
    scanf("%s", tmp);
    while (strcmp(tmp, "-1") != 0)
    {
        insert(&h0, &l0, tmp[0]);
        scanf("%s", tmp);
    }

    now = h0;
    while (now != NULL)
    {
        nodep next_of_now = now->next;
        if (classify(now->data) == 1)
        {
            nodep prev_loc = find_prev_location(ha, now->data);
            merge(prev_loc, &ha, &h0);
        }
        else if (classify(now->data) == 2)
        {
            nodep prev_loc = find_prev_location(hb, now->data);
            merge(prev_loc, &hb, &h0);
        }
        else
        {
            nodep prev_loc = find_prev_location(hc, now->data);
            merge(prev_loc, &hc, &h0);
        }
        now = next_of_now;
    }

    out(ha, 'A');
    out(hb, 'B');
    out(hc, 'C');
    return 0;
}