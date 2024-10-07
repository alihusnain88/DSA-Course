/*
  Muhammad Ali Husnain
  Roll No:  BCSF22M039

  *****************************
    Priority Queue Using DLL2
  *****************************

*/
#include <iostream>
#include "Priority Queue.h"
#include "Priority Queue.cpp"
using namespace std;

int main(){ 
        
    system("cls");
    system("color 6");

    cout <<endl;
    cout <<"*************************\n";
    cout <<"Priority Queue Using DLL2\n";
    cout <<"*************************\n\n";

    PriorityQueue queue;

    int choice;
    int val;
    int priority;
    int item;
    while(choice != 6){
    cout <<"Choose An Option:\n";
    cout <<" 1. Enqueue An Item\n";
    cout <<" 2. Dequeue An Item\n";    
    cout <<" 3. Get Peek Front\n";
    cout <<" 4. Get Size\n";
    cout <<" 5. Print Queue\n";
    cout <<" 6. Exit\n";
    cin>>choice;

    
    switch(choice){
//---------------------------------------------------------------------------------------------  
        case 1:
        cout <<"----------------Enqueueing An Item----------------\n";
        cout <<"Enter value of item to enqueue: ";
        cin >> val;
        cout <<"Enter priority of node: ";
        cin >> priority;

        queue.enqueue(val, priority);
        cout <<"----------------Value Enqueued----------------\n\n";
        break;

//---------------------------------------------------------------------------------------------  
        case 2:
        cout <<"----------------Dequeueing An Item----------------\n";
        item = queue.dequeue();
        if(item == -1){
            cout <<"\n------- The Queue Is Empty!!! ---------\n\n";
        }
        else{
            cout <<"-------------Front Value " <<item <<" Dequeued-------------\n\n";
        }
        break;        
//---------------------------------------------------------------------------------------------  
        case 3:
        cout <<"----------------Get Peek Front----------------\n";
        if(queue.peek_front() == -1){
            cout <<"\n------- The Queue Is Empty!!! ---------\n\n";            
        }
        else{
        cout <<"\nPeek Front Value Of Queue Is: "<<queue.peek_front() <<endl <<endl;
        }
        break;

//---------------------------------------------------------------------------------------------  
        case 4:
        cout <<"---------------------Get Size---------------------\n";
        cout <<"-----------The size of queue is: "<<queue.size() <<" -----------"<<endl <<endl;
        break;
//---------------------------------------------------------------------------------------------  
        case 5:
        cout <<"---------------------Print Queue---------------------\n";
        cout <<"Queue based on decreasing priority from left to right:\n";
        queue.print();
        cout <<endl <<endl;
        break;
//---------------------------------------------------------------------------------------------  
        case 6:
        cout <<"-------------------------Exit-------------------------\n";
        cout <<"-----------------Exited On User Choice----------------\n";
        break;
//---------------------------------------------------------------------------------------------  
        default:
        cout <<"\n!!! Invalid Choice !!!\n\n";
        break;  
    }
    }

    return 0;
}