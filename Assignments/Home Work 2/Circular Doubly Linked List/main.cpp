#include <iostream>
#include"dll.h"
#include"dll.cpp"
using namespace std;

int main() {
  int choice, data, value, k;
  dll list;

  while (choice != 10){
     cout << "Choose An Option:\n";
     cout << "1. Insert at End" <<  endl;
     cout << "2. Insert at First" <<  endl;
     cout << "3. Insert Before" <<  endl;
     cout << "4. Insert After" <<  endl;
     cout << "5. Delete 1st Occurrence" <<  endl;
     cout << "6. Delete Kth Occurrence" <<  endl;
     cout << "7. Delete All Occurrences" << endl;
     cout << "8. Reverse Display" <<  endl;
     cout << "9. Print List" <<  endl;
     cout << "10. Exit" <<  endl;
     cin >> choice;

    switch (choice) {
      case 1:
        cout << "--------------Insert At End--------------\n" <<  endl;
         cout << "Enter data to insert: ";
         cin >> data;
        list.insertAtEnd(data);
        break;
      case 2:
        cout << "--------------Insert At First--------------\n" <<  endl;
         cout << "Enter data to insert: ";
         cin >> data;
        list.insertAtFirst(data);
        break;
      case 3:
        cout << "--------------Insert Before A Value--------------\n" <<  endl;
         cout << "Enter data to insert: ";
         cin >> data;
         cout << "Enter value before which to insert: ";
         cin >> value;
        list.insertBefore(data, value);
        break;
      case 4:
        cout << "--------------Insert After A Value--------------\n" <<  endl;
         cout << "Enter data to insert: ";
         cin >> data;
         cout << "Enter value after which to insert: ";
         cin >> value;
        list.insertAfter(data, value);
        break;
      case 5:
        cout << "--------------Delete First Occurrence--------------\n" <<  endl;
        cout <<"There is still a bit issue in this functionality!\n";
         cout << "Enter value to delete (1st occurrence): ";
         cin >> value;
        list.delete1stOccurrence(value);
        break;
      case 6:
        cout << "--------------Delete Kth Occurrence--------------\n" <<  endl;
        cout <<"There is still a bit issue in this functionality!\n";
         cout << "Enter value to delete: ";
         cin >> value;
         cout << "Enter occurrence number (k): ";
         cin >> k;
        list.deleteKthOccurrence(value, k);
        break;
      case 7:
          cout << "--------------Delete All Occurrences--------------\n" << endl;
        cout <<"There is still a bit issue in this functionality!\n";
          cout << "Enter value to delete (All occurrences): ";
          cin >> value;
          list.deleteAllOccurrences(value);
          break;
      case 8:
        cout << "--------------Reverse Display--------------\n" <<  endl;
         cout << "List in reverse order:\n";
        list.reverseDisplay();
        break;
      case 9:
        cout << "--------------Print List--------------\n" <<  endl;
         cout << "List:\n";
        list.print();
        break;
     
      case 10:
        cout << "--------------Exit--------------\n" <<  endl;
        cout <<"*** Exited on user choice ***\n";
        break;
      default:
         cout << "Invalid choice!" <<  endl;
    }
  } 

  return 0;
}