#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack(int c) : capacity(c), top(-1)
{
    array = new int[capacity];
}

void Stack::push(int element)
{
    if (!isFull())
    {
        array[++top] = element;
    }
    else
    {
        cout <<"\n*** Stack is full! ***\n";
    }
}
int Stack::pop()
{
    if(!isEmpty())
    {
        return (array[top--]);
    }
    else
    {
        cout <<"\n*** Stack is empty! ***\n";
    }
    return -1; 
}

bool Stack::isFull()
{
    return (top == capacity-1);
}
bool Stack::isEmpty()
{
    return (top == -1);
}
int Stack::Size()
{
    return (top + 1);
}
void Stack::print()
{
    int traverser = top;
    while(traverser >= 0)
    {
        cout <<array[traverser--] <<" ";
    }
    cout <<endl;
}