#include <bits/stdc++.h>
using namespace std;

void display(queue<int>& q)
{
    int temp = q.size();

    while(temp > 0)
    {
        int x = q.front();
        cout << x << " "; 
        q.pop();
        q.push(x);
        --temp;
    }
    cout << "\n";
}
void reverse(queue<int>& q)
{
    stack<int> st;

    while(q.size() > 0)
    {
        st.push(q.front());
        q.pop();
    }
    while(st.size() > 0)
    {
        q.push(st.top());
        st.pop();
    }
}
void rmv_even_pos(queue<int>& q)
{
    int temp = q.size();
    for(int i = 0 ;i < temp; ++i)
    {
        if(i % 2 != 0)
        {
            q.push(q.front());
        }
        q.pop();
    }
}
int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    
    display(q);
    //cout << q.size() << "\n";

    reverse(q);
    display(q);
    reverse(q);
    display(q);

    rmv_even_pos(q);
    display(q);

    cout <<"Mohit maadarchod\n" << q.back();
}