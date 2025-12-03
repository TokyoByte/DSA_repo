#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int* a;
    int idx =-1;
    int n;
    Stack(int N)
    {
        a = new int(n);
        n = N;
    }
    void push(int val)
    {
        // cout << sizeof(a) << " ";
        // cout << sizeof(a[0]) << " ";
        if(idx == sizeof(a)/sizeof(a[0]) - 1)
        {
            cout << "Overflow\n";
        }
        else
        {
            ++idx;
            a[idx] = val;
        }
    }
    void pop()
    {
        if(idx == -1)
        {
            cout << "Underflow\n";
        }
        else
        {
            --idx;
        }
    }
    int top()
    {
        if(idx == -1)
        {
            return 0;
        }
        else
        {
            return a[idx];
        }
    }
    int size()
    {
        return idx + 1;
    }
};
int main()
{
    Stack st(5);
    st.push(5);
    cout << st.top() << "\n";
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "idx : " << st.idx << "\n";
    st.pop();
    cout << st.top()<<"\n";
    cout << st.size() << "\n";
    st.push(44);
    st.push(45);
    st.push(99);
    cout << st.top() << "\n";
}