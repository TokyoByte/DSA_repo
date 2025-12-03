#include <iostream>
using namespace std;

class heap
{
    public:
    int * arr;
    int size;
    int total_size;

    heap(int n)
    {
        arr = new int[n];
        total_size = n;
        size = 0;
    }

    void insert(int val)
    {
        if(size == total_size)
        {
            cout << "Heap Overflow\n";
            return;
        }

        arr[size] = val;
        int index = size;
        size++;

        while(index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
        cout << arr[index] << " is inserted into the heap\n";
    }

    void print()
    {
        for(int i = 0; i < size; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    void heapify(int index)
    {
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;

        if(left < size && arr[left] > arr[largest])
        {
            largest = index;
        }
        if(right < size && arr[right] > arr[largest])
        {
            largest = right;
        }

        if(largest != index)
        {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }
    void delete()
    {
        if(size == 0)
        {
            cout << "Heap Underflow\n";
            return;
        }

        cout << arr[0] << "Deleted from the heap\n";
        arr[0] = arr[size - 1];
        size--;
        if(size == 0)
        {
            return;
        }
        heapify(0);
    }
};
int main()
{
    heap H1(6);
    H1.insert(4);
    H1.insert(14);
    H1.insert(11);
    H1.print();
    H1.insert(114);
    H1.insert(24);
    H1.insert(1);
    H1.print();
}