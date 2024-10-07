#include<iostream>
#include"dll.h"
using namespace std;
Node::Node(int val):prev(NULL), data(val), next(NULL){ }
Node::~Node(){
    if(prev != NULL){
        prev = NULL;
    }
    if(next != NULL){
        next = NULL;
    }
}

dll::dll():head(NULL), tail(NULL){ }
dll::~dll(){ head= NULL; tail=NULL; }
void dll::insertAtEnd(int val){
    Node* newnode = new Node(val);
    if(head == NULL){
        head = tail = newnode;
        head->next = head->prev = head;
        tail->next = tail->prev = head;
        return;
    }
    if(head->next == head){
        head->next = newnode;
        newnode->prev = head;
        tail = newnode;
        head->prev = tail;
        tail->next = head;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    head->prev = tail;
    tail->next = head;
}
void dll::print(){
    if(head == NULL){
        cout <<"Empty list!\n";
        return;
    }
    Node* temp = head;
    while(temp->next != head){
        cout <<temp->data <<"->";
        temp = temp->next;
    }
    cout <<temp->data <<endl;    
}
void dll::insertAtFirst(int val){
    Node* newnode = new Node(val);
    if(head == NULL){
        head = tail = newnode;
        head->next = head->prev = head;
        tail->next = tail->prev = head;
        return;
    }
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        head->prev = tail;
        tail->next = head;    
}
void dll::insertBefore(int index, int val){
    if(head == NULL){
        cout <<"Empty list!\n";
        return;
    }
    if(index < 1){
        cout <<"Invalid index! Enter an index from 1 to N.\n";
        return;
    }    
    Node* newnode = new Node(val);
    if(head == NULL){
        cout <<"No element in the list!\n";
        return;
    }
    if(index == 1){
        insertAtFirst(val);
        return;
    }
    Node* temp = head;
    for(int i=1; i<index; i++){
        temp = temp->next;
        if(temp == tail && i!=index){
        cout <<"Invalid index! Not enough elements in the list.\n";
        return;
       }        
    }
    temp->prev->next = newnode;
    newnode->prev = temp->prev;
    temp->prev = newnode;
    newnode->next = temp;
}
void dll::insertAfter(int index, int val){//Insert After
    if(head == NULL){
        cout <<"Empty list!\n";
        return;
    }
    if(index < 1){
        cout <<"Invalid index! Enter an index from 1 to N.\n";
        return;
    }
    Node* newnode = new Node(val);
    if(head == NULL){
        cout <<"No element in the list!\n";
        return;
    }
    Node* temp = head;
    for(int i=1; i<index; i++){
       temp = temp->next;
       if(temp == tail && i!=index){
        cout <<"Invalid index! Not enough elements in the list.\n";
        return;
       }
    }
    if(temp == tail){
        insertAtEnd(val);
        return;
    }
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

// Delete First Occurrence
void dll::delete1stOccurrence(int val){
    if(head == NULL){
        cout <<"Empty list!\n";
        return;
    }
    if(head == NULL){//If no element
        cout <<"No element in the list!\n";
        return;
    }
    Node* temp = head;
    while(temp != tail && temp->data != val){
        temp = temp->next;
    }
    if(temp == head && temp->data == val){//If head is to be deleted
        if(head->next == head){//If only 1 element and that is to be deleted
        head = tail = NULL;
        delete temp;
        return;
        }
        else{//For long list and head is to be deleted
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
            return;
        }
    }
    if(temp == tail && temp->data == val){//If tail is to be deleted
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
        return;
    }
    else{//If value is not found even after reaching tail
        cout <<"Value not found!\n";
        return;
    }
    //For any middle element:
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}
// Delete Kth Occurrence
void dll::deleteKthOccurrence(int val, int k){
    if(head == NULL){//If no element
        cout <<"No element in the list!\n";
        return;
    }
    Node* temp = head;
    int count = 0;
    while(temp != tail && count != k){
        if(temp->data == val){
            count++;
        }
        temp = temp->next;
    }
    temp = temp->prev;
    if(temp == head && temp->data == val){//If head is to be deleted
        if(head->next == head){//If only 1 element and that is to be deleted
        head = tail = NULL;
        delete temp;
        return;
        }
        else{//For long list and head is to be deleted
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
            return;
        }
    }
    if(temp->next == tail && temp->next->data == val){//If tail is to be deleted
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
        return;
    }
    else{//If value is not found even after reaching tail
        cout <<"Value not found!\n";
        return;
    }
    //For any middle element:
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}
void dll::deleteAllOccurrences(int val) {
    if (head == NULL) {//No element
        cout << "Empty list!\n";
        return;
    }
    if(head->next == head){//1 element
        if (head->data == val) {
            delete head;
            head = tail = NULL;
            return;
        }
        else {
            cout << "No occurrences found!\n";
            return;
        }
    }
    else{//More than one elements
        int remaining = 0;
        Node* temp = head;
        //First calculating no. of occurrences
        while (temp != tail) {
            if (temp->data == val) {
                remaining++;
            }
            temp = temp->next;
        }
        if (tail->data == val) {
            remaining++;
        }
        //Occurrences calculated
        if (remaining == 0) {
            cout << "No occurrences found!\n";
        }
        else {
            temp = head;
            while (temp != tail) {
                if (temp->data != val) {
                    temp = temp->next;
                }
                else {
                    if (temp == head) {
                        head = head->next;
                        delete temp;
                        temp = head;
                        head->prev = tail;
                        tail->next = head;
                        remaining--;
                    }
                    else {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        temp = temp->next;
                        delete temp->prev;
                        remaining--;
                    }
                }
                if (remaining == 0) {
                    break;
                }
            }
            if (tail->data == val) {
                if (tail->prev == tail) {
                    delete tail;
                    head = tail = NULL;
                    remaining--;
                }
                else {
                    tail = tail->prev;
                    delete temp;
                    tail->next = head;
                    head->prev = tail;
                    temp = NULL;
                }
            }
        }//While ends
    }
}
void dll::reverseDisplay(){
    if(head == NULL){ //No element
        cout <<"NO element in the list!\n";
        return;
    }
    if(head->next == head){ //1 element
        cout <<head->data <<endl;
        return;
    }
    Node* temp = tail;
    while(temp->prev != tail){
        cout <<temp->data <<"->";
        temp = temp->prev;
    }
    cout <<temp->data <<endl;
}
