# ifndef PRIORITY_QUEUE
# define PRIORITY_QUEUE
# include <iostream>
using namespace std;

class PriorityQueue;

class Node{
private:
 int data;
 int priority;
 Node* next;
public:
 Node(int, int); 
 Node(int, int, Node*);
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