#include <iostream>
using namespace std;
class Cache;

class Page
{
private:
 Page* prev;
 int page_value;
 Page* next;
public:
 Page(int v): prev(nullptr), page_value(v), next(nullptr) { }
 ~Page()
 {
    if(prev != nullptr)
    { prev = nullptr; }

    if(next != nullptr)
    { next = nullptr; }
 }
 friend class Cache;
 
};

class Cache
{
private:
 Page* front;
 Page* back;
 int capacity;
 static int hits;
 static int faults;

 int position(int v)
 {
    Page* traverser = back;
    int pos = 0;
    while(traverser)
    {
        pos++;
        if(traverser->page_value == v)
        {
            return pos;
        }
        traverser = traverser->next;
    }
    return -1;
 }
 void addPageAtFront(int v)
 {
    if(back == nullptr)
    {
        front = back = new Page(v);
        return;
    }
    front->next = new Page(v);
    front->next->prev = front;
    front = front->next;
 }
 int size()
 {
    if(back == nullptr) { return 0; }
    int noOfPages;
    Page* traverser = back;
    while(traverser)
    {
        noOfPages++;
        traverser = traverser->next;
    }
    return noOfPages;
 }
 int dequeue()
 {
    int value = back->page_value;
    if(back == front)
    {
        delete back;
        front = back = nullptr;
    }
    else
    {
        back = back->next;
        delete back->prev;
    }
    return value;
 }

public:
 Cache(int c, Page* f = nullptr,  Page* b = nullptr): capacity(c), front(f),  back(b) { }

 int accessPage(int v, int capacity)
 {
    int pos = position(v);
    if(pos != -1)
    {
        Page* traverser = back;
        while(pos != 1)
        {
            pos--;
            traverser = traverser->next;
        }
        if(traverser == front)
        {
            cout <<"\nYou are already on this page!\n";
            return v; 
        }
        int temp = traverser->page_value;
        while(traverser->next != nullptr)
        {
            traverser->page_value = traverser->next->page_value;
            traverser = traverser->next;
        }
        traverser->page_value = temp;
        hits++;
    }
    else 
    {
        if(size() == capacity)
        {
            dequeue();
        }
        addPageAtFront(v);
        faults++;
    }
    return v;
 }
 void HitsAndFaults()
 {
    cout <<"\nHits: ";
    cout <<hits;

    cout <<"\nfaults: ";
    cout <<faults;

 }
 void printPresentPages()
 {
    cout <<"\nPages present in the cache right now:\n";
    if(back == nullptr)
    {
        cout <<"\nNo pages accessed! Pages list is empty.\n"; 
        return;
    }
    Page* traverser = back;
    while(traverser)
    {
        cout <<traverser->page_value <<" ";
        traverser = traverser->next;
    }
 }
 
};
int Cache::hits = 0;
int Cache::faults = 0;

int main(){
    int choice = 1;
    int capacity;

    cout << "Enter cache capacity: ";
    cin >> capacity;

    Cache cache(capacity);

    while (choice != 4) {
        cout << "\nMenu:\n";
        cout << "1. Access / Add A Page\n";
        cout << "2. Print Present Pages\n";
        cout << "3. Show Hits And Faults\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int page;
                cout << "Enter page number to access: ";
                cin >> page;
                cache.accessPage(page, capacity);
                break;
            }
            case 2:
                cache.printPresentPages();
                break;
            case 3:
            cache.HitsAndFaults();
            break;

            case 4:
                cout<<"   Exiting....   ";
                break;
            default:
                cout << "*** Invalid choice! ***\n";
        }
    }
    
    
    return 0;
}