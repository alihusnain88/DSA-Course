# ifndef PRIORITY_QUEUE
# define PRIORITY_QUEUE
# include <iostream>
using namespace std;

class PriorityQueue;

class Node{
private:
 Node* prev;
 int data;
 int priority;
 Node* next;
public:
 Node(int, int = 0); 
 Node(Node* = NULL, int = 0, int = 0, Node* = NULL);
 ~Node();

 friend class PriorityQueue;
};

class PriorityQueue{
private:
 Node* front;
 Node* rear;
public:
 PriorityQueue();
 ~PriorityQueue();
 void enqueue(int, int);
 int dequeue();
 int peek_front();
 int size();
 void print();
};

# endif