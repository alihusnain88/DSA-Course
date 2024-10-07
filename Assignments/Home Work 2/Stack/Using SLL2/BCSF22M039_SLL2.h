# ifndef SLL
# define SLL
class BCSF22M039_SLL2;

class Node{
private:
 int data;
 Node* next;
public:
 Node(int);
 ~Node();
 friend class BCSF22M039_SLL2;
};

class BCSF22M039_SLL2{
private:
 Node* head;
 Node* top;
public:
 BCSF22M039_SLL2();
 ~BCSF22M039_SLL2();
 void push(int );
 void pop();
 int getSize();
 int getTop();
 bool isEmpty();
 void print();
};

# endif