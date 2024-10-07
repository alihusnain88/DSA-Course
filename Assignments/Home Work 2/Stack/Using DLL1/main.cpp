#include <iostream>
#include"BCSF22M039_DLL1.h"
#include"BCSF22M039_DLL1.cpp"
using namespace std;

int main(){
    BCSF22M039_DLL1 stack;
    int data;
    int choice;
    
    while (choice != 7) {
    cout << "Choose An Option:\n";
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Get Size" << endl;
    cout << "4. Get Top" << endl;
    cout << "5. Is Empty" << endl;
    cout << "6. Print Stack" << endl;
    cout << "7. Exit" << endl;
    cin >> choice;

    switch (choice) {
      case 1:
        cout <<"--------------Push-----------------\n";
        cout << "Enter data to push: ";
        cin >> data;
        stack.push(data);
        break;
      case 2:
        cout <<"--------------Pop-----------------\n";        
        stack.pop();
        
        break;
      case 3:
        cout <<"--------------Stack Size-----------------\n";        
        cout << "Stack size: " << stack.getSize() << endl <<endl;
        break;
      case 4:
        cout <<"--------------Top Data-----------------\n";     
        if(stack.getTop() == -1){
            cout <<"Stack is empty!\n\n";
        }   
        else{
        cout << "Top element: " << stack.getTop() << endl <<endl;
        }
        break;
      case 5:
        cout <<"--------------Is Empty-----------------\n";        
        cout << (stack.isEmpty() ? "***Stack is empty!***\n\n" : "***Stack is not empty!***\n\n") << endl;
        break;
      case 6:
        cout <<"--------------Print Stack-----------------\n";        
        stack.print();
        break;
      case 7:
      cout <<"-------------Exit----------------\n";
      cout <<"*** Exited on user choice ***\n\n";
      break;        
      default:
        cout << "Invalid choice! Choose again: ";
    }
  }
    return 0;
}