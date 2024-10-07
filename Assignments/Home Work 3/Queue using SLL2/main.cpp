/* 
   Muhammad Ali Husnain
   Roll No:  BCSF22M039

   ********************
   Queue using SLL2
   ********************

*/
#include <iostream>
#include "Queue.h"
#include "Queue.cpp"
using namespace std;

int main(){ 
    Queue queue;

    int choice;
    int val;
    int item;
    while(choice != 10){
    cout <<"Choose An Option:\n";
    cout <<" 1. Enqueue An Item\n";
    cout <<" 2. Dequeue An Item\n";
    cout <<" 3. Add Front\n";
    cout <<" 4. Remove Rear\n";
    cout <<" 5. Get Peek Front\n";
    cout <<" 6. Get Peek Rear\n";
    cout <<" 7. Is Empty\n";
    cout <<" 8. Get Size\n";
    cout <<" 9. Print Queue\n";
    cout <<" 10. Exit\n";
    cin>>choice;

    
    switch(choice){
//---------------------------------------------------------------------------------------------  
        case 1:
        cout <<"----------------Enqueueing An Item----------------\n";
        cout <<"Enter value of item to enqueue: ";
        cin >> val;
        queue.enqueue(val);
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
        cout <<"----------------Adding At Front----------------\n";
        cout <<"Enter value of item to add at front: ";
        cin >> val;
        queue.add_front(val);
        cout <<"----------------Value Added At Front----------------\n\n";
        break;
//---------------------------------------------------------------------------------------------  
        case 4:
        cout <<"----------------Removing Rear----------------\n";
        item = queue.remove_rear();
        if(item == -1){
            cout <<"\n------- The Queue Is Empty!!! ---------\n\n";
        }
        else{
          cout <<"-------------Rear Value " <<item <<" Removed--------------\n\n";
        }
        break;
//---------------------------------------------------------------------------------------------  
        case 5:
        cout <<"----------------Get Peek Front----------------\n";
        if(queue.peek_front() == -1){
            cout <<"\n------- The Queue Is Empty!!! ---------\n\n";            
        }
        else{
        cout <<"\nPeek Front Value Of Queue Is: "<<queue.peek_front() <<endl <<endl;
        }
        break;
//---------------------------------------------------------------------------------------------  
        case 6:
        cout <<"----------------Get Peek Rear----------------\n";
        if(queue.peek_rear() == -1){
            cout <<"\n------- The Queue Is Empty!!! ---------\n\n";            
        }
        else{
        cout <<"\nPeek Rear Value Of Queue Is: "<<queue.peek_rear() <<endl <<endl;
        }
        break;
//---------------------------------------------------------------------------------------------  
        case 7:
        cout <<"---------------------Is Empty---------------------\n";
        if(queue.is_empty()){
            cout <<"\n------- The Queue Is Empty!!! ---------\n\n";          
        }
        else{            
            cout <<"\n------- The Queue Is Not Empty!!! ---------\n\n";          
        }
        break;
//---------------------------------------------------------------------------------------------  
        case 8:
        cout <<"---------------------Get Size---------------------\n";
        cout <<"-----------The size of queue is: "<<queue.size() <<" -----------"<<endl <<endl;
        break;
//---------------------------------------------------------------------------------------------  
        case 9:
        cout <<"---------------------Print Queue---------------------\n";
        queue.print();
        cout <<endl <<endl;
        break;
//---------------------------------------------------------------------------------------------  
        case 10:
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