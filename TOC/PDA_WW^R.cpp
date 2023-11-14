#include <bits/stdc++.h>
using namespace std;
string input;

bool pda(int pos)
{
    stack<char> st;
    st.push('$');
    for (int i = 0; i < pos; i++)
    {
        st.push(input[i]);
    }
    for (int i = pos; i < input.size(); i++)
    {
        if (st.top() == input[i])
            st.pop();
        else
            return false;
    }
    st.pop();
    return st.empty();
}

int main()
{
    cin >> input;
    if (input.size() % 2)
    {
        cout << "Rejected";
        return 0;
    }
    else
    {
        bool match = false;
        for (int i = 1; i <= input.size() / 2; i++)
        {
            if (pda(i))
            {
                cout << "Accepted";
                return 0;
            }
        }
    }
    cout << "Rejected";
}
