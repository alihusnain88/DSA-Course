#include <iostream>
#include "BCSF22M039_SLL1.h"
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
BCSF22M039_SLL1::BCSF22M039_SLL1(): head(NULL) {}
// SLL class Destructor
BCSF22M039_SLL1::~BCSF22M039_SLL1(){
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
void BCSF22M039_SLL1::insertAtEnd(int value){
    Node *newnode = new Node(value);
    if(head == NULL){
        head = newnode;
        // newnode->next = NULL;    
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;   
}
// Insert At First
void BCSF22M039_SLL1::insertAtFirst(int value){
    Node* newnode = new Node(value);
    newnode->next = head;
    head = newnode;
}
// Insert Before
void BCSF22M039_SLL1::insertBefore(int index, int value){
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
        newnode->next = head->next;
        head->next = newnode;
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
void BCSF22M039_SLL1::insertAfter(int index, int value){
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

    newnode->next = temp->next;
    temp->next = newnode;
    cout <<"----------------Value inserted----------------\n";
    }
    else{
        cout <<"*** Invalid Index ***\n\n";
    }
}
// Delete First Occurrence
void BCSF22M039_SLL1::deleteFirstOccurrence(int value){
    if(head == NULL){
        cout <<"Empty List!\n";
        return;
    }
    bool value_found = false;
    // If list contains only one element
    if(head->next == NULL){
       if(head->data == value){//Head is to be deleted
        value_found = true;
        delete head;
        head = NULL;
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
        return;
    }
    value_found = true;
    next = temp->next->next;
    delete temp->next;
    temp->next = next;
    cout <<"----------------First occurrence of "<<value <<" deleted----------------\n";
    }
    if(!value_found){
        cout <<"*** Value not found!***\n";
    }
}
// Delete Kth Occurrence
void BCSF22M039_SLL1::deleteKthOccurrence(int value, int k){
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
void BCSF22M039_SLL1::deleteAllOccurrences(int value){
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
void BCSF22M039_SLL1::printList(){
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
void BCSF22M039_SLL1::reverseList(){
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
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
    head = prev;
}
bool BCSF22M039_SLL1::isValidIndex(int index){
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


Node* BCSF22M039_SLL1::reverseRecursive(Node* head)
{
    if(head == nullptr)
    {
        return nullptr;
    }
    if(head->next == nullptr)
    {
        this-> head = head;
        // head->next = nullptr; Not needed because it's already done by chance :)
        return head;
    } 
    Node* received = reverseRecursive(head->next);
    received->next = head;
    head->next = nullptr;
    return head;
}
void BCSF22M039_SLL1::printReverseRecursive(Node* head)
{
    if(head != nullptr)
    {
        printReverseRecursive(head->next);
        cout <<head->data <<"->";
    }
}
Node* BCSF22M039_SLL1::getHead()
{
    return head;
}

int BCSF22M039_SLL1::binarySearch(int key)
{
    int size = 0, count, s, e, m;

    Node* temp = head;
    while(temp->next != nullptr)
    {
        size++;
        temp = temp->next;        
    }
    size++;
    s = 0;
    e = size;

    Node* start = head;
    Node* end = temp;
    Node* middle = nullptr;

    while(start->data <= end->data)
    {
        count = 1;
        temp = head;
        m = (s+e)/2;
        while(count != m)
        {
            count++;
            temp = temp->next;
        }
        middle = temp;
        if(middle->data == key)
        {
            return count;
        }
        if(middle->data > key)
        {
            end = middle;            
            e = m-1;
        }
        else
        {
            start = middle->next;
            s = m+1;
        }
    }
    return -1; 
}
int BCSF22M039_SLL1::BinarySearch(int key)
{
    if(head == nullptr)
    {
        return -1;
    }
    Node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    if(key > temp->data || key < head->data)
    {
        return -1;
    }
    Node* first = head;
    Node* last = temp;
    Node* middle = nullptr;
    Node* slow;
    Node* fast;

    while(first->data <= last->data)
    {
        slow = first;
        fast = first;
    while(fast != last)
    {
        fast = fast->next;
        if(fast != last)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    middle = slow;
    if(middle->data == key)
    {
        return key;
    }
    else if(key < middle->data)
    {
        last = middle;
    }
    else if(middle->data < key)
    {
        first = middle->next;
    }
    }    
    return -1;

}