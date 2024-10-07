#include<iostream>
#include"BCSF22M039_SLL2.h"
using namespace std;
// Node Constructor and Destructor
Node::Node(int val):data(val), next(NULL){ }
Node::~Node(){
    if(next != NULL){
        next = NULL;
    }
}

// List Constructor and Destructor
BCSF22M039_SLL2::BCSF22M039_SLL2():head(NULL), top(NULL){ }
BCSF22M039_SLL2::~BCSF22M039_SLL2(){
    if(head != NULL){
        head = NULL;
    }
    if(top != NULL){
        top = NULL;
    }
}
// Push
void BCSF22M039_SLL2::push(int val){
    Node* newnode = new Node(val);
    if(head == NULL){
        head = top = newnode;
        cout <<"Data pushed successfully!\n\n";
        return;
    }
    top->next = newnode;
    top = newnode;
    cout <<"Data pushed successfully!\n\n";
}
// Pop
void BCSF22M039_SLL2::pop(){
    if(isEmpty()){//No element
        cout <<"Stack is empty!\n";
        return;
    }
    if(head->next == NULL){//1 element
        delete head;
        head = NULL;
        cout <<"*** Data popped successfully!\n";
        return;
    }
    Node* temp = head;
    while(temp->next != top){
        temp = temp->next;
    }
    top = temp;
    delete temp->next;
    top->next = NULL;
    cout <<"*** Data popped successfully!\n";
}
// Get data at top
int BCSF22M039_SLL2::getTop(){
    if(head == NULL){//No element
        return -1;
    }
    return (top->data);
}
// Is empty
bool BCSF22M039_SLL2::isEmpty(){
    return (head == NULL);
}
// Get list size
int BCSF22M039_SLL2::getSize(){
    int size = 0;
    Node* temp = head;
    if(head == NULL){
        return 0;
    }
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    return size;
}
// Print
void BCSF22M039_SLL2::print(){
    if(head == NULL){
        cout <<"Stack is empty!\n";
        return;
    }
    cout <<"*** Printing stack from bottom to top ***\n";
    Node* temp = head;
    while(temp != NULL){
        cout <<temp->data <<"->";
        temp = temp->next;
    }
    cout <<"NULL\n";
}



