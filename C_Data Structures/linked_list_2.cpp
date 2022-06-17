#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
Node *head;
void Print();
void Insert(int n);
void Delete(int n);
void Insert(int n)
{
    Node *temp1 = new Node();
    temp1->data = n;
    temp1->next = head; // 1º *temp1(1).data = n ; *temp.next(1) = Null and make head point to temp1(1) 1 ( head -> 1)
    head = temp1;       // 2º *temp1(2).data = n ; *temp1(2).next(2) = head( which is = temp1(1)) and make head = temp1(2) 2->1 and head (2)
} // 3º *temp1(3).data = n ; *temp1(3).next(3) = head( which is = temp1(2)) and make head = temp1(3) 3->2->1 and head (3)
void Print()
{
    Node *temp = head; // 1º temp -> head = (temp1(3))
    printf("Print the list : \n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next; // 1º temp = head -> temp1(3)(*temp1(3).next = temp1(2))
        // 2º temp = head -> temp1(2)(*temp1(2).next= temp1(1)
        // 3º temp = head -> temp1(1)(*temp1(1).next= NULL
        // ends
    }
    printf("\n");
}
// Deletes node at position n
void Delete(int n)
{
    Node *temp1 = head;
    if (n == 1)
    {
        head = temp1->next;
        delete (temp1);
        return;
    }
    int i;
    for (i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next;
        // temp1 points to (n-1)th Node
    }
    Node *temp2 = temp1->next; // nth node
    temp1->next = temp2->next; // n+1th node
    delete (temp2);
}
int main()
{
    head = NULL; // emtpy list
    Insert(1);
    Insert(2);
    Insert(4);
    Insert(5);
    Insert(6);
    int n;
    std::cout << "Enter a position" << std::endl;
    std::cin >> n;
    Delete(n);
    Print();
    return 0;
}