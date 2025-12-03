#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int a[2*n];

        if(n % 2 == 0)
        {
            for(int i = 1 ;i <= 2*n; ++i)
            {
                if(i == 1 || i == 2*n - 1)
                {
                    cout << 2 << " ";
                }
                else if(i == 2 || n + 1)
                {
                    cout << 1 << " ";
                }
                else if(i <= n)
                {
                    cout << i << " ";
                }
                else
                {
                    if(i*2 <= n)
                    {
                        cout << i*3 << " ";
                    }
                    cout << i*2 << " ";
                }
            }
        }
        else
        {

        }
        for(int i = 0; i < 2*n; ++i)
        {

        }
    }
}