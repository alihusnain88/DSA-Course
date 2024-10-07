#include <iostream>
#include "Queue.h"
using namespace std;

// Node class Constructor
Node::Node(int value): data(value), next(NULL) {}
// Node class Destructor
Node::~Node(){
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
    front = nullptr;
}

// Enqueue An Item
void Queue::enqueue(int item){
    Node *newnode = new Node(item);
    if(front == NULL){
        front = rear = newnode;
        return;
    }
    rear->next = newnode;
    rear = newnode;   
}
// Dequeue An Item
int Queue::dequeue(){
    if(front == NULL){
        return -1;
    }
    int front_data;
    if(front->next == NULL){
        front_data = front->data;
        delete front;
        front = rear = NULL;
        return front_data;
    }
    Node* temp = front->next;
    front_data = front->data;
    delete front;
    front = temp;
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
    front = newnode;
}
// Remove rear
int Queue::remove_rear(){
    if(front == NULL){
        return -1;
    }
    int rear_data;
    if(front == rear){
        rear_data = rear->data;
        delete rear;
        front = rear = NULL;
        return rear_data;
    }
    Node* temp = front;
    while(temp->next != rear){
        temp = temp->next;
    }
    rear_data = rear->data;
    delete rear;
    rear = temp;
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