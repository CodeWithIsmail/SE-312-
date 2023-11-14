#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, k;
    int state, symbol;
    freopen("dfatoregex.txt", "r", stdin);

    cout << "Enter number of state:\n";
    cin >> state;
    cout << "Enter the states:\n";
    int states[state];
    for (i = 0; i < state; i++)
    {
        cin >> states[i];
    }
    cout << "Enter number of input symbols:\n";
    cin >> symbol;
    cout << "Enter input symbols:\n";
    string symbols[symbol];
    for (i = 0; i < symbol; i++)
    {
        cin >> symbols[i];
    }

    int table[state][symbol];
    cout << "Enter transition table:\n";

    for (i = 0; i < state; i++)
    {
        for (j = 0; j < symbol; j++)
        {
            cin >> table[i][j];
        }
    }

    for (i = 0; i < state; i++)
    {
        for (j = 0; j < symbol; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    // main process start
    string re[state][state + 1][state + 1];

    for (i = 0; i < state; i++)
    {
        for (j = 0; j < state; j++)
        {
            int check = 0;
            if (i == j)
            {
                re[0][i + 1][j + 1] += "E";
                check = 1;
            }
            for (k = 0; k < symbol; k++)
            {
                if (table[i][k] == j + 1)
                {

                    if (check)
                        re[0][i + 1][j + 1] += " + " + symbols[k];
                    else
                        re[0][i + 1][j + 1] += symbols[k];

                    check = 1;

                    // if (i == j)
                    //     re[0][i + 1][j + 1] += "+E ";
                }
            }

            if (check == 0)
                re[0][i + 1][j + 1] += "N";
        }
    }

    for (k = 1; k < state; k++)
    {
        for (int x = 0; x < state; x++)
        {
            for (int y = 0; y < state; y++)
            {
                i = states[x], j = states[y];
                re[k][i][j] = re[k - 1][i][j] + " + " + re[k - 1][i][k] + "(" + re[k - 1][k][k] + ")*" + re[k - 1][k][j];
            }
        }
    }

    cout << "\nReguler expression:\n\n";

    for (k = 0; k < 3; k++)
    {
        for (i = 1; i <= state; i++)
        {
            for (j = 1; j <= state; j++)
            {
                cout << "R" << i << j << "(" << k << "): " << re[k][i][j] << endl
                     << endl;
            }
        }
    }
}