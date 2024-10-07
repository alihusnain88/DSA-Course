# ifndef QUEUE
# define QUEUE
class Queue;

class Node{
private:
 Node* prev;
 int data;
 Node* next;
public:
 Node(int ); 
 ~Node();

 friend class Queue;
};

class Queue{
private:
 Node* front;
 Node* rear;
public:
 Queue();
 ~Queue();
 void enqueue(int );
 int dequeue();
 void add_front(int );
 int remove_rear();
 int peek_front();
 int peek_rear();
 bool is_empty();
 int size();
 void print();
};

# endif