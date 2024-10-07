#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
using namespace std;

int main()
{
    cout <<"Enter size of stack: ";
    int size;
    cin >> size;
    Stack stack(size);
    int choice;

    while (choice != 7)
    {
        cout << "\nChoose An Option:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Is Full\n";
        cout << "4. Is Empty\n";
        cout << "5. Size\n";
        cout << "6. Print\n";
        cout << "7. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter data to push: ";
            cin >> data;
            stack.push(data);
            break;
        }
        case 2:
        {
            int data = stack.pop();
            if (data != -1)
            {
                cout << "Popped element: " << data << endl;
            }
            break;
        }
        case 3:
        {
            if (stack.isFull())
            {
                cout << "Stack is full" << endl;
            }
            else
            {
                cout << "Stack is not full" << endl;
            }
            break;
        }
        case 4:
        {
            if (stack.isEmpty())
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "Stack is not empty" << endl;
            }
            break;
        }
        case 5:
        {
            cout << "Size of stack: " << stack.Size() << endl;
            break;
        }
        case 6:
        {
            stack.print();
            break;
        }
        case 7:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
        }
        }
    } 
    return 0;
}