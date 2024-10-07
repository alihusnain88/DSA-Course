# ifndef DLL2
# define DLL2

class dll;
class Node {
private:
  int data;
  Node* prev;
  Node* next;

public:
  Node(int );
  friend class dll;
};

class dll{
private:
  Node* head;
  Node* tail;

public:
  dll();
  
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