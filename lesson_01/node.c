#include <stdio.h>
#include <stdlib.h>

// Enter -1 to end input
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node *NODEPTR;

NODEPTR create_node(void);
void insert_node(NODEPTR previous, NODEPTR *head); // Send the address of the pointer head
void output_node_list(NODEPTR head);
void delete_node(NODEPTR previous, NODEPTR *head);
NODEPTR get_node(int n, NODEPTR head); // Counting from 0,1...

int main(void)
{
    NODEPTR hd;
    hd = create_node();
    printf("original node list:\n");
    output_node_list(hd);
    // printf("---\n%d\n",get_node(2,hd)->data);
    printf("\ninsert at no.:");
    int tmp;
    scanf("%d", &tmp);
    insert_node(get_node(tmp - 1, hd), &hd);
    printf("\n-----after insert\n");
    output_node_list(hd);
    printf("\ndelete no.:");
    scanf("%d", &tmp);
    delete_node(get_node(tmp - 1, hd), &hd);
    printf("\n-----after delete\n");
    output_node_list(hd);
    free(hd);
    return 0;
}

NODEPTR create_node(void)
{
    NODEPTR currentptr = NULL, headptr = NULL, lastptr = NULL;
    int num;
    scanf("%d", &num);
    while (num != -1)
    {
        currentptr = malloc(sizeof(NODE));
        currentptr->data = num;
        if (headptr == NULL) // It is the head of node
        {
            headptr = currentptr;
            lastptr = currentptr;
            currentptr->next = NULL;
        }
        else // In the middle of node
        {
            lastptr->next = currentptr;
            lastptr = currentptr;
            currentptr->next = NULL;
        }
        scanf("%d", &num);
    }
    return headptr;
}

void insert_node(NODEPTR previous, NODEPTR *head) // Send the address of the pointer head
{
    NODEPTR newptr = malloc(sizeof(NODE));
    scanf("%d", &newptr->data);
    if (previous == NULL) // Insert the node at the first place
    {
        NODEPTR current = *head;
        *head = newptr;
        newptr->next = current;
    }
    else if (previous->next == NULL) // Insert the node at the last place
    {
        previous->next = newptr;
        newptr->next = NULL;
    }
    else // In the middle of node
    {
        NODEPTR current = previous->next;
        previous->next = newptr;
        newptr->next = current;
    }
    return;
}
void output_node_list(NODEPTR head)
{
    if (head == NULL)
    {
        printf("Empty Node List\n");
        return;
    }
    NODEPTR current = head;
    while (current != NULL)
    {
        printf("%d\t", current->data);
        current = current->next;
    }
    return;
}
NODEPTR get_node(int n, NODEPTR head) // counting from 0,1...
{
    int cnt = 0;
    NODEPTR current = head;
    while (cnt < n)
    {
        current = current->next;
        cnt++;
    }
    return current;
}
void delete_node(NODEPTR previous, NODEPTR *head)
{
    if (previous == NULL) // Delete the first node
    {
        *head = (*head)->next;
    }
    else if (previous->next == NULL)
    {
        return;
    }
    else
    {
        NODEPTR temp = previous->next->next;
        previous->next = temp;
    }
}