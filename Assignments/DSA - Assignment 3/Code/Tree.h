/*
    Assignment - 3
   Muhammad Ali Husnain
   Roll No:  BCSF22M039

*/

#ifndef TREE_H
#define TREE_H
# include <bits/stdc++.h>
using namespace std;

class BinaryTree;

class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    Node(int = 0);
    Node *getLeft();
    Node *getRight();
    int getData();

    friend class BinaryTree;
    friend class BST;
};

class BinaryTree
{
private:
    Node *root;

    void treeToVector(Node *, vector<int> &);
    void printService(vector<int> &);
    void buildMaxHeap(vector<int> &);
    void maxHeapify(vector<int> &, int , int );
    void inorderTraversalSorted(Node *, vector<int> &, int );
public:
    BinaryTree();
    Node* getRoot();
    Node* insert(Node *, int );
    bool areSame(Node *, Node *);
    void printReverseOrder();
    void printBoundary(Node* );
    void printLeaves(Node* , stack<Node*>& );
    bool isSumTree(Node *);
    bool isBST(Node *);
    void sortTreeUsingHeapSort(Node* );
    int iterativeHeight();
    int recursiveHeight(Node* );
    Node *buildTree();
    void printTree();
    bool isCompleteTree();
};

class BST : public BinaryTree
{
private:
 Node* root;
 Node *minValue(Node *);
public:
    Node *insertInBST(Node *, int );
    int kthLargest(Node *, int, int &);
    int kthSmallest(Node *, int , int &);
    Node *removeRange(Node *, int , int );
    Node* removeRangeOutside(Node* , int , int );
    Node *buildTree();
};

#endif