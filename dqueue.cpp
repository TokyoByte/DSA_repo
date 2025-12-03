#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class Dqueue
{
    public:
    node* head;
    node* tail;
    int size;

    Dqueue()
    {
        head = tail = NULL;
        size = 0;
    }
    void pushAtFront(int val)
    {
        node* temp = new node(val);
        if(size == 0)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            head->prev = temp;
            temp->next = head;
            head = temp;          
        }
        ++size;
    }
    void pushAtBack(int val)
    {
        node* temp = new node(val);
        if(size == 0)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        ++size;
    }
    void popAtFront()
    {
        if(size == 0)
        {
            cout << "Underflow\n";
        }
        else
        {
            node* temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
            --size;
        }
    }
    void popAtBack()
    {
        if(size == 0)
        {
            cout << "Underflow\n";
        }
        else
        {
            node*temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(tail);
            --size;
        }
    }
    int front()
    {
        if(size > 0)
        {
            return head->data;
        }
        else{
            cout << "Stack is empty\n";
            return 0;
        }
    }
    int back()
    {
        if(size > 0)
        {
            return tail->data;
        }
        else{
            cout << "Stack is empty\n";
            return 0;
        }
    }
    void display()
    {
        int count = size;
        node* temp = head;
        while(count > 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
            --count;
        }
        cout << "\n";
    }
};
int main()
{
    Dqueue queue;

    queue.popAtBack();
    queue.popAtFront();
    queue.pushAtFront(45);
    cout << "front is : " << queue.front() << "\n";
    cout << "back is : " << queue.back() << "\n";
    queue.pushAtBack(55);
    queue.pushAtBack(65);
    cout << "front is : " << queue.front() << "\n";
    cout << "back is : " << queue.back() << "\n";
    queue.pushAtFront(90);
    queue.display();
}