# ifndef CIRCULAR_QUEUE
# define CIRCULAR_QUEUE
# include <iostream>

class CircularQueue;

class Node{
private:
 int data;
 Node* next;
public:
 Node(int ); 
 Node(int , Node* );
 ~Node();

 friend class CircularQueue;
};

class CircularQueue{
private:
 Node* front;
 Node* rear;
public:
 CircularQueue();
 ~CircularQueue();
 void enqueue(int );
 int dequeue();
 int peek_front();
 int size();
 void print();
};


# endif