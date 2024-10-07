# ifndef SLL2
# define SLL2

#include <iostream>
using namespace std;

class BCSF22M039_SLL2;
class Node{
private:
 int data;
 Node* next;
public:
 Node(int ); 
 ~Node();

 friend class BCSF22M039_SLL2;
};

class BCSF22M039_SLL2{
private:
 Node* head;
 Node* tail;
public:
 BCSF22M039_SLL2();
 ~BCSF22M039_SLL2();

 void insertAtEnd(int );
 void insertAtFirst(int );
 void insertBefore(int, int);
 void insertAfter(int, int);
 void deleteFirstOccurrence(int);//Remaining
 void deleteKthOccurrence(int, int);//Remaining
 void deleteAllOccurrences(int);//Remaining
 void printList();
 void reversePrint();//Remaining
 void reverseList();
 bool isValidIndex(int );
};

# endif