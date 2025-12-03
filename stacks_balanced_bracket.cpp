#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> st;
    string s;

    cin >> s;
    int ans = 1;

    for(int i = 0; s[i] != '\0'; ++i)
    {
        if(s[i] == '(')
        {
            st.push(s[i]);
        }
        else if(s[i] == ')')
        {
            if(st.size() == 0)
            {
                ans = 0;
                break;
            }
            else
            {
                st.pop();
            }
        }
    }
    if(st.size() != 0)
    {
        ans = 0;
    }
    if(ans == 1)
    {
        cout << "true\n";
    }
    else{
        cout << "False\n";
    }
}