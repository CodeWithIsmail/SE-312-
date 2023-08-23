#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    freopen("lis.txt","r",stdin);
    int n;
    cin>>n;
    int a[n+1]={0};
    for(i=1;i<=n;i++)
    {
       cin>>a[i];
    }



  // for(i=0;i<=n;i++)
  // cout<<a[i]<<" ";

    int LP[n+1],previous[n+1];
    vector<int>L;
    int temp=INT_MIN;
    L.push_back(temp);

    LP[0]=previous[0]=-1;

    for(i=1;i<=n;i++)
    {
      if(L[L.size()-1]<a[i])
      {
         L.push_back(a[i]);
         LP[L.size()]=i;
         previous[i]=LP[L.size()-1];
      }
      else
      {
          int s=0,h=L.size();
          while(s<h)
          {
              int m=(s+h)/2;
              if(L[m]<a[i])
                 s=m+1;
              else h=m;
          }

          L[s]=a[i];
          LP[s]=i;
          previous[i]=LP[s-1];
      }



      for(int i=0;i<=n;i++)
      {
         cout<<L[i]<<" ";
      }
      cout<<endl;
       for(int i=0;i<=n;i++)
      {
         cout<<previous[i]<<" ";
      }

    }

}
