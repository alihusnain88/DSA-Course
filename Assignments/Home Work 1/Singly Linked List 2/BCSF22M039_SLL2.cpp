#include <iostream>
#include "BCSF22M039_SLL2.h"
using namespace std;

// Node class Constructor
Node::Node(int value): data(value), next(NULL) {}
// Node class Destructor
Node::~Node(){
    if(next!=nullptr){ 
       next=nullptr; 
    }
}

// SLL class Constructor
BCSF22M039_SLL2::BCSF22M039_SLL2(): head(NULL),tail(NULL) {}
//SLL class Destructor
BCSF22M039_SLL2::~BCSF22M039_SLL2(){
    Node* current = head;
    Node* temp;
    while(current != NULL){
        temp = current->next;
        delete current;
        current = temp;
    }    
    head = nullptr;
}
// Insert At End 
void BCSF22M039_SLL2::insertAtEnd(int value){
    Node *newnode = new Node(value);
    if(head == NULL){
        head = tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;   
}
// Insert At First
void BCSF22M039_SLL2::insertAtFirst(int value){
    Node* newnode = new Node(value);
    if(head == NULL){
        head = tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}
// Insert Before
void BCSF22M039_SLL2::insertBefore(int index, int value){
    if(head == NULL){
        cout <<"Empty List!\n\n";
        return;
    }
    if(isValidIndex(index)){
    Node* newnode = new Node(value);
    Node* temp = head;
    if(index == 1){
        newnode->next = head;
        head = newnode;
        cout <<"----------------Value inserted----------------\n\n";
        return;
    }
    for(int i=1; i<index-1; i++){
        temp = temp->next;
    }
    if(temp == head){
        newnode->next = head;
        head = newnode;
        cout <<"----------------Value inserted----------------\n\n";
    }
    else{
    newnode->next = temp->next;
    temp->next = newnode;
        cout <<"----------------Value inserted----------------\n\n";
    }
    }
    else{
        cout <<"Invalid Index!\n\n";
    }
}
// Insert After
void BCSF22M039_SLL2::insertAfter(int index, int value){
    if(head == NULL){
        cout <<"Empty List!\n";
        return;
    }
    if(isValidIndex(index)){
    Node* newnode = new Node(value);
    Node* temp = head;
    for(int i=1; i<index; i++){
        temp = temp->next;
    }
    if(temp == tail){
        tail->next = newnode;
        tail = newnode;
    }
    else{
    newnode->next = temp->next;
    temp->next = newnode;
    cout <<"----------------Value inserted----------------\n";
    }
    }
    else{
        cout <<"Invalid Index!\n\n";
    }
}
// Delete First Occurrence
void BCSF22M039_SLL2::deleteFirstOccurrence(int value){
    if(head == NULL){
        cout <<"Empty List!\n";
        return;
    }
    bool value_found = false;
    // If list contains only one element
    if(head == tail){
       if(head->data == value){//Head is to be deleted
        value_found = true;
        delete head;
        head = tail = NULL;
        cout <<"----------------First occurrence of "<<value <<" deleted----------------\n";
        return;
       }
       else{
        cout <<"*** Value not found!***\n\n";
        return;
       }
    }
    
    // If list has more than one elements and head is to be deleted
    Node* temp = head;      
    Node* next;
    if(head->data == value){
        value_found = true;
        head = head->next;
        delete temp;
        cout <<"----------------First occurrence of "<<value <<" deleted----------------\n";
    }
    else{
    while(temp != NULL){
        if(temp->next->data == value){
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL){
        value_found = false;
    }
    if(temp->next == tail){
        delete temp->next;
        value_found = true;
        temp->next = NULL;
        tail = temp;
        return;
    }
    else{
    value_found = true;
    next = temp->next->next;
    delete temp->next;
    temp->next = next;
    cout <<"----------------First occurrence of "<<value <<" deleted----------------\n";
    }
    }
    if(!value_found){
        cout <<"*** Value not found!***\n";
    }
}
// Delete Kth Occurrence
void BCSF22M039_SLL2::deleteKthOccurrence(int value, int k){
    Node* temp = head;
    int position = 0;
    while(temp->next->data != value && position != k){
        if(temp->next->data == value){
            position++;
        }
    }
    delete temp->next;
    temp->next = temp->next->next;
}
// Delete All Occurrences
void BCSF22M039_SLL2::deleteAllOccurrences(int value){
    if(head == NULL){
        cout <<"No element in the list!\n";
        return;
    }
    if(head->next == NULL && head->data == value){
        delete head;
        head = nullptr;
        return;
    }
    if(head->next == NULL && head->data != value){
      cout <<"Value not found!\n";
      return;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* next = curr->next;

    while(curr != NULL){
        if(curr->data == value){
            delete curr;
            prev->next = next;

            prev = curr;
            curr = next;
            next = curr->next;
        }
    }
}
// Print List
void BCSF22M039_SLL2::printList(){
    if(head == NULL){
        cout <<"No element in the list!\n";
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        cout <<temp->data <<"->";
        temp = temp->next;
    }
    cout <<"NULL\n";
}
// Reverse List
void BCSF22M039_SLL2::reverseList(){
    if(head == NULL){
        return;
    }
    if(head == tail){

        return;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    Node* temp = head;
    head = tail;
    tail = temp;
}
bool BCSF22M039_SLL2::isValidIndex(int index){
    if(index < 1){
        return false;
    }
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    if(index > count){
        return false;
    }
    return true;    
}


