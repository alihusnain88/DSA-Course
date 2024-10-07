# ifndef DLL
# define DLL
class BCSF22M039_DLL1;

class Node{
private:
 Node* prev;
 int data;
 Node* next;
public:
 Node(int);
 ~Node();
 friend class BCSF22M039_DLL1;
};

class BCSF22M039_DLL1{
private:
 Node* top;
public:
 BCSF22M039_DLL1();
 ~BCSF22M039_DLL1();
 void push(int );
 void pop();
 bool isEmpty();
 int getSize();
 int getTop();
 void print();
};
# endif