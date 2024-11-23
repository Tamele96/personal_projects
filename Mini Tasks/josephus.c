// The code below solves the famous Josephus problem using a circular linked list:
//
// There are N people standing in a circle like 1->2->3...->N->1 and there is a knife.
// Whoever has the knife kills the person next to them and hands over the knife, i.e., if 2 has the knife in 1->2->3->1 then 2 kills 3 and hands over the knife to 1.
// This process continues until there is only one person left, i.e., there is no one left to kill.
// This last person is deemed as the winner. Initially the knife is with person 1.
// For a given N, you need to determine the winner.

// Solved by Daniel Tamele

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

