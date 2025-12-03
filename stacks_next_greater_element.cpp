
#include <bits/stdc++.h>
using namespace std;

void next_greater(int n, int a[], int ans[])
{
    stack<int> st;
    // ans[n - 1] = -1;
    // st.push(a[n - 1]);

    for(int i = n - 1; i >= 0; --i)
    {
        while(st.size() > 0 && st.top() <= a[i]) 
        {
            //cout << "st.top : " << st.top() << " and a[i] : " << a[i] << "\n";
            st.pop();
        }
        if(st.size() == 0)
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(a[i]);
        //cout << st.top() << " \n";
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    stack<int> st;
    int ans[n];

    next_greater(n, a, ans);

    for(int i = 0; i < n; ++i)
    {
        cout << ans[i] << " ";
    }
}