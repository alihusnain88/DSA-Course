# ifndef STACK_H
# define STACK_H

class Stack
{
private:
 int top;
 int *array;
 int capacity;

public:
 Stack(int );
 void push(int );
 int pop();
 bool isFull();
 bool isEmpty();
 int Size();
 void print();
 
};

# endif