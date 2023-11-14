#include <bits/stdc++.h>
using namespace std;

int numState, numSymbol, numAccept;
vector<char> states, symbols, accepts, transition;
map<pair<char, char>, char> table;
map<char, bool> accpetState;
char start;
string input;

void dfa()
{
    char currentState = start;
    for (auto x : input)
    {
        transition.push_back(currentState);
        currentState = table[{currentState, x}];
    }
    transition.push_back(currentState);
}
void input_take()
{
    int i, j;
    freopen("dfa.txt", "r", stdin);

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
            char temp;
            cin >> temp;
            table[{states[i], symbols[j]}] = temp;
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
void output()
{
    if (accpetState[transition.back()])
        cout << "ACCEPTED\n";
    else
        cout << "REJECTED\n";
    for (int i = 0; i < transition.size() - 1; i++)
        cout << transition[i] << " => ";
    cout << transition.back();
}
int main()
{
    input_take();
    dfa();
    output();
}