#include<stdio.h>
#include<time.h>

char str[5][15];

int length(char a[])
{
    int i;
    for(i=0; a[i]; i++);
    return i;
}

int check(char a[])
{
    int i;
    for(i=0; a[i]; i++)
    {
        if(a[i]!='0' && a[i]!='1') return 0;
    }
    return 1;
}

void display()
{
    for(int i=0; i<5; i++)
    {
        printf("%s => Length: %d\n",str[i],length(str[i]));
    }
}
void concate()
{

    printf("Enter two string:\n");
    char str1[15],str2[15];
    scanf("%s %s",str1,str2);
    int s1=length(str1),s2=length(str2),s3=s1+s2,i,j;
    char s[s3+1];

    for(i=0; i<s1; i++)
        s[i]=str1[i];
    for(; i<s3; i++)
        s[i]=str2[i-s1];
    s[s3]='\0';
    printf("%s\n",s);
}
int main()
{
    int i,j;

    srand("NULL");
    for(i=0; i<5; i++)
    {
        int size=rand()%10+1;
        for(j=0; j<size; j++)
        {
            str[i][j]=rand()%2+'0';
        }
    }

    display();

    printf("Enter string:\n");
    char strCheck[15];
    scanf("%s",strCheck);

    check(strCheck)? printf("Accepted"):printf("Not Accepted");
    printf("\n");

    concate();
}
