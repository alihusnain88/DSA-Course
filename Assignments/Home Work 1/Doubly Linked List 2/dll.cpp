#include <iostream>
#include "dll.h"
using namespace std;

Node::Node(int value) : data(value), prev(nullptr), next(nullptr) {}

dll::dll() : head(nullptr), tail(nullptr) {}


  // Insert at the end
  void dll::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) { // Empty list
      head = tail = newNode;
      return;
    }

    tail->next = newNode; 
    newNode->prev = tail;  
    tail = newNode;        
  }

  // Insert at the first
  void dll::insertAtFirst(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) { 
      head = tail = newNode;
      return;
    }

    newNode->next = head; 
    head->prev = newNode; 
    head = newNode;       
  }

  // Insert before a specific node
  void dll::insertBefore(int index, int value) {
    if (head == nullptr) {
      std::cout << "Empty list!\n";
      return;
    }

    if (index < 1) {
      std::cout << "Invalid index! Enter an index from 1 to N.\n";
      return;
    }

    if (index == 1) {
      insertAtFirst(value);
      return;
    }

    Node* temp = head;
    int count = 1;
    while (temp != nullptr && count < index) { 
      temp = temp->next;
      count++;
    }

    if (temp == nullptr) {
      std::cout << "Invalid index! Not enough elements in the list.\n";
      return;
    }

    Node* newNode = new Node(value);
    newNode->next = temp;   
    newNode->prev = temp->prev; 

    if (temp->prev != nullptr) { 
      temp->prev->next = newNode;
    } else { 
      head = newNode;
    }

    temp->prev = newNode;  
  }

  
  void dll::insertAfter(int index, int value) {
    if (head == nullptr) {
      std::cout << "Empty list!\n";
      return;
    }

    if (index < 1) {
      std::cout << "Invalid index! Enter an index from 1 to N.\n";
      return;
    }

    Node* temp = head;
    int count = 1;
    while (temp != nullptr && count < index) { 
      temp = temp->next;
      count++;
    }

    if (temp == nullptr) {
      std::cout << "Invalid index! Not enough elements in the list.\n";
      return;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next; 

    if (temp->next != nullptr) { 
      temp->next->prev = newNode;
    } else { 
      tail = newNode;
    }

    temp->next = newNode;  
    newNode->prev = temp;   
  }

   // Print the list 
  void dll::printList() {
    if (head == nullptr) {
      std::cout << "Empty list!\n";
      return;
    }

    Node* temp = head;
    while (temp != nullptr) {
      std::cout << temp->data << "->";
      temp = temp->next;
    }
    std::cout << "NULL\n";
  }

  // Print the list in reverse order
  void dll::reversePrint() {
    if (head == nullptr) {
      std::cout << "Empty list!\n";
      return;
    }
    Node* temp = tail;
    while(temp != NULL){
        cout <<temp->data <<"->";
        temp = temp->prev;
    }
  }  

  // Reverse the order of nodes in the list (in-place)
  void dll::reverseList() {
    if (head == nullptr || head->next == nullptr) { 
      return;
    }

    Node* temp = head;
    head = tail; 
    tail = temp;

    while (temp != nullptr) {
      Node* nextNode = temp->next;
      temp->next = temp->prev; 
      temp->prev = nextNode;
      temp = nextNode;
    }
  }