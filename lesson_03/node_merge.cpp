#include <bits/stdc++.h>
#include <malloc.h>
using namespace std;

// Enter -1 to end input
//Merge the node list
struct NODE
{
    int data;
    struct NODE *next;
};
typedef struct NODE node;
typedef struct NODE *nodeptr;

nodeptr create_node(void);
void insert_node(nodeptr previous, nodeptr *head); // Send the address of the pointer head
void output_node_list(nodeptr head);
void delete_node(nodeptr previous, nodeptr *head);
nodeptr get_node(int n, nodeptr head); // Counting from 0,1...
void destroy(nodeptr head);

int main(void)
{
    nodeptr hd1=create_node(),hd2=create_node();
    
    destroy(hd1);
    destroy(hd2);
    return 0;
}

nodeptr create_node(void)
{
    nodeptr currentptr = NULL, headptr = NULL, lastptr = NULL;
    int num;
    scanf("%d", &num);
    while (num != -1)
    {
        currentptr = (nodeptr)malloc(sizeof(NODE));
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

void insert_node(nodeptr previous, nodeptr *head) // Send the address of the pointer head
{
    nodeptr newptr = (nodeptr)malloc(sizeof(NODE));
    scanf("%d", &newptr->data);
    if (previous == NULL) // Insert the node at the first place
    {
        nodeptr current = *head;
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
        nodeptr current = previous->next;
        previous->next = newptr;
        newptr->next = current;
    }
    return;
}
void output_node_list(nodeptr head)
{
    if (head == NULL)
    {
        printf("Empty Node List\n");
        return;
    }
    nodeptr current = head;
    while (current != NULL)
    {
        printf("%d\t", current->data);
        current = current->next;
    }
    return;
}
nodeptr get_node(int n, nodeptr head) // counting from 0,1...
{
    int cnt = 0;
    if (n < 0)
    {
        return NULL;
    }
    nodeptr current = head;
    while (cnt < n)
    {
        current = current->next;
        cnt++;
    }
    return current;
}
void delete_node(nodeptr previous, nodeptr *head)
{
    if (previous == NULL) // Delete the first node
    {
        nodeptr temp=(*head)->next;//
        *head = temp;
        free(temp);//
    }
    else if (previous->next == NULL)
    {
        return;
    }
    else
    {
        nodeptr temp = previous->next->next;
        free(previous->next);//
        previous->next = temp;
    }
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