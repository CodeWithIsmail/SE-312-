#include <bits/stdc++.h>
using namespace std;

#define mx 100

int main()
{
    freopen("input.txt", "r", stdin);
    char states[mx], symbol[mx], str[mx], start, end, state, path[mx], paths = 0, p = 0;
    int numState, numsymbol, i, j, k = 0;

    cout<<"Enter number of states:"<<endl;
    cin>>numState;
    cout<<"Enter states:"<<endl;
    for (i = 0; i < numState; i++)
        cin>>states[i];

    cout<<"Enter number of symbols:"<<endl;
    cin>>numsymbol;
    cout<<"Enter symbols:"<<endl;
    for (i = 0; i < numsymbol; i++)
        cin>>symbol[i];

    char transit[numState][numsymbol];
    cout<<"Provide transition functions: \n";
    for (i = 0; i < numState; i++)
    {
        cout<<"Enter transition for state "<<states[i];
        for (j = 0; j < numsymbol; j++)
        {
            cout<<"\nEnter for symbol "<< symbol[j]<<" ";
             cin>>transit[i][j];
        }
    }
    cout << "Enter final state: ";
    cin >> end;
    int finalIndex;
    for (i = 0; i < numState; i++)
    {
        if (end == states[i])
        {
            finalIndex = i;
            break;
        }
    }

    char equiv[numState][numState];

    for (i = 0; i < numState; i++)
    {
        for (j = 0; j < numState; j++)
        {
            equiv[i][j] = ' ';
        }
    }

    for (i = 0; i < numState; i++)
    {
        for (j = 0; j < numState; j++)
        {
            if ((i == finalIndex || j == finalIndex) && i > j)
            {
                equiv[i][j] = 'X';
            }
        }
    }

    for (int f = 0; f < numState; f++)
    {
        for (i = 0; i < numState; i++)
        {
            for (j = 0; j < numState; j++)
            {
                if (i > j)
                {
                    for (k = 0; k < numsymbol; k++)
                    {
                        int x, y;
                        for (int m = 0; m < numState; m++)
                        {
                            if (states[m] == transit[i][k])
                                x = m;
                            if (states[m] == transit[j][k])
                                y = m;
                        }
                        if (equiv[x][y] == 'X' || equiv[y][x] == 'X')
                        {
                            equiv[i][j] = 'X';
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < numState; i++)
    {
        for (j = 0; j < numState; j++)
        {
            if (equiv[i][j] == ' ')
            {
                equiv[i][j] = '=';
            }
        }
    }

    cout << endl;
    for (i = 0; i < numState; i++)
    {
        for (j = 0; j < numState; j++)
            if (i >= j)
                cout << equiv[i][j] << "  ";
        cout << endl;
    }


    vector<set<char>> newState;
    vector<bool>checked(numState, false);

    for (i = 0; i < numState; i++)
    {
        for (j = 0; j < numState; j++)
        {
            if (equiv[i][j] == '=' && i > j)
            {
                set<char> temp;
                temp.insert(states[i]);
                temp.insert(states[j]);
                newState.push_back(temp);
                checked[i]=true;
                checked[j]=true;
            }

        }
    }
    cout << "\nTransitions to New States:\n";
    char newtransit[newState.size()][numsymbol];
    for (i = 0; i < newState.size(); i++)
    {
        for (j = 0; j < numsymbol; j++)
        {
            int temp=-1;
            for (int k = 0; k < numState; k++)
            {
                if (states[k] == *newState[i].begin())
                {
                    temp = k;
                    break;
                }
            }
            if(temp!=-1)
                cout << "state " << *newState[i].begin() << " with " << symbol[j] << " : " << transit[temp][j] << endl;
        }
    }
    for(int i=0; i<numState; i++)
    {
        for(j=0; j<numsymbol; j++)
        {
            if(checked[i]==false)
                cout<<"state "<<states[i]<<" with "<<symbol[j]<<" : "<<transit[i][j]<<endl;
        }
    }
    return 0;
}
