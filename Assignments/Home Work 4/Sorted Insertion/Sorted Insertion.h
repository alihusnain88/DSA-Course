# ifndef SORTED_INSERTION
# define SORTED_INSERTION
# include <iostream>
using namespace std;

// Insertion Sort Main Algorithm
void insertionSort(int arr[], int size){
    int j;
    for(int i=1; i<size; i++){
        j = i;
        while(j>0 && arr[j]<arr[j-1]){
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}
// Sorted Insert Required Function
int* sortedInsert(int arr[], int size, int value){
    int *newArray = new int[size+1];
    for(int i=0; i<size; i++){
        newArray[i] = arr[i];
    } //All elements copied except the value

    newArray[size] = value;
    
    int iterator = size;
    while(iterator>0 && newArray[iterator]<newArray[iterator-1]){
        swap(newArray[iterator],newArray[iterator-1]);
        iterator--;
    }   
    return newArray;
}
// Printing Array
void print(int arr[], int size){
    for(int i=0; i<size; i++){
        cout <<arr[i] <<" ";
    }
    cout <<endl;
}


# endif