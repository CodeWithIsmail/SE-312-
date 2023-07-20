#include<stdio.h>
int power(int n)
{
    int i,ans=2;
    for(i=1; i<n; i++) ans*=2;
    return ans;
}
void deciToBin(int n)
{
    printf("NUmber of string= %d\n",power(n));
    for(int j=0; j<power(n); j++)
    {
        int a[n],i,m=j;
        for(i=0; i<n; i++) a[i]=0;

        while(m)
        {
            i--;
            a[i]=m%2;
            m/=2;
        }

        for(i=0; i<n; i++)
            printf("%d",a[i]);
        printf("\n");
    }
}
int length(char a[])
{
    int i;
    for(i=0; a[i]; i++);
    return i;
}
int palindromeCheck(char str[])
{
    int i,j,s=length(str);
    char str2[s];
    for(i=0;i<s;i++)
    {
       str2[i]=str[s-1-i];
    }

    for(i=0;i<s;i++)
    {
        if(str[i]!=str2[i]) return 0;
    }
    return 1;
}
int main()
{
    int n;
    printf("Enter n:\n");
    scanf("%d",&n);
    deciToBin(n);

    printf("Enter string:\n");
    char check[15];
    scanf("%s",check);
    palindromeCheck(check)? printf("Palindrome"):printf("Not Palindrome");
}
