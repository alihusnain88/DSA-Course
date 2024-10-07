/*
   Muhammad Ali Husnain
   Roll No:  BCSF22M039
   
   *****************
   Sorted Insertion
   *****************
*/
# include <iostream>
# include "Sorted Insertion.h"
using namespace std;
void insertionSort(int [], int );


int main(){
    system("cls");
    system("color 6");
    
    cout <<"*****************\n";
    cout <<"Sorted Insertion\n";
    cout <<"*****************\n";

    cout <<"Enter size of array: ";
    int size;
    cin >> size;

    int *array = new int[size];

   cout <<"Enter array elements:\n";
   for(int i=0; i<size; i++){
    cin >> array[i];
   }
   
   cout <<"Enter value to insert: ";
   int value;
   cin >> value;

   cout <<"\n------------Original Array------------\n";
   print(array, size);

   cout <<"\n---------Sorted Original Array---------\n";
   insertionSort(array, size);
   print(array, size);

   cout <<"\n----------Final Array After Insertion----------\n";
   print(sortedInsert(array, size, value), size+1);
   cout <<endl;
    
    return 0;
}

