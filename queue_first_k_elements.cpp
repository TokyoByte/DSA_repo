#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;

    node(int data1)
    {
        data = data1;
        next = NULL;
    }
};
class Queue
{
    public:
    node* head;
    node* tail;
    int size;
    int n;

    Queue(int N)
    {
        head = tail;
        size = 0;
        n = N;
    }

    void push(int val)
    {
        if(size == 0)
        {
            node* temp = new node(val);
            head = temp;
            tail = head;
            ++size;
        }
        else
        {
            node* temp = new node(val);
            tail->next = temp;
            tail = temp;
            ++size;
        }
    }
    void pop()
    {
        if(size == 0)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            --size;
            node* temp = head;
            head = head->next;
            free(temp);
        }
    }
    int front()
    {
        if(size > 0)
        {
            return head->data;
        }
        else{
            return 0;
        }
    }
    int back()
    {
        if(size > 0)
        {
            return tail->data;
        }
        else
        {
            return 0;
        }
    }
    void display()
    {
        node* temp = head;
        while(temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};
void reversing_k_elemnts(Queue q, int k)
{
    stack<int> s;

    for(int i = 0; i < k; ++i)
    {
        int temp = q.front();
        q.pop();
        s.push(temp);
    }

    while(s.size() > 0)
    {
        q.push(s.top());
        s.pop();
    }

    for(int i = 0; i < k - q.n; ++i)
    {
        int temp2 = q.front();
        q.pop();
        q.push(temp2);
    }
}
int main()
{
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    reversing_k_elemnts(q, 3);
    q.display();
}