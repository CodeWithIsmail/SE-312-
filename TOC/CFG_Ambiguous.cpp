#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> production = {{"aS"}, {"aSbS"}, {""}};
vector<vector<string>> derivation;
bool match = false;
string input;

void cfg(string temp, vector<string> ans)
{
    if (temp.size() > input.size() * 2 || match || derivation.size() > 1)
        return;

    if (temp == input)
    {
        match = true;
        ans.push_back(temp);
        derivation.push_back(ans);
        return;
    }
    if (temp == "")
    {
        for (int i = 0; i < production.size(); i++)
        {
            if (match)
            {
                match = false;
            }
            for (int j = 0; j < production[i].size(); j++)
            {
                temp = production[i][j];
                if (temp == "")
                    ans.push_back(temp);
                cfg(temp, ans);
            }
        }
    }
    else
    {
        int x;
        for (int x = 0; x < temp.size(); x++)
            if (temp[x] == 'S')
                break;
        if (x == temp.size())
            return;
        ans.push_back(temp);
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] == 'S')
            {
                for (int j = 0; j < production.size(); j++)
                {
                    for (auto x : production[j])
                    {
                        string u = temp;
                        u.erase(i, 1);
                        u.insert(i, x);
                        cfg(u, ans);
                        if (match)
                            return;
                    }
                }
            }
        }
    }
}

int main()
{
    vector<string> ans;
    cin >> input;
    cfg("", ans);

    for (int i = 0; i < derivation.size(); i++)
    {
        for (auto x : derivation[i])
        {
            x == "" ? cout << "e " : cout << x << " ";
        }
        cout << endl;
    }

    derivation.size() > 1 ? cout << "Ambiguous" : cout << "Not ambigous";
}
