# ifndef SLL1
# define SLL1

#include <iostream>
using namespace std;

class BCSF22M039_SLL1;
class Node{
private:
 int data;
public:
 Node* next;
 Node(int ); 
 ~Node();

 friend class BCSF22M039_SLL1;
};

class BCSF22M039_SLL1{//Changings remaining
private:
 Node* head;
 bool isValidIndex(int );

public:
 BCSF22M039_SLL1();
 ~BCSF22M039_SLL1();

 Node* getHead();
 void insertAtEnd(int );
 void insertAtFirst(int );
 void insertBefore(int, int);
 void insertAfter(int, int);
 void deleteFirstOccurrence(int);
 void deleteKthOccurrence(int, int);
 void deleteAllOccurrences(int);
 void printList();
 void reverseList();
 Node* reverseRecursive(Node* head);
 void printReverseRecursive(Node* );
 int binarySearch(int );
 int BinarySearch(int );
 
};

# endif