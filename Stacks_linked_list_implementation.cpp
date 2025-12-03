#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int data1)
    {
        data = data1;
        next = NULL;
    }
};

class Stack
{
public:
    int idx;
    node* head;

    Stack()
    {
        idx = -1;
        head = NULL;
    }
    void push(int val)
    {
        node *temp = new node(val);
        
        temp->next = head;
        head = temp;
        ++idx;
    }
    void pop()
    {
        if(idx >= 0)
        {
            node* temp = head;
            head = head->next;
            free(temp);
            --idx;
        }
        else
        {
            cout << "Underflow\n";
        }
    }
    int top()
    {
        if(idx >= 0)
        {
            return head->data;
        }
        else
        {
            return -1;
        }
    }
    int size()
    {
        if(idx >= 0)
        {
            return idx + 1;
        }
        else
        {
            return -1;
        }
    }
};
int main()
{
    Stack st;

    st.push(10);
    cout << st.top() << "\n";
    st.pop();
    st.pop();
    st.push(20);
    st.push(30);
    st.push(40);
    cout << st.size() << " " << st.top() << "\n";
}