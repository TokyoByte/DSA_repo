#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* left;
    node*right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void display(node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    display(root->left);
    display(root->right);
}

void elements_at_nth_level(node* root, int n, int curr)
{
    if(root == NULL)
    {
        return;
    }
    if(curr == n)
    {
        cout << root->data << " ";
    }
    elements_at_nth_level(root->left, n, curr + 1);
    elements_at_nth_level(root->right, n, curr+1);
}

void level_order_traversal(node* root)
{
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if(temp->left != NULL)
        {
            q.push(temp->left);
        }
        if(temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}
int main()
{
    node* a = new node(1);
    node* b = new node(2);
    node* c = new node(3);
    node* d = new node(4);
    node* e = new node(5);
    node* f = new node(6);
    node* g = new node(7);
    node* h = new node(8);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    f->right = h;

    node* root = a;
    int n = 3;
    display(root);
    cout<< "\n";
    elements_at_nth_level(root, n, 1);
    cout<< "\n";
    level_order_traversal(root);
}