#include <iostream>
#include "Queue.h"
using namespace std;

// Node class Constructor
Node::Node(int value): prev(NULL), data(value), next(NULL) {}
// Node class Destructor
Node::~Node(){
    if(prev!=nullptr){ 
       prev=nullptr; 
    }
    if(next!=nullptr){ 
       next=nullptr; 
    }
}
// Queue class Constructor
Queue::Queue(): front(NULL), rear(NULL) {}
//Queue class Destructor
Queue::~Queue(){
    Node* current = front;
    Node* temp;
    while(current != NULL){
        temp = current->next;
        delete current;
        current = temp;
    }    
    front = rear = nullptr;
}

// Enqueue An Item
void Queue::enqueue(int item){
    Node *newnode = new Node(item);
    if(front == NULL){
        front = rear = newnode;
        return;
    }
    rear->next = newnode;
    newnode->prev = rear;
    rear = newnode;   
}
// Dequeue An Item
int Queue::dequeue(){
    if(front == NULL){
        return -1;
    }
    int front_data = front->data;
    if(front == rear){
        delete front;
        front = rear = NULL;
    }
    else{
    front = front->next;
    delete front->prev;
    front->prev = NULL;
    }
    return front_data;
}
// Add At Front
void Queue::add_front(int item){
    Node* newnode = new Node(item);
    if(front == NULL){
        front = rear = newnode;
        return;
    }
    newnode->next = front;
    front->prev = newnode;
    front = newnode;
}
// Remove rear
int Queue::remove_rear(){
    if(front == NULL){
        return -1;
    }
    int rear_data = rear->data;
    if(front == rear){
        delete rear;
        front = rear = NULL;
        return rear_data;
    }
    rear = rear->prev;
    delete rear->next;
    rear->next = NULL;
    return rear_data;
}
// Peek Front
int Queue::peek_front(){
    if(front == NULL){
        return -1;
    }
    return front->data;
}
// Peek Rear
int Queue::peek_rear(){
    if(rear == NULL){
        return -1;
    }
    return rear->data;
}
// Is Empty
bool Queue::is_empty(){
    return (front == NULL);
}
// Size 
int Queue::size(){
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
void Queue::print(){
    if(front == NULL){
        cout <<"\n------- The Queue Is Empty!!! ---------\n\n";
        return;
    }
    Node* temp = front;
    cout <<"(Front)->";
    while(temp != NULL){
        cout <<temp->data <<"->";
        temp = temp->next;
    }
    cout <<"(Rear)\n\n";
}