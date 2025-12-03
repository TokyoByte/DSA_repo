#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int f;
    int b;
    int*a;
    int n;

    Queue(int N)
    {
        a = new int [N];
        f = -1;
        b = -1;
        n = N;
    }

    void push(int val)
    {
        if(size() == 0)
        {
            ++f;
            b = 1;
            a[f] = val;
        }
        else if(b < n)
        {
            a[b] = val;
            ++b;
        }
        else
        {
            cout << "Overflow\n";
        }        
    }
    void pop()
    {
        if(size() == 0)
        {
            cout << "Stack is empty\n";
        }
        else
        {
            ++f;
            if(f == b)
            {
                f = -1;
                b = -1 ;
            }
        }
    }
    int front()
    {
        if(size() != 0)
        {
            return a[f];
        }
        else{
            return -1;
        }
    }
    int back()
    {
        if(size() != 0)
        {
            return a[b - 1];
        }
        else
        {
            return -1;
        }
    }
    int size()
    {
        return b-f;
    }
};

void display(Queue q)
{
    while(q.size() > 0)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

int main()
{
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout << "front is : " << q.front() << "\n";

    q.pop();

    cout << "front is : " << q.front() << "\n";

    cout << "back is : " << q.back() << "\n";

    cout << "size is : " << q.size() << "\n";
    display(q);
}