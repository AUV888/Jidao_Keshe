#include <iostream>
#include <cstdlib>
#include <iostream>
#define print_error cout << "Unable to allocate memory\n"
using namespace std;

struct LISTNODE
{
    int data;
    LISTNODE *next;
};
typedef LISTNODE node;
typedef LISTNODE *nodeptr;

void create_head(nodeptr *hptrptr, nodeptr *lptrptr) // send the address of head and last
{
    hptrptr = (nodeptr *)malloc(sizeof(node));
    if (hptrptr != NULL) // allocate success
    {
        (*hptrptr)->next = NULL;
        (*lptrptr) = (*hptrptr);
    }
    return;
}

void insert_end(nodeptr *lptrptr, int val)
{
    nodeptr newptr;
    newptr = (nodeptr)malloc(sizeof(node));
    if (newptr != NULL)
    {
        newptr->data = val;
        newptr->next = NULL;
        (*lptrptr)->next = newptr;
        (*lptrptr) = newptr;
    }
    else
    {
        print_error;
    }
    return;
}

void insert_front(nodeptr head, int val)
{
    nodeptr newptr;
    newptr = (nodeptr)malloc(sizeof(node));
    if (newptr != NULL)
    {
        newptr->data = val;
        newptr->next = head->next;
        head->next = newptr;
    }
    else
    {
        print_error;
    }
    return;
}

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

int main(void)
{
    nodeptr head, last;
    create_head(&head, &last);
    if (head == NULL)
    {
        print_error;
    }

    return 0;
}
