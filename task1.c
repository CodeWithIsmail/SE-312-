#include<stdio.h>
#include<string.h>
int main()
{
    int i,j;
    char null='o';
    int state,symbol;

    printf("Enter number of state:\n");
    scanf("%d",&state);
    scanf("%c",&null);
    printf("Enter the states:\n");
    char states[state];
    for(i=0; i<state; i++)
    {
        scanf("%c",&states[i]);
        scanf("%c",&null);
    }
    printf("Enter number of input symbols:\n");
    scanf("%d",&symbol);
    scanf("%c",&null);
    printf("Enter input symbols:\n");
    char symbols[symbol];
    for(i=0; i<symbol; i++)
    {
        scanf("%c",&symbols[i]);
        scanf("%c",&null);
    }

    char table[state][symbol];
    printf("Enter transition table:\n");
    //scanf("%c",&null);

    for(i=0; i<state; i++)
    {
        for(j=0; j<symbol; j++)
        {
            printf("Enter transition from %c for %c input symbol:\n",states[i],symbols[j]);
            scanf("%c",&table[i][j]);
            scanf("%c",&null);
        }
    }
    char start;
    printf("Enter start:\n");
    scanf("%c",&start);
    scanf("%c",&null);
    printf("Enter number of accepting state:\n");
    int accept;
    scanf("%d",&accept);
    scanf("%c",&null);
    char end[accept];
    printf("Enter end:\n");
    for(i=0; i<accept; i++)
    {
        scanf("%c",&end[i]);
        scanf("%c",&null);
    }


    //for(i=0; i<accept; i++)
    //printf("%c\n",end[i]);
    int t;
    printf("Enter number of test cases:\n");
    scanf("%d",&t);
    while(t--)
    {
        int check=0;
        //printf("Enter input string size:\n");
        //int size;
        // scanf("%d",&size);
        char str[100];
        printf("Enter string:\n");
        scanf("%s",str);

        // str[size]='\0';

        i=0,j=0;
        int k=0;
        char currentState=start;
        char path[state];
        for(i=0;i<strlen(str);i++)
        {
            path[k]=currentState;

            for(j=0; states[j]!=currentState; j++);
            int stateIndex=j;
            for(j=0; symbols[j]!=str[i]; j++);
            int symbolIndex=j;

            currentState=table[stateIndex][symbolIndex];
            //i++;
            k++;
        }
        path[k]=currentState;
        k++;
        path[k]='\0';
        for(i=0; i<accept; i++)
        {
            if(end[i]==currentState)
            {
                check=1;
                printf("Accepted\n");
                printf("Path:\n");
                for(k=0; path[k]!='\0'; k++)
                    printf("%c ",path[k]);
                printf("\n");

                break;
                //return 0;
            }
        }
        if(!check) printf("Not accepted\n");
    }

    //  printf("%s",str);



    /*for(i=0;i<state;i++)
    {
        for(j=0;j<symbol;j++)
        {
            printf("%c ",table[i][j]);
        }
        printf("\n");
    }*/
}
