#include <bits/stdc++.h>

using namespace std;
  const int MAX=1e6+3;
  int TA[MAX];
bool is_prime(int n)
{
    if(n==0||n==1)
        return false;
    if(n==2)
        return true;
    if(n%2==0)
        return false;
    for(int i=3;i * i <= n;i+=2)
      if(n%i==0)
      return false;

    return true;
}

int main()
{
    int cont=0;
    TA[1]=0;
   for(int i=2;i<=MAX;++i)
   {
     if(is_prime(i)==true)
        TA[i]=TA[i-1]+1;
     else
        TA[i]=TA[i-1];
    }
    int x,y;
    while(true)
        {
        cin>>x>>y;
        if(x==0&&y==0)
            break;
        cout<<TA[y]-TA[x-1]<<endl;
        }


    return 0;
}
