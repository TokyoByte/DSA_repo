#include <bits/stdc++.h>

using namespace std;

class Queue
{
public:

    stack<int> st;
    int f;
    int b;

    Queue()
    {
        f = -1;
        b = -1;
    }
    void push(int val)
    {
        st.push(val);
    }
    void pop()
    {
        if(st.size() == 0) return;
        stack<int> helper;

        while(st.size() > 0)
        {
            helper.push(st.top());
            st.pop();
        }
        helper.pop();

        while(helper.size() > 0)
        {
            st.push(helper.top());
            helper.pop();
        }
    }
    int front()
    {
        if(st.size() == 0) return -1;
        stack<int> helper;

        while(st.size() > 0)
        {
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();

        while(helper.size() > 0)
        {
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
};
int main()
{
    Queue q;
    q.push(10);
    cout << q.front() << "\n";
    q.push(20);
    q.pop();
    cout << q.front() << "\n";
}