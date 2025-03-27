#include <bits/stdc++.h>
#include <malloc.h>
using namespace std;

// Enter -1 to end input
// Merge the node list
// The nodelist 1 and 2 must be ascending
struct NODELIST
{
    int data;
    struct NODELIST *next;
};
typedef struct NODELIST node;
typedef struct NODELIST *nodeptr;

void destroy(nodeptr head)
{
    nodeptr tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    return;
}

void create(nodeptr *headp, nodeptr *lastp)
{
    int num;
    cin >> num;
    while (num != -1)
    {
        nodeptr current = (nodeptr)malloc(sizeof(node));
        current->data = num;
        if ((*headp) == NULL) // at head
        {
            (*headp) = current;
            (*lastp) = current;
            current->next = NULL;
        }
        else // other
        {
            (*lastp)->next = current;
            current->next = NULL;
            *lastp = current;
        }
        cin >> num;
    }
    return;
}

void output(nodeptr head)
{
    if (head == NULL)
    {
        cout << "EMPTY NODE LIST\n";
        return;
    }
    nodeptr cur = head;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
    return;
}

// h1 will point to the new head of the merged nodelist
// while h2 will be a NULL pointer
void merge(nodeptr *h1, nodeptr *h2, nodeptr *l1, nodeptr *l2)
{
    /*
     nodeptr cur1 = *h1, cur2 = *h2;
     if (*h1 == NULL || *h2 == NULL)
     {
         cout << "CANNOT MERGE EMPTY NODELIST\n";
         return;
     }
     else if (cur2->data < cur1->data)
     {
         nodeptr tmp = cur2->next;
         *h1 = cur2;
         cur2->next = cur1;
         cur2 = tmp;
     }
     */
    //写不出来,不写了！！！
    return;
}

int main(void)
{
    nodeptr head1 = NULL, last1 = NULL, head2 = NULL, last2 = NULL;
    create(&head1, &last1); // must be ascending
    create(&head2, &last2); // must be ascending
    merge(&head1, &head2, &last1, &last2);
    output(head1);
    destroy(head1);
    destroy(head2);
    return 0;
}
