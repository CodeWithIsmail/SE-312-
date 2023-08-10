#include <stdio.h>
#include<string.h>
int numOfState, numOfSymbol, numOfAccept, start, end;
int t, i, j, k;
char null='o';

int check(int accept[numOfAccept], int state)
{
    for (i = 0; i < numOfAccept; i++)
    {
        if (accept[i] == state)
        {
            return 1;
        }
    }
    return 0;
}
void nfa(char *input, int pos, int state, int function[numOfState][numOfSymbol][numOfState], int accept[numOfAccept])
{
    if (pos==strlen(input)-1)
    {
        if (check(accept, state)==1)
        {
            printf("%d ", state);
            printf("\nAccepted.\n");
        }
        else
        {
            printf("%d ", state);
            printf("\nRejected.\n");
        }
        return;
    }

    printf("%d ", state);
    int currentValue = input[pos] - '0';
    for (i = 0; i < numOfState; i++)
    {
        if (function[state][currentValue][i]==1)
        {
             nfa(input, pos + 1, state, function[state][currentValue][i],accept[numOfAccept]);
        }
    }
    return;
}

int main()
{
    printf("Enter number of state:\n");
    scanf("%d",&numOfState);

    scanf("%c",&null);
    printf("Enter the states:\n");
    char states[numOfState];

    for(i=0; i<numOfState; i++)
    {
        scanf("%c",&states[i]);
        scanf("%c",&null);
    }

    printf("Enter number of input symbols:\n");
    scanf("%d",&numOfSymbol);
    scanf("%c",&null);
    printf("Enter input symbols:\n");
    char symbols[numOfSymbol];
    for(i=0; i<numOfSymbol; i++)
    {
        scanf("%c",&symbols[i]);
        scanf("%c",&null);
    }

    printf("Enter the transition function:\n");
    int transFunc[numOfState][numOfSymbol][numOfState];

    for (i = 0; i < numOfState; i++)
    {
        for (j = 0; j < numOfSymbol; j++)
        {
            printf("Enter function of %c for input value %d:\n",states[i],j);

            for (k = 0; k < numOfState; k++)
            {
                scanf("%d", &transFunc[i][j][k]);
            }
        }
    }

    printf("Enter Starting State:\n");
    scanf("%d", &start);
    printf("Enter number of Accepting state:\n");
    scanf("%d", &numOfAccept);
    int acceptState[numOfAccept];
    printf("Enter Ending State: ");
    for (i = 0; i < numOfAccept; i++)
        scanf("%d", &acceptState[i]);

    printf("Enter number of testcase:\n");
    scanf("%d", &t);
    while (t--)
    {
        char str[100];
        printf("Enter the String to check : ");
        scanf("%s", &str);

        nfa(str, 0, 0, transFunc, acceptState);
    }
    return 0;
}
