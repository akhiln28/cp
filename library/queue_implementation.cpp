#include <iostream>

using namespace std;

class my_queue
{
public:
    int *arr; 
    int size, capacity; 
    int start, end; 
    my_queue(int capacity)
    {
        this->capacity = capacity;
        arr = (int *) malloc(capacity * sizeof(int));
        start = 0; 
        end = 0; 
    }
    void push(int a)
    {
        if (size == capacity) {
            cout << "size is full" << endl;
            return;
        }
        arr[end] = a; 
        end = (end + 1) % capacity; 
        size++;
    }
    void pop()
    {
        start = (start + 1) % capacity; 
        size--;
    }
    void print_queue()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int front()
    {
        return arr[start];
    }
};

int main()
{
    my_queue q(5); 
    q.push(1);
    q.push(1);
    q.push(2);
    q.print_queue();
    cout << q.front() << endl;
    return 0; 
}