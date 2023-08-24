#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream file("code.txt");
    if (!file.is_open())
    {
        cout<<"Error in file opening.";
        return 0;
    }

    int state=0,lineNum=0;
    string line;
    while(!file.eof())
    {
        lineNum++;
        getline(file,line);

        if(state==1)
        {
            int temp=line.find("*/");
            int index=0,last;
            while(line[index]==' ') index++;
            temp==-1? last=line.size(): last=temp-2;
            string out=line.substr(index,last-index+1);
            cout<<lineNum<<" -> "<<out<<endl;
            state=0;
        }
        else
        {
            int index=line.find("//");
            if(index!=-1)
            {
                string temp=line.substr(index+2);
                cout<<lineNum<<" -> "<<temp<<endl;
                continue;
            }
            int index1=line.find("/*");

            if(index1!=-1)
            {
                string temp="";
                int index2=line.find("*/");
                if(index2!=-1)
                {
                    temp=line.substr(index1+2,index2-index1-3);
                    // cout<<index1<<" "<<index2<<endl;
                    //for(int i=index1+2; i<index2-1; i++)
                    //  temp+=line[i];
                }
                else
                {
                    temp=line.substr(index1+2);
                    state=1;
                }
                cout<<lineNum<<" -> "<<temp<<endl;
            }
        }
    }
}
