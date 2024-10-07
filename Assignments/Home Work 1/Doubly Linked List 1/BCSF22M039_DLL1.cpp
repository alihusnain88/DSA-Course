#include <iostream>
#include "BCSF22M039_DLL1.h"
using namespace std;
Node::Node(int val) : prev(NULL), data(val), next(NULL) {}
Node::~Node()
{
    if (prev != NULL)
    {
        prev = NULL;
    }
    if (next != NULL)
    {
        next = NULL;
    }
}

dll::dll() : head(NULL) {}
dll::~dll() { head = NULL; }
void dll::insertAtEnd(int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void dll::print()
{
    if (head == NULL)
    {
        cout << "Empty list!\n";
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
void dll::insertAtFirst(int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
void dll::insertBefore(int index, int val)
{
    if (head == NULL)
    {
        cout << "Empty list!\n";
        return;
    }
    if (index < 1)
    {
        cout << "Invalid index! Enter an index from 1 to N.\n";
        return;
    }
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        cout << "No element in the list!\n";
        return;
    }
    if (index == 1)
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        return;
    }
    Node *temp = head;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
        if (temp->next == NULL && i != index)
        {
            cout << "Invalid index! Not enough elements in the list.\n";
            return;
        }
    }
    temp->prev->next = newnode;
    newnode->prev = temp->prev;
    temp->prev = newnode;
    newnode->next = temp;
}
void dll::insertAfter(int index, int val)
{ // Insert After
    if (head == NULL)
    {
        cout << "Empty list!\n";
        return;
    }
    if (index < 1)
    {
        cout << "Invalid index! Enter an index from 1 to N.\n";
        return;
    }
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        cout << "No element in the list!\n";
        return;
    }
    Node *temp = head;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
        if (temp->next == NULL && i != index)
        {
            cout << "Invalid index! Not enough elements in the list.\n";
            return;
        }
    }
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

void dll::reverseDisplay()
{
    if (head == NULL)
    { // No element
        cout << "NO element in the list!\n";
        return;
    }
    if (head->next == NULL)
    { // 1 element
        cout << head->data << endl;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->prev;
    }
}
void dll::listReverse()
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        cout << head->data << "->NULL\n";
        return;
    }
    Node *tempHead = head;
    while (tempHead->next != NULL)
    {
        tempHead = tempHead->next;
    }
    Node *temp = head;
    Node *next;
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = temp->prev;
        temp->prev = next;
        temp = next;
    }
    head = tempHead;
    return;
}

void dll::removeNthFromEnd(int n)
{
    int size = 0;
    if (head != nullptr)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            size++;
            temp = temp->next;
        }
        if (n <= size && n > 0)
        {
            n = size - n; // index toggled
            temp = head;

            int i = 1;
            while (i != n)
            {
                temp = temp->next;
                i++;
            }
            Node *next = temp->next->next;
            delete temp->next;
            temp->next = next;
        }
    }
}
