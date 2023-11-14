#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream file("sample_code.c");
    if (!file.is_open())
    {
        cout << "Error in file opening.";
        return 0;
    }

    int state = 0, lineNumber = 0, unterminatedComment = -1;
    string line;
    string multilineComment = "";
    vector<pair<int, string>> multiComment;

    while (getline(file, line))
    {
        lineNumber++;

        if (state == 1)
        {
            int commentEnd = line.find("*/");
            int index = 0, last;
            while (line[index] == ' ')
                index++;
            if (commentEnd == -1)
            {
                string comment = line.substr(index);
                multiComment.push_back({lineNumber, comment});
            }
            else
            {
                last = commentEnd - 2;
                string comment = line.substr(index, last - index + 1);
                multiComment.push_back({lineNumber, comment});

                for (auto x : multiComment)
                {
                    if (x.second != "")
                        cout << x.first << " -> " << x.second << endl;
                }
                state = 0;
                multiComment.clear();
                unterminatedComment = -1;
            }
        }
        else
        {
            int index = line.find("//");
            if (index != -1)
            {
                string comment = line.substr(index + 2);
                cout << lineNumber << " -> " << comment << endl;
                continue;
            }

            int indexStart = line.find("/*");

            if (indexStart != -1)
            {
                if (unterminatedComment == -1)
                    unterminatedComment = lineNumber;
                string comment = "";
                int indexEnd = line.find("*/");
                if (indexEnd != -1)
                {
                    comment = line.substr(indexStart + 2, indexEnd - indexStart - 3);
                    cout << lineNumber << " -> " << comment << endl;
                    unterminatedComment = -1;
                }
                else
                {
                    comment = line.substr(indexStart + 2);
                    multiComment.push_back({lineNumber, comment});
                    state = 1;
                }
            }
        }
    }
    if (state == 1)
    {
        cout << "Error: Unterminated comment at line " << unterminatedComment << endl;
    }
}