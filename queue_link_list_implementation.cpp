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

    Queue()
    {
        head = tail;
        size = 0;
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
};
int main()
{
    Queue q;
    q.push(10);
    cout << "top is : " << q.front() << "\n";
    q.push(20);
    q.push(30);
    cout << "top is : " << q.front() << "\n";
    cout << "back is : " << q.back() << "\n";
    cout << "size is : " << q.size << "\n";
    q.pop();
    cout << "top is : " << q.front() << "\n";
    cout << "back is : " << q.back() << "\n";
    cout << "size is : " << q.size << "\n";
    q.pop();
    q.pop();cout << "top is : " << q.front() << "\n";
    cout << "back is : " << q.back() << "\n";
    cout << "size is : " << q.size << "\n";
    q.pop();
    cout << "top is : " << q.front() << "\n";
    cout << "back is : " << q.back() << "\n";
    cout << "size is : " << q.size << "\n";
}