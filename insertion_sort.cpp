#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for(int i = 1; i < n; ++i)
    {
        for(int j = i; j > 0; --j)
        {
            if(a[j - 1] > a[j])
            {
                int temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
            else
            {
                break;
            }
            for(int i = 0; i < n; ++i)
            {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }

    for(int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
}