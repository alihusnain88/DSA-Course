#include<iostream>
#include"BCSF22M039_DLL1.h"
using namespace std;
// Node Constructor and Destructor
Node::Node(int val):prev(NULL), data(val), next(NULL){ }
Node::~Node(){
    if(prev != NULL){
        prev = NULL;
    }
    if(next != NULL){
        next = NULL;
    }
}
// List Constructor and Destructor
BCSF22M039_DLL1::BCSF22M039_DLL1():top(NULL){ }
BCSF22M039_DLL1::~BCSF22M039_DLL1(){
    if(top != NULL){
        top = NULL;
    }
}
// Push
void BCSF22M039_DLL1::push(int val){
    Node* newnode = new Node(val);
    if(top == NULL){
        top = newnode;
        cout <<"*** Data pushed successfully! ***\n\n";
        return;
    }
    top->next = newnode;
    newnode->prev = top;
    top = newnode;
    cout <<"*** Data pushed successfully! ***\n\n";
}
// Pop
void BCSF22M039_DLL1::pop(){
    if(isEmpty()){
        cout <<"Stack is empty!\n";
        return;
    }
    if(top->prev == NULL){//1 element
       delete top;
       top = nullptr;
       cout <<"*** Data popped successfully! ***\n\n";
       return;
    }
    top = top->prev;
    delete top->next;
    top->next = NULL;
    cout <<"*** Data popped successfully! ***\n\n";
}
// Is empty
bool BCSF22M039_DLL1::isEmpty(){
    return (top == NULL);
}
// Get stack size
int BCSF22M039_DLL1::getSize(){
    int size = 0;
    if(top == NULL){
        return 0;
    }
    Node* temp = top;
    while(temp != NULL){
        size++;
        temp = temp->prev;
    }
    return size;
}
// Get data at top
int BCSF22M039_DLL1::getTop(){
    if(top == NULL){
        return -1;
    }
    return (top->data);
}
// Print
void BCSF22M039_DLL1::print(){
    if(top == NULL){
        cout <<"Empty list!\n";
        return;
    }
    Node* temp = top;
    while(temp != NULL){
        cout <<temp->data <<"->";
        temp = temp->prev;
    }
    cout <<"NULL\n";
}