#include <iostream>
#include "BinaryTree.cpp"

using namespace std;
int main()
{
  cout << "Enter levels of Binary Tree: ";
  int levels;
  cin >> levels;

  BinaryTree tree(levels);
  int choice;
  while (choice != 14)
  {
    cout << "\nChoose An Option:\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Find\n";
    cout << "4. Print Level Order\n";
    cout << "5. Get Right Child\n";
    cout << "6. Get Left Child\n";
    cout << "7. Get Parent\n";
    cout << "8. Is Empty\n";
    cout << "9. Size\n";
    cout << "10. Inorder Traversal\n";
    cout << "11. Preorder Traversal\n";
    cout << "12. Postorder Traversal\n";
    cout << "13. Level Order Traversal\n";
    cout << "14. Exit\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
      int data;
      cout << "Enter data to insert: ";
      cin >> data;
      tree.insert(data);
      break;
    }
    case 2:
    {
      int data;
      cout << "Enter data to delete: ";
      cin >> data;
      tree.Delete(data);
      break;
    }
    case 3:
    {
      int data;
      cout << "Enter data to find: ";
      cin >> data;
      int found = tree.find(data);
      if (found != -1)
      {
        cout << "Found at index: " << found << endl;
      }
      else
      {
        cout << "Not found" << endl;
      }
      break;
    }
    case 4:
    {
      tree.printLevelOrder();
      break;
    }
    case 5:
    {
      int index;
      cout << "Enter index: ";
      cin >> index;
      int rightChild = tree.getRightChild(index);
      if (rightChild != -1)
      {
        cout << "Right child: " << rightChild << endl;
      }
      else
      {
        cout << "No right child" << endl;
      }
      break;
    }
    case 6:
    {
      int index;
      cout << "Enter index: ";
      cin >> index;
      int leftChild = tree.getLeftChild(index);
      if (leftChild != -1)
      {
        cout << "Left child: " << leftChild << endl;
      }
      else
      {
        cout << "No left child" << endl;
      }
      break;
    }
    case 7:
    {
      int index;
      cout << "Enter index: ";
      cin >> index;
      int parent = tree.getParent(index);
      if (parent != -1)
      {
        cout << "Parent: " << parent << endl;
      }
      else
      {
        cout << "No parent" << endl;
      }
      break;
    }
    case 8:
    {
      if (tree.isEmpty())
      {
        cout << "Tree is empty" << endl;
      }
      else
      {
        cout << "Tree is not empty" << endl;
      }
      break;
    }
    case 9:
    {
      cout << "Size: " << tree.size() << endl;
      break;
    }
    case 10:
    {
      Node *head = tree.traverseInOrder(0);
      break;
    }
    case 11:
    {
      Node *head = tree.traversePreOrder(0);
      break;
    }
    case 12:
    {
      Node *head = tree.traversePostOrder(0);
      break;
    }
    case 13:
    {
      Node *head = tree.levelOrderTraversal();
      break;
    }
    case 14:
      cout << "Exiting...\n";
      break;
    default:
      cout << "Invalid choice!\n";
    }
  }
}
