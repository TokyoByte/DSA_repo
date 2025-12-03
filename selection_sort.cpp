#include <iostream>
using namespace std;

int main()
{
    int a[6];
    int n = 6;

    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for(int i = 0; i < n - 1; ++i)
    {
        int smallest = i;
        for(int j = i; j < n; ++j)
        {
            if(a[smallest] > a[j])
            {
                smallest = j;
            }
        }
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
    }

    for(int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
}