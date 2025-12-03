#include <bits/stdc++.h>
using namespace std;

stack<char> doubles(string s)
{
    stack<char> st;

    for(int i = 0; i < s.length(); ++i)
    {
        if(st.size() > 0)
        {
            if(st.top() != s[i])
            {
                st.push(s[i]);
            }
        }
        else
        {
            st.push(s[i]);
        }
    }
    return st;
}
string doubles2(string s)
{
    stack<char> st;
    string a;

    for(int i = 0; i < s.length(); ++i)
    {
        if(st.size() > 0)
        {
            if(st.top() != s[i])
            {
                st.push(s[i]);
                a = a + s[i];
            }
        }
        else
        {
            st.push(s[i]);
            a = a + s[i];
        }
    }
    return a;
}
void display(stack<char> st)
{
    for(int i = 0;st.size() > 0; ++i)
    {
        cout << st.top() << " ";
        st.pop();
    }
}
int main()
{
    string s;
    s = "aaabbcddaabffg";

    stack<char> st = doubles(s);
    cout << doubles2(s) << " \n";
    display(st);
}