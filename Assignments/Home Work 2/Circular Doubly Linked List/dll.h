# ifndef DLL
# define DLL
class dll;

class Node{
private:
 Node* prev;
 int data;
 Node* next;
public:
 Node(int);
 ~Node();
 friend class dll;
};
class dll{
private:
 Node* head;
 Node* tail;
public:
 dll();
 ~dll();
 void insertAtEnd(int );
 void insertAtFirst(int );
 void insertBefore(int, int);
 void insertAfter(int, int);
 void delete1stOccurrence(int );
 void deleteKthOccurrence(int, int);
 void deleteAllOccurrences(int);
 void reverseDisplay();
 void print();
};
# endif