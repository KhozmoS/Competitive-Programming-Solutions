#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    string N;
    cin>>t;
      for(int i=0;i<t;++i)
      {
       cin>>N;
       int ta=N.size();
       if(N[ta-1]=='5'||N[ta-1]=='0')
       cout<<"YES"<<endl;
       else
       cout<<"NO"<<endl;
      }

    return 0;
}