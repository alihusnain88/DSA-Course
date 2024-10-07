/*
    Assignment - 3
   Muhammad Ali Husnain
   Roll No:  BCSF22M039

*/

#include <bits/stdc++.h>
#include "Tree.h"
#include "Tree.cpp"

using namespace std;

int main()
{

    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Are Trees Same?\n";
        cout << "2. Find kth largest and smallest\n";
        cout << "3. Print Boundaries\n";
        cout << "4. Is Sum Tree?\n";
        cout << "5. BST or not?\n";
        cout << "6. Sort Using Heap Sort\n";
        cout << "7. Remove Inside range\n";
        cout << "8. Remove Outside range\n";
        cout << "9. Complete Tree or not?\n";
        cout << "10. Print Reverse Levels\n";
        cout << "11. Calculate Height - Iterative\n";
        cout << "12. Calculate Height - Recursive\n";
        cout << "13. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\n*** Build First Tree ***\n";
            BinaryTree tree1;
            tree1.buildTree();

            cout << "\n*** Build Second Tree ***\n";
            BinaryTree tree2;
            tree2.buildTree();

            if (tree1.areSame(tree1.getRoot(), tree2.getRoot()))
            {
                cout << "\nBoth trees are same\n";
            }
            else
            {
                cout << "\nTrees are not same\n";
            }
            break;
        }
        case 2:
        {
            cout << "\n*** Build Tree ***\n";
            BST tree3;
            tree3.buildTree();

            int k, count = 0;
            cout << "Enter value of k: ";
            cin >> k;
            cout << k << "th largest element: " << tree3.kthLargest(tree3.getRoot(), k, count);
            cout << k << "th smallest element: " << tree3.kthSmallest(tree3.getRoot(), k, count);

            break;
        }
        case 3:
        {
            cout << "\n*** Build Tree ***\n";
            BinaryTree tree4;
            tree4.buildTree();
            cout << "Boundaries are: \n";
            tree4.printBoundary(tree4.getRoot());

            break;
        }
        case 4:
        {
            cout << "\n*** Build Tree ***\n";
            BinaryTree tree5;
            tree5.buildTree();

            if (tree5.isSumTree(tree5.getRoot()))
            {
                cout << "\nThis is a sum tree\n";
            }
            else
            {
                cout << "\nNot a sum tree\n";
            }
            break;
        }
        case 5:
        {
            cout << "\n*** Build Tree ***\n";
            BinaryTree tree6;
            tree6.buildTree();

            if (tree6.isBST(tree6.getRoot()))
            {
                cout << "\nThis is a BST\n";
            }
            else
            {
                cout << "\nNot a BST\n";
            }
            break;
        }
        case 6:
        {
            cout << "\n*** Build Tree ***\n";
            BinaryTree tree7;
            tree7.buildTree();

            cout << "\nOriginal Tree: \n";
            tree7.printTree();
            tree7.sortTreeUsingHeapSort(tree7.getRoot());
            cout << "\nSorted Tree:\n";
            tree7.printTree();
            break;
        }
        case 7:
        {
            cout << "\n*** Build Tree ***\n";
            BST tree8;
            tree8.buildTree();
            int first, last;
            cout << "Enter starting point: ";
            cin >> first;
            cout << "Enter ending point: ";
            cin >> last;

            cout << "Original Tree:\n";
            tree8.printTree();

            tree8.removeRange(tree8.getRoot(), first, last);

            cout << "Modified Tree:\n";
            tree8.printTree();
            break;
        }
        case 8:
        {
            cout << "\n*** Build Tree ***\n";
            BST tree9;
            tree9.buildTree();
            int first, last;
            cout << "Enter starting point: ";
            cin >> first;
            cout << "Enter ending point: ";
            cin >> last;

            cout << "Original Tree:\n";
            tree9.printTree();

            tree9.removeRangeOutside(tree9.getRoot(), first, last);

            cout << "Modified Tree:\n";
            tree9.printTree();
            break;
        }
        case 9:
        {
            cout << "\n*** Build Tree ***\n";
            BST tree9;
            tree9.buildTree();

            if (tree9.isCompleteTree())
            {
                cout << "\nThis is a complete tree\n";
            }
            else
            {
                cout << "\nNot a complete binary tree\n";
            }

            break;
        }
        case 10:
        {
            BinaryTree tree10;
            tree10.buildTree();
            cout << "\nReverse Level Printing\n";
            tree10.printReverseOrder();
            break;
        }
        case 11:
        {
            BinaryTree tree11;
            tree11.buildTree();

            cout << "\nHeight of tree (iterative) is: " << tree11.iterativeHeight() << endl;

            break;
        }
        case 12:
        {
            BinaryTree tree12;
            tree12.buildTree();

            cout << "\nHeight of tree (recursive) is: " << tree12.recursiveHeight(tree12.getRoot()) << endl;

            break;
        }
        case 13:
        {
            cout <<"... Exiting ...";
            break;
        }
        
        default:
        {
            cout << "Invalid choice\n";
            break;
        }
        }
    } while (choice != 13);

    return 0;
}