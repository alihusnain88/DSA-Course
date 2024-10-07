#include <iostream>
#include "dll.h"
#include "dll.cpp"
using namespace std;

int main(){
    dll List1;
    cout <<"\nEnter elements to initialize list (-1 to stop): \n";
    int input;

    while (input != -1){
        cin>>input;
        if(input != -1){//Don't insert -1
            List1.insertAtEnd(input);
        }        
    }   

    int choice;
    int val;
    int index;
    int k;

    while(choice != 10){
    cout <<"\nChoose An Option:\n";
    cout <<" 1. Insert At End\n";
    cout <<" 2. Insert At First\n";
    cout <<" 3. Insert Before\n";
    cout <<" 4. Insert After\n";
    cout <<" 5. Print list\n";
    cout <<" 6. List Reverse\n";
    cout <<" 7. Reverse Print\n";
    cout <<" 8. Delete first occurrence\n";
    cout <<" 9. Delete kth occurrence\n";//Remaining
    cout <<" 10. Delete all occurrences\n";//Remaining 
    cout <<" 11. Exit\n";
    cin>>choice;

    
    switch(choice){
//---------------------------------------------------------------------------------------------  
        case 1:
        cout <<"----------------Insert At End----------------\n";
        cout <<"Enter value to insert at end: ";
        cin >> val;
        List1.insertAtEnd(val);
        cout <<"----------------Value inserted At End----------------\n";
        break;
//---------------------------------------------------------------------------------------------- 
        case 2:
        cout <<"----------------Insert At First----------------\n";
        cout <<"Enter value to insert at first: ";
        cin >> val;
        List1.insertAtFirst(val);
        cout <<"----------------Value inserted At First----------------\n";
        break;
//---------------------------------------------------------------------------------------------- 
        case 3:
        cout <<"----------------Insert Before----------------\n";
        cout <<"Enter index to insert value before this index: ";
        cin>>index;
        cout <<"Enter value to insert before specified index: ";
        cin >> val;
        List1.insertBefore(index, val);
        break;
//---------------------------------------------------------------------------------------------- 
        case 4:
        cout <<"----------------Insert After----------------\n";
        cout <<"Enter index to insert value after this index: ";
        cin>>index;
        cout <<"Enter value to insert after specified index: ";
        cin >> val;
        List1.insertAfter(index, val);
        break;
//---------------------------------------------------------------------------------------------- 
        case 5:
        cout <<"----------------Print List------------------\n";
        cout <<"Here is the list till now:\n";
        List1.printList();
        cout <<endl;
        break;
//---------------------------------------------------------------------------------------------- 
        case 6:
        cout <<"----------------List reverse------------------\n";
        cout <<"Original list:\n";
        List1.printList();

        List1.reverseList();

        cout <<"Reversed list:\n";
        List1.printList();
        break;
//---------------------------------------------------------------------------------------------- 
        case 7:
        cout <<"----------------Print Reverse------------------\n";
        cout <<"List printed in reverse order:\n";
        List1.reversePrint();
        break;
//---------------------------------------------------------------------------------------------- 
        case 8:
        cout <<"----------------Delete 1st occurrence------------------\n";
        cout <<"Enter value to delete its first occurrence: ";
        cin >>val;
        // List1.deleteFirstOccurrence(val);
        cout <<"This function is remaining!\n\n";
        break;
//---------------------------------------------------------------------------------------------- 
        case 9:
        cout <<"----------------Delete kth occurrence------------------\n";
        cout <<"Enter value to delete its kth occurrence: ";
        cin >>val;

        cout <<"Enter occurrence (value of k): ";
        cin >>k;

        // List1.deleteKthOccurrence(val, k);
        cout <<"This function is remaining!\n\n";
        // cout <<"----------------Kth occurrence deleted----------------\n";
        break;
//---------------------------------------------------------------------------------------------- 
        case 10:
        cout <<"----------------Delete all occurrences------------------\n";
        cout <<"Enter value to delete its all occurrences: ";
        cin >>val;

        // List1.deleteAllOccurrences(val);
        cout <<"This function is remaining!\n\n";
        // cout <<"----------------All occurrences deleted----------------\n";
        break;
//---------------------------------------------------------------------------------------------- 
        case 11:
        cout <<"----------------Exit----------------\n";
        cout <<"------- Exited on user choice ------\n";
        break;
    }
    }
    return 0;
}