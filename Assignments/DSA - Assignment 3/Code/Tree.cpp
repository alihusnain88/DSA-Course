/*
    Assignment - 3
   Muhammad Ali Husnain
   Roll No:  BCSF22M039

*/

#include <bits/stdc++.h>
#include "Tree.h"

using namespace std;

Node::Node(int val) : data(val), left(nullptr), right(nullptr) {}

BinaryTree::BinaryTree() : root(nullptr) {}
Node *BinaryTree::getRoot() { return root; }

Node *BinaryTree::insert(Node *root, int val)
{
    if (!root)
    {
        root = new Node(val);
        return root;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (!temp->left)
        {
            temp->left = new Node(val);
            return root;
        }

        q.push(temp->left);

        if (!temp->right)
        {
            temp->right = new Node(val);
            return root;
        }

        q.push(temp->right);
    }

    return root;
}

Node *BST::insertInBST(Node *root, int val)
{
    if (!root)
    {
        root = new Node(val);
        return root;
    }

    if (val < root->data)
    {
        root->left = insertInBST(root->left, val);
    }
    else
    {
        root->right = insertInBST(root->right, val);
    }

    return root;
}

bool BinaryTree::areSame(Node *root1, Node *root2)
{
    vector<int> tree1;
    vector<int> tree2;
    treeToVector(root1, tree1);
    treeToVector(root2, tree2);

    return (tree1 == tree2);
}
void BinaryTree::treeToVector(Node *root, vector<int> &vec)
{
    if (!root)
    {
        return;
    }
    treeToVector(root->left, vec);
    vec.push_back(root->data);
    treeToVector(root->right, vec);
}
int BST::kthLargest(Node *root, int k, int &count)
{
    if (!root)
    {
        return -1;
    }
    int right = kthLargest(root->right, k, count);
    if (right != -1)
    {
        return right;
    }
    if (++count == k)
    {
        return root->data;
    }
    int left = kthLargest(root->left, k, count);
    return left; // It is either the kth largest element or -1(not found)
}
int BST::kthSmallest(Node *root, int k, int &count)
{
    if (!root)
    {
        return -1;
    }

    int left = kthSmallest(root->left, k, count);
    if (left != -1)
    {
        return left;
    }

    if (++count == k)
    {
        return root->data;
    }

    int right = kthSmallest(root->right, k, count);
    return right;
}
void BinaryTree::printReverseOrder()
{
    if (!root)
    {
        cout << "\nEmpty tree !\n";
        return;
    }
    queue<Node *> q;
    vector<int> v; // Stack can also be used for printing in reverse
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        v.push_back(temp->data);
        if (temp->right)
        {
            q.push(temp->right);
        }
        if (temp->left)
        {
            q.push(temp->left);
        }
    } // Vector with reverse order is ready
    printService(v);
}
void BinaryTree::printService(vector<int> &v)
{
    int size = v.size();
    for (int i = size - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void BinaryTree::printBoundary(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";

    Node *temp = root->left;
    while (temp)
    {
        cout << temp->data << " ";
        if (temp->left)
            temp = temp->left;
        else if (temp->right)
            temp = temp->right;
        else
            break;
    }

    stack<Node *> s;
    printLeaves(root, s);
    while (!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }

    temp = root->right;
    while (temp)
    {
        if (temp->right)
            temp = temp->right;
        else if (temp->left)
            temp = temp->left;
        else
            break;
    }
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->left;
    }
}
void BinaryTree::printLeaves(Node *root, stack<Node *> &s)
{
    if (!root)
        return;
    printLeaves(root->left, s);
    if (!root->left && !root->right)
        s.push(root);
    printLeaves(root->right, s);
}
bool BinaryTree::isSumTree(Node *root)
{
    if (!root)
    {
        return true;
    }
    if (!root->left && !root->right)
    {
        return true;
    }
    int leftSum = 0, rightSum = 0;
    if (root->left)
    {
        if (!isSumTree(root->left))
        {
            return false;
        }
        leftSum = root->left->data;
    }
    if (root->right)
    {
        if (!isSumTree(root->right))
        {
            return false;
        }
        rightSum = root->right->data;
    }
    return root->data == leftSum + rightSum;
}

bool BinaryTree::isBST(Node *root)
{
    if (!root)
    {
        return true;
    }
    if (root->left && root->left->data > root->data)
    {
        return false;
    }
    if (root->right && root->right->data < root->data)
    {
        return false;
    }
    return (isBST(root->left) && isBST(root->right));
}
void BinaryTree::sortTreeUsingHeapSort(Node *root)
{
    vector<int> values;
    treeToVector(root, values);
    buildMaxHeap(values);
    for (int i = values.size() - 1; i >= 0; i--)
    {
        swap(values[0], values[i]);
        maxHeapify(values, 0, i);
    }
    inorderTraversalSorted(root, values, 0);
}
void BinaryTree::buildMaxHeap(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, i, n);
    }
}

void BinaryTree::maxHeapify(vector<int> &arr, int i, int n)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, n);
    }
}
void BinaryTree::inorderTraversalSorted(Node *root, vector<int> &values, int index)
{
    if (!root)
        return;
    inorderTraversalSorted(root->left, values, index);
    root->data = values[index++];
}
Node *BST::removeRange(Node *root, int min, int max)
{
    if (!root)
    {
        return root;
    }
    root->left = removeRange(root->left, min, max);
    if (root->data >= min && root->data <= max)
    {
        Node *temp = root;
        root = minValue(root->right);
        if (temp->right != root)
        {
            temp->right = removeRange(temp->right, root->data, max);
        }
        delete temp;
    }
    else
    {
        root->right = removeRange(root->right, min, max);
    }

    return root;
}
Node *BST::removeRangeOutside(Node *root, int min, int max)
{
    if (!root)
        return root;

    root->left = removeRangeOutside(root->left, min, max);

    if (root->data < min || root->data > max)
    {
        Node *temp = root;
        root = minValue(root->right);
        if (temp->right != root)
        {
            temp->right = removeRangeOutside(temp->right, min, max);
        }
        delete temp;
    }
    else
    {
        root->right = removeRangeOutside(root->right, min, max);
    }

    return root;
}
Node *BST::minValue(Node *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}
bool BinaryTree::isCompleteTree()
{
    if (!root)
    {
        return true;
    }

    queue<Node *> q;
    q.push(root);

    bool flag = false;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left)
        {
            q.push(temp->left);
            if (flag)
            {
                return false;
            }
        }
        else
        {
            flag = true;
        }

        if (temp->right)
        {
            q.push(temp->right);
            if (flag)
            {
                return false;
            }
        }
    }

    return true;
}
int BinaryTree::iterativeHeight()
{
    if (!root)
    {
        return 0;
    }

    queue<Node *> q;
    q.push(root);

    int height = 0;

    while (!q.empty())
    {
        int size = q.size();
        height++;

        while (size--)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }

    return height;
}
int BinaryTree::recursiveHeight(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int leftHeight = recursiveHeight(root->left);
    int rightHeight = recursiveHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}
Node *BinaryTree::buildTree()
{
    int input;
    cout << "Enter tree values (-1 to stop):\n";

    while (input != -1)
    {
        cin >> input;
        if(input != -1)
        root = insert(root, input);
    }

    return root;
}
Node *BST::buildTree()
{
    int input;
    cout << "Enter tree values (-1 to stop):\n";

    while (input != -1)
    {
        cin >> input;
        if(input != -1)
        root = insertInBST(root, input);
    }

    return root;
}
void BinaryTree::printTree()
{
    if (!root)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            cout
                << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        cout << endl;
    }
}