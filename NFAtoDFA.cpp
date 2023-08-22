#include<bits/stdc++.h>
using namespace std;

string transition[100][100][100];
string str[100][100];
int numOfState,numOfSymbol;
string output;
bool check=false;
void NfaToDFa(char states[],char alpha[],map<string,int>index);
//map<string,int>index;

int main()
{
    freopen("nfa.txt","r",stdin);
    int numOfTransition,i,j,k;
    string startState,finishState;
    string input;
    cin>>numOfState>>numOfSymbol;

    char states[numOfState],alpha[numOfSymbol];
    map<string,int>index;
    for(i=0; i<numOfState; i++)
    {
        cin>>states[i];
        string temp="";
        temp.push_back(states[i]);
        index[temp]=i;
    }

    for(i=0; i<numOfSymbol; i++) cin>>alpha[i];

    for(i=0; i<numOfState; i++)
    {
        for(j=0; j<numOfSymbol; j++)
        {
            string temp="";
            cin>>numOfTransition;
            for(k=0; k<numOfTransition; k++)
            {
                cin>>transition[i][j][k];
                temp+=transition[i][j][k];
            }
            transition[i][j][k]='/0';
            str[i][j]=temp;
        }

    }
    cin>>startState>>finishState;

    NfaToDFa(states,alpha,index);
}


void NfaToDFa(char states[],char alpha[],map<string,int>index)
{
    stack<string>state;
    map<string,bool>check;
    int i,j,k,coun=numOfState;

    for(i=0; i<numOfState; i++)
    {
    string temp="";
    temp.push_back(states[i]);
        //state.push(states[i]);
    }
    while(!state.empty())
    {
        string currentState=state.top();
        if(!check[currentState])
        {
            for(j=0; j<numOfSymbol; j++)
            {
                string temp="";
                for(k=0; k<currentState.size(); k++)
                {
                   string temp2="";
                   temp2.push_back(currentState[k]);
                    int tempIn=index[temp2];
                    temp+=str[tempIn][j];
                }
                str[coun][j]=temp;
                if(!check[temp])
                {
                    state.push(temp);
                }
            }
            check[currentState]=true;
            state.pop();
            coun++;
        }
    }

    for(i=0;i<coun;i++)
    {
       for(j=0;j<numOfSymbol;j++)
       {
          cout<<str[i][j]<<" ";
       }
       cout<<endl;
    }
}
