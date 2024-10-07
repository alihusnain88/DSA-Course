#include <iostream>
#include "Circular Queue.h"
using namespace std;

// Node class Constructors
Node::Node(int value) : data(value), next(NULL) {}
Node::Node(int value, Node *nextptr) : data(value), next(nextptr) {}
// Node class Destructor
Node::~Node()
{
    if (next != nullptr)
    {
        next = nullptr; 
    }
}
// Circular Queue class Constructor
CircularQueue::CircularQueue() : front(NULL), rear(NULL) {}
// Circular Queue class Destructor
CircularQueue::~CircularQueue()
{
    Node *current = front;
    Node *temp;
    while (current != rear)
    {
        temp = current->next;
        delete current;
        current = temp;
    }
    delete current; //Deleting rear which is still remaining
    front = rear = nullptr;
}
// Enqueue Item
void CircularQueue::enqueue(int item)
{
    // Empty queue
    if (front == NULL)
    {
        front = rear = new Node(item);
        front->next = front;
        rear->next = front;
        return;
    }
    rear->next = new Node(item, front);
    rear = rear->next;
}
// Dequeue Item
int CircularQueue::dequeue()
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
        Node* temp = front;
        front = front->next;
        delete temp;
        rear->next = front;
    }
    return front_data;
}
// Peak Front
int CircularQueue::peek_front(){
    if(front == NULL){
        return -1;
    }
    return (front->data);
}
// Size
int CircularQueue::size(){
    if(front == NULL){
        return 0;
    }
    int size = 0;
    Node* temp = front;
    while(temp != rear){
        size++;
        temp = temp->next;
    }
    size++;
    return size;
}

// Print
void CircularQueue::print()
{
    if (front == NULL)
    {
        cout << "\n------- The Queue Is Empty!!! ---------\n\n";
        return;
    }
    Node *temp = front;
    cout << "(Front)->";
    while (temp != rear)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout <<rear->data <<"->";
    cout << "(Rear)...\n\n";
}