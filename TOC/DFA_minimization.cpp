#include <bits/stdc++.h>
using namespace std;

int numState, numSymbol, numAccept;
vector<char> states, symbols, accepts;
map<pair<char, char>, char> table;
map<char, bool> accpetState;
map<char, int> inde;
const int mx = 50;
string min_table[mx][mx];
char start;
string input;

void table_filling()
{
    int i, j, k, sym;

    for (i = 0; i < numState; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (accpetState[states[i]] != accpetState[states[j]])
                min_table[i][j] = "X";
            else
                min_table[i][j] = "=";
        }
    }

    for (k = 0; k < numState; k++)
    {
        for (i = 0; i < numState; i++)
        {
            for (j = 0; j < i; j++)
            {
                if (min_table[i][j] == "=")
                {
                    bool check = 0;
                    for (sym = 0; sym < numSymbol; sym++)
                    {
                        char st1 = table[{states[i], symbols[sym]}];
                        char st2 = table[{states[j], symbols[sym]}];

                        int index1 = inde[st1], index2 = inde[st2];
                        if (min_table[max(index1, index2)][min(index1, index2)] == "X")
                        {
                            min_table[i][j] = "X";
                            break;
                        }
                    }
                }
            }
        }
    }
}
void input_take()
{
    int i, j;
    freopen("DFA_minimization.txt", "r", stdin);

    cin >> numState;
    for (i = 0; i < numState; i++)
    {
        char temp;
        cin >> temp;
        states.push_back(temp);
        inde[temp] = i;
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

int main()
{
    input_take();
    table_filling();
    int i, j;
    for (i = 0; i < numState; i++)
    {
        for (j = 0; j < i; j++)
        {
            cout << min_table[i][j] << " ";
        }
        cout << "= \n";
    }
}