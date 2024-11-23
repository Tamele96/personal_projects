#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

struct node *head = NULL;
struct node *tail = NULL;

void insertAtEnd(int data)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    } 
    else 
    {
        tail->next = newNode;
        tail = newNode;
    }
}

int solveJosephus()
{
    struct node *current = head;

    while (current->next != current) 
    {
        struct node *toRemove = current->next;
        current->next = toRemove->next;
        if (toRemove == head)
        {
            head = toRemove->next;
        }
        free(toRemove);
        current = current->next;
    }
    return current->data;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        head=NULL;
        tail=NULL;
        int n;
        scanf("%d",&n);
        for (int i=1 ; i<=n ; i++) {
            insertAtEnd(i);
        }
        int solution = solveJosephus();
        printf("%d\n", solution);
    }
}

