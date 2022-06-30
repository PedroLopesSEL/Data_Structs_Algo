// C++ program to Implement a stack
// using singly linked list
#include <iostream>
using namespace std;
// Node class to represent
// a node of the linked list.
class Node
{
public:
    int data;
    Node *link;
    // Default constructor
    Node()
    {
        data = 0;
        link = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->link = NULL;
    }
};

// Utility function to add an element
// data in the stack insert at the beginning
class Stack_Linked_list
{
private:
    Node *top;

public:
    Stack_Linked_list() { top = NULL; };

    void push(int);
    int isEmpty();
    int peek();
    void pop();
    void display();
};
void Stack_Linked_list::push(int data)
{

    // Create new node temp and allocate memory in heap
    Node *temp = new Node();

    // Check if stack (heap) is full.
    // Then inserting an element would
    // lead to stack overflow
    if (!temp)
    {
        cout << "\nStack Overflow";
        exit(1);
    }

    // Initialize data into temp data field
    temp->data = data;

    // Put top pointer reference into temp link
    temp->link = top;

    // Make temp as top of Stack
    top = temp;
}

// Utility function to check if
// the stack is empty or not
int Stack_Linked_list::isEmpty()
{
    // If top is NULL it means that
    // there are no elements are in stack
    return top == NULL;
}

// Utility function to return top element in a stack
int Stack_Linked_list::peek()
{

    // If stack is not empty , return the top element
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

// Utility function to pop top
// element from the stack
void Stack_Linked_list::pop()
{
    Node *temp;
    // Check for stack underflow
    if (top == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {

        // Assign top to temp
        temp = top;

        // Assign second node to top
        top = top->link;

        // This will automatically destroy
        // the link between first node and second node

        // Release memory of top node
        // i.e delete the node
        free(temp);
    }
}

// Function to print all the
// elements of the stack
void Stack_Linked_list::display()
{
    Node *temp;

    // Check for stack underflow
    if (top == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {

            // Print node data
            cout << temp->data << "-> ";

            // Assign temp link to temp
            temp = temp->link;
        }
    }
}

// Driver Code
int main()
{
    Stack_Linked_list stack;
    Node *top = new Node();
    // Push the elements of stack
    stack.push(11);
    stack.push(22);
    stack.push(33);
    stack.push(44);

    // Display stack elements
    stack.display();

    // Print top element of stack
    cout << "\nTop element is "
         << stack.peek() << endl;

    // Delete top elements of stack
    stack.pop();
    stack.pop();

    // Display stack elements
    stack.display();

    // Print top element of stack
    cout << "\nTop element is "
         << stack.peek() << endl;

    return 0;
}
