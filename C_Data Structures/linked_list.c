#include <stdlib.h>
#include <stdio.h>
// If I want to store not a constant number of number of elements int, char, ... We can use a Linked list
//  Acess/Insert/Delete to element Time to acess is porpotional to number of elements  O(n)
//  To start to acess the linlked list we always need the head node
struct Node
{
    int data; /* data */ // 4 bytes
    struct Node *next;   // pointer variable to point to next data memory - 4bytes
};

// Array vs Linked List
/*
Cost of acessing an element : O(1) vs O(N)
Memory requirement : fixed size ex : A[5] can be used or unusedd; five elements vs Consumes less memory

*/
struct Node * head ;

struct Node *Insert(int x, struct Node *HEAD);
void Print(struct Node *HEAD);
void Print(struct Node *HEAD)
{
    printf("List is :\n");
    while (HEAD != NULL)
    {
        printf(" %d", HEAD->data);
        HEAD = HEAD->next;
    }
    printf("\n");
}
struct Node *Insert(int x, struct Node *HEAD)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    // temp->next = NULL;
    // if (HEAD != NULL){ temp->next=HEAD;}
    temp->next = HEAD;
    HEAD = temp;
    return HEAD;
}

int main()
{
    head = NULL;
    struct Node *HEAD = NULL;
    printf("How many number ?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number \n");
        scanf("%d", &x);
        HEAD = Insert(x, HEAD);
        Print(HEAD);
    }

    // struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    // // temp->data = 2;
    // // temp->next = NULL;
    // (*temp).data = 1;
    // (*temp).next = NULL;
    // HEAD = temp;

    return 0;
}
