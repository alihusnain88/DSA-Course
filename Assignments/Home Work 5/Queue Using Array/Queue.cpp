#include <iostream>

using namespace std;

class CircularQueue
{
private:
    int front, rear, capacity;
    int *array;

public:
    CircularQueue(int capacity)
    {
        this->capacity = capacity;
        front = rear = -1;
        array = new int[capacity];
    }

    ~CircularQueue()
    {
        delete[] array;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % capacity == front;
    }

    int size()
    {
        return (isEmpty()) ? 0 : (rear - front + 1) % capacity;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        array[rear] = x;
        if (front == -1)
        {
            front = rear;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int data = array[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        return data;
    }

    int Front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return array[front];
    }

    int Rear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return array[rear];
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i != rear; i = (i + 1) % capacity)
        {
            cout << array[i] << " ";
        }
        cout << array[rear] << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the size of the queue: ";
    cin >> n;

    CircularQueue q(n);

    int choice;
    while (choice != 9)
    {
        cout << "\nChoose An Option:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Rear\n";
        cout << "5. isEmpty\n";
        cout << "6. isFull\n";
        cout << "7. Size\n";
        cout << "8. Print\n";
        cout << "9. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter data to enqueue: ";
            cin >> data;
            q.enqueue(data);
            break;
        }
        case 2:
        {
            int data = q.dequeue();
            if (data != -1)
            {
                cout << "Dequeued element: " << data << endl;
            }
            break;
        }
        case 3:
        {
            int data = q.Front();
            if (data != -1)
            {
                cout << "Front element: " << data << endl;
            }
            break;
        }
        case 4:
        {
            int data = q.Rear();
            if (data != -1)
            {
                cout << "Rear element: " << data << endl;
            }
            break;
        }
        case 5:
        {
            if (q.isEmpty())
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                cout << "Queue is not empty" << endl;
            }
            break;
        }
        case 6:
        {
            if (q.isFull())
            {
                cout << "Queue is full" << endl;
            }
            else
            {
                cout << "Queue is not full" << endl;
            }
            break;
        }
        case 7:
        {
            cout << "Size of queue: " << q.size() << endl;
            break;
        }
        case 8:
        {
            q.print();
            break;
        }
        case 9:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
        }
        }
    }

    return 0;
}