#include <bits/stdc++.h>
#include <malloc.h>
using namespace std;

// Enter -1 to end input
// Reverse the node list
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

void reverse(nodeptr *head, nodeptr *last)
{
    if (*head == NULL)
    {
        cout << "CANNOT REVERSE EMPTY NODELIST\n";
        return;
    }
    nodeptr prev = *head, curr = prev->next;
    *head = *last;
    *last = prev;
    prev->next = NULL;
    while (curr != NULL)
    {
        nodeptr tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return;
}

int main(void)
{
    nodeptr head = NULL, last = NULL;
    create(&head, &last);
    reverse(&head, &last);
    output(head);
    destroy(head);
    return 0;
}
