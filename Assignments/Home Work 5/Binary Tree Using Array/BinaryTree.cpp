#include <iostream>
#include <math.h>
#include "BinaryTree.h"

using namespace std;
BinaryTree::BinaryTree(int levels) : capacity(findCapacity(levels)), leaf(-1)
{
    arr = new int[capacity];
    for(int i=0; i<capacity; i++)
    {
        arr[i] = -1;
    }
}

int BinaryTree::findCapacity(int levels)
{
    int leaves = pow(2, levels - 1);
    int capacity = (leaves * 2) - 1;
    return capacity;
}

bool BinaryTree::insert(int element)
{
    if (leaf < capacity)
    {
        arr[++leaf] = element;
        return true;
    }
    
    return false;
    
}
void BinaryTree::Delete(int index)
{
    if(leaf == -1)
    {
        cout <<"\nEmpty tree!\n";
        return;
    }
    if (index >= capacity || arr[index] == -1)
    {
        return;
    }
    arr[index] = -1;
    leaf--;
    Delete((index * 2) + 1);
    Delete((index * 2) + 2);
}
int BinaryTree::find(int element)
{
    for (int i = 0; i < capacity; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;  
}

void BinaryTree::printLevelOrder()
{
    for (int i = 0; i <= leaf; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int BinaryTree::getRightChild(int index)
{
    if ((index * 2) + 1 >= capacity)
    {
        cout <<"Child Not Found!\n";
        return -1;
    }
    else
    {
        return arr[(index * 2) + 1];
    }
}
int BinaryTree::getLeftChild(int index)
{
    if ((index * 2) + 2 >= capacity)
    {
        cout <<"Child Not Found!\n";
        return -1;
    }
    else
    {
        return arr[(index * 2) + 2];
    }
}
int BinaryTree::getParent(int index)
{
    if (index > 0)
    {
        return arr[((index - 1) / 2)];
    }
    else
    {
        cout << "Invalid Index ! OR No Parent Exists for this index !\n";
        return -1;
    }
}
Node *BinaryTree::traverseInOrder(int index)
{
     if (leaf == -1)
    {
        cout <<"Empty Tree!\n";
        return nullptr;
    }

    if (index >= capacity || arr[index] == -1)
    {
        return nullptr;
    }

    Node *left = traverseInOrder(index * 2 + 1);
    Node *current = new Node(arr[index]);
    cout <<arr[index] <<" "; 
    Node *right = traverseInOrder(index * 2 + 2);  

    if (left)
    {
        Node *last = left;
        while (last->next)
        {
            last = last->next;
        }
        last->next = current;
    }

    current->next = right;

    return left ? left : current;
}
Node *BinaryTree::traversePreOrder(int index)
{
     if (leaf == -1)
    {
        cout <<"Empty Tree!\n";
        return nullptr;
    }
    
    if (index >= capacity || arr[index] == -1)
    {
        return nullptr;
    }

    Node *current = new Node(arr[index]);
    cout <<arr[index] <<" ";
    current->next = traversePreOrder(index * 2 + 1);
    current->next = traversePreOrder(index * 2 + 2);

    return current;
}
Node *BinaryTree::traversePostOrder(int index)
{
     if (leaf == -1)
    {
        cout <<"Empty Tree!\n";
        return nullptr;
    }

    if (index >= capacity || arr[index] == -1)
    {
        return nullptr;
    }

    Node *left = traversePostOrder(index * 2 + 1);
    Node *right = traversePostOrder(index * 2 + 2);
    Node *current = new Node(arr[index]);
    cout <<arr[index] <<" ";

    if (right)
    {
        Node *last = right;
        while (last->next)
        {
            last = last->next;
        }
        last->next = current;
    }

    if (left)
    {
        current->next = left;
    }

    return right ? right : current;
}
Node *BinaryTree::levelOrderTraversal()
{
    if (leaf == -1)
    {
        cout <<"Empty Tree!\n";
        return nullptr;
    }
    dll list;
    for (int i = 0; i < capacity; i++)
    {
        if (arr[i] != -1)
        {
            list.insertAtEnd(arr[i]); 
            cout <<arr[i] <<" ";
        }
        else
        {
            break;
        }
    }
    return list.head; 
}

bool BinaryTree::isEmpty()
{
    return (leaf == -1);
}
int BinaryTree::size()
{
    return (leaf + 1);
} 
