#include <iostream>
#include "Priority Queue.h"
using namespace std;

// Node class Constructors
Node::Node(int value, int p) : prev(NULL), data(value), priority(p), next(NULL) {}
Node::Node(Node *prevptr, int value, int p, Node *nextptr) : prev(prevptr), data(value), priority(p), next(nextptr) {}
// Node class Destructor
Node::~Node()
{
    if (prev != nullptr)
    {
        prev = nullptr;
    }
    if (next != nullptr)
    {
        next = nullptr;
    }
}
// PriorityQueue class Constructor
PriorityQueue::PriorityQueue() : front(NULL), rear(NULL) {}
// PriorityQueue class Destructor
PriorityQueue::~PriorityQueue()
{
    Node *current = front;
    Node *temp;
    while (current != NULL)
    {
        temp = current->next;
        delete current;
        current = temp;
    }
    front = rear = nullptr;
}
// Enqueue Item
void PriorityQueue::enqueue(int item, int p)
{
    // Empty queue
    if (front == NULL)
    {
        front = rear = new Node(item, p);
        return;
    }
    // Enqueueing before front
    if (p >= front->priority)
    {
        front = new Node(NULL, item, p, front); // Enqueue item before front
        front->next->prev = front;
        return;
    }
    // Enqueueing after rear
    if (rear->priority >= p)
    {
        rear->next = new Node(rear, item, p, NULL);
        rear = rear->next;
        return;
    }
    // Enqueueing in the middle
    Node *temp = front;
    while (temp->next != NULL && temp->next->priority > p)
    {
        temp = temp->next;
    }
    Node *newnode = new Node(temp, item, p, temp->next);
    temp->next->prev = newnode;
    temp->next = newnode;
}
// Dequeue Item
int PriorityQueue::dequeue()
{
    if (front == NULL)
    { // No element
        return -1;
    }
    int front_data = front->data;
    if (front == rear)
    { // 1 element
        delete front;
        front = rear = NULL;
    }
    else
    { // Multiple elements
        front = front->next;
        delete front->prev;
    }
    return front_data;
}
// Peak Front
int PriorityQueue::peek_front(){
    if(front == NULL){
        return -1;
    }
    return (front->data);
}
// Size
int PriorityQueue::size(){
    if(front == NULL){
        return 0;
    }
    int size = 0;
    Node* temp = front;
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    return size;
}

// Print
void PriorityQueue::print()
{
    if (front == NULL)
    {
        cout << "\n------- The Queue Is Empty!!! ---------\n\n";
        return;
    }
    // cout <<"*** Queue based on node values: \n";
    cout <<"\nPriorities are in angular brackets []\n";
    Node *temp = front;
    cout << "(Front)->";
    while (temp != NULL)
    {
        cout << temp->data <<"[" <<temp->priority<<"]" << "->";
        temp = temp->next;
    }
    cout << "(Rear)\n\n";
}