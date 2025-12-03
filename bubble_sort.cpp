#include <iostream>
using namespace std;

int main()
{
    int a[5];
    int n = 5;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    
    for(int i = 0; i < n - 1; ++i)
    {
        bool x = true;
        for(int j = 0; j < n - 1 -i; ++j)
        {
            if(a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                x = false;
            }
        }
        if(x == true)
        {
            break;
        }
    }

    for(int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
}