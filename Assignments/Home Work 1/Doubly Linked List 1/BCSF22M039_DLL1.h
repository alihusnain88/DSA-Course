#ifndef DLL1
#define DLL1
class dll;

class Node
{
private:
    Node *prev;
    int data;
    Node *next;

public:
    Node(int = 0);
    ~Node();
    friend class dll;
};

class dll
{
private:
    Node *head;

public:
    dll();
    ~dll();
    void insertAtEnd(int);
    void insertAtFirst(int);
    void insertBefore(int, int);
    void insertAfter(int, int);
    void reverseDisplay();
    void print();
    void listReverse();
    void reverseRecursive();
    void removeNthFromEnd(int);
};

#endif
