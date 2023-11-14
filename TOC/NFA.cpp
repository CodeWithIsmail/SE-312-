#include <bits/stdc++.h>
using namespace std;

int numState, numSymbol, numAccept;
vector<char> states, symbols, accepts;
vector<vector<char>> transition;
map<pair<char, char>, vector<char>> table;
map<char, bool> accpetState;
char start;
string input;
bool check = false;

void nfa(char currentState, int pos)
{
    if (pos == input.size())
    {
        if (accpetState[currentState])
            check = true;
        return;
    }
    for (auto x : table[{currentState, input[pos]}])
    {
        if (check)
            return;
        // cout << x << " ";
        nfa(x, pos + 1);
    }
    return;
}
void input_take()
{
    freopen("nfa.txt", "r", stdin);
    int i, j, k;

    cin >> numState;
    for (i = 0; i < numState; i++)
    {
        char temp;
        cin >> temp;
        states.push_back(temp);
    }

    cin >> numSymbol;
    for (i = 0; i < numSymbol; i++)
    {
        char temp;
        cin >> temp;
        symbols.push_back(temp);
    }

    for (i = 0; i < numState; i++)
    {
        for (j = 0; j < numSymbol; j++)
        {
            int way;
            cin >> way;
            for (k = 0; k < way; k++)
            {
                char temp;
                cin >> temp;
                table[{states[i], symbols[j]}].push_back(temp);
            }
        }
    }

    cin >> start;

    cin >> numAccept;
    for (i = 0; i < numAccept; i++)
    {
        char temp;
        cin >> temp;
        // accepts.push_back(temp);
        accpetState[temp] = 1;
    }
    cin >> input;
}
int main()
{
    input_take();
    nfa(start, 0);
    if (check)
        cout << "\nACCEPTED";
    else
        cout << "\nREJECTED";
}