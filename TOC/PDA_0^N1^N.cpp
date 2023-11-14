#include <bits/stdc++.h>
using namespace std;
string input;
stack<char> st;

bool pda()
{
    bool check = false;
    st.push('$');
    for (auto x : input)
    {
        if (x == '0')
        {
            if (!check)
                st.push('0');
            else
                return false;
        }
        else
        {
            if (st.top() == '0')
            {
                st.pop();
                check = 1;
            }
            else
                return false;
        }
    }
    st.pop();
    return st.empty();
}
int main()
{
    cin >> input;
    pda() ? cout << "ACCEPTED" : cout << "REJECTED";
}
