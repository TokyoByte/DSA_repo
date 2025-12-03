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
        else if(b >= n && b % n < f)
        {
            int x = b % n;

            a[x] =  val;
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
            int z = f % n;

            a[z] = -1;
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
            int g = f % n;
            return a[g];
        }
        else{
            return -1;
        }
    }
    int back()
    {
        if(size() != 0)
        {
            // if(b <= n)
            // {
            //     return a[b - 1];
            // }
            // else
            // {
            //     int y = b % n;
            //     return a[y - 1];
            // }
            return a[(b-1) % n];
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
    void display()
    {
        for(int i = 0; i < n; ++i)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    Queue q(5);

    q.pop();
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
    q.display();

    cout << "q.f : " << q.f << " and q.b : " << q.b << "\n";
    q.push(99);

    cout << "front is : " << q.front() << "\n";

    cout << "back is : " << q.back() << "\n";

    cout << "size is : " << q.size() << "\n";
    q.display();
    cout << "q.f : " << q.f << " and q.b : " << q.b << "\n";

    q.push(344);
    q.pop();
    q.pop();
    q.push(23);
    q.push(345);
    cout << "q.front " << q.front() << "\n";
    cout << "q.back " << q.back() << "\n";
    q.display();
    q.pop();
    cout << "q.front " << q.front() << "\n";
    cout << "q.back " << q.back() << "\n";
    q.display();
    q.pop();
    cout << "q.front " << q.front() << "\n";
    cout << "q.back " << q.back() << "\n";
    q.display();
    q.pop();
    q.display();
    cout << "q.front " << q.front() << "\n";
    cout << "q.back " << q.back() << "\n";
}