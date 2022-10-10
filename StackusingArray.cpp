/*A stack is a conceptual structure consisting of a set of homogeneous elements and is based on the principle of last in first out (LIFO).
It is a commonly used abstract data type with two major operations, namely push and pop.
*/
// Following is the program to implement a stack data structure using an array in order to understand its features.

#include <iostream>
using namespace std;
#define SIZE 100 // setting SIZE to determine a constant number.
int stack[SIZE]; // define the stack as an array
int top = -1;    // set top =-1

// push operation to insert elements into the stack
void push(int val)
{
    if (top >= SIZE - 1) // condition for overflow
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        stack[top] = val;
    }
}
// pop operation to remove or pop an element from the stack
void pop()
{
    if (top <= -1) // condition for underflow
        cout << "Stack Underflow" << endl;
    else
    {
        cout << "The popped element is " << stack[top] << endl;
        top--;
    }
}
// display the contents of the stack
void display()
{
    if (top >= 0)
    {
        cout << "Stack elements are:";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
    else
        cout << "Stack is empty";
}
// main function
int main()
{
    int x, val;
    cout << "1-> Push in stack" << endl;
    cout << "2-> Pop from stack" << endl;
    cout << "3-> Display stack" << endl;
    cout << "4-> Exit" << endl;
    do
    {
        cout << "Enter choice: " << endl; // your choice of operation
        cin >> x;
        switch (x)
        {
        case 1:
        {
            cout << "Enter the value to be pushed:" << endl;
            cin >> val;
            push(val);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            cout << "Exit" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (x != 4);
    return 0;
}