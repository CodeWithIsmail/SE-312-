#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> production = {{"A1B"}, {"0A", ""}, {"0B", "1B", ""}};
vector<string> derivation;
bool match = false;
string input;

void left_derivation(string temp, vector<string> ans)
{
    if (temp.size() > input.size() + 1 || match)
        return;

    if (temp == input)
    {
        match = true;
        for (int x = 0; x < ans.size(); x++)
        {
            derivation.push_back(ans[x]);
        }
        derivation.push_back(temp);
        return;
    }
    ans.push_back(temp);
    if (temp == "")
    {
        for (int i = 0; i < production.size(); i++)
        {
            for (auto x : production[i])
            {
                temp = x;
                left_derivation(temp, ans);
            }
        }
    }
    else
    {
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] == 'A')
            {
                for (auto x : production[1])
                {
                    string current = temp;
                    current.erase(i, 1);
                    current.insert(i, x);
                    left_derivation(current, ans);
                }
            }
            else if (temp[i] == 'B')
            {
                for (auto x : production[2])
                {
                    string current = temp;
                    current.erase(i, 1);
                    current.insert(i, x);
                    left_derivation(current, ans);
                }
            }
        }
    }
}

void right_derivation(string temp, vector<string> ans)
{
    if (temp.size() > input.size() + 1 || match)
        return;

    if (temp == input)
    {
        match = true;
        for (int x = 0; x < ans.size(); x++)
        {
            derivation.push_back(ans[x]);
        }
        derivation.push_back(temp);
        return;
    }
    ans.push_back(temp);
    if (temp == "")
    {
        for (int i = 0; i < production.size(); i++)
        {
            for (auto x : production[i])
            {
                temp = x;
                right_derivation(temp, ans);
            }
        }
    }
    else
    {
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            if (temp[i] == 'A')
            {
                for (auto x : production[1])
                {
                    string current = temp;
                    current.erase(i, 1);
                    current.insert(i, x);
                    right_derivation(current, ans);
                }
            }
            else if (temp[i] == 'B')
            {
                for (auto x : production[2])
                {
                    string current = temp;
                    current.erase(i, 1);
                    current.insert(i, x);
                    right_derivation(current, ans);
                }
            }
        }
    }
}

int main()
{
    vector<string> ans;
    cin >> input;
    left_derivation("", ans);
    match ? cout << "YES" : cout << "NO";
    cout << "\nLeftmost: S";
    for (int i = 1; i < derivation.size(); i++)
        cout << " => " << derivation[i];
    cout << "\n";

    derivation.clear();
    ans.clear();
    match = false;

    right_derivation("", ans);
    match ? cout << "YES" : cout << "NO";
    cout << "\nRightmost: S";
    for (int i = 1; i < derivation.size(); i++)
        cout << " => " << derivation[i];
    cout << "\n";
}
