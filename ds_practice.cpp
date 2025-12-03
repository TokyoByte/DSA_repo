#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    class node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

int main()
{
    class node* temp(5);

    node* first(10);

    temp->next = first;

    node*head = temp;

    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}