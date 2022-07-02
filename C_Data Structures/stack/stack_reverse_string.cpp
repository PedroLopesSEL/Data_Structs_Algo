#include <iostream>
#include <cstring>
#include <stack> // Stack from standart template lib
using namespace std;
// class stack
// {
// private :
//     char A[101];
//     int top;
// public:
//     void push (int x);
//     void pop();
//     int Top();
//     bool IsEmpty();
// };
void Reserve(char *C, int n)
{
    stack<char> S;
    for (size_t i = 0; i < n; i++)
    {
        S.push(C[i]);
    }
    for (size_t i = 0; i < n; i++)
    {
        C[i] = S.top();
        S.pop(); // Stack=(Hello); S.top()= 'o' ; C[0]= 'o';
    }
}

int main()
{
    char C[51];
    cout << "Enter a string: ";
    cin.getline(C, sizeof C);
    cout << "You entered: \n" << C;
    Reserve(C, strlen(C));
    cout << "\nRever what you enter: " << C;
    return 0;
}