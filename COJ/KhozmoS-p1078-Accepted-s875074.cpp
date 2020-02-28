#include <bits/stdc++.h>

using namespace std;
   int cas,n,can,sum;
int main()
{
     int n;
       cin>>cas;
        for(int i=0;i<cas;i++){
      cin>>n;
       for(int j=0;j<n;j++){
         cin>>can;
         sum+=can;
       }
        if(sum % n == 0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
         sum=0;
        }

    return 0;
}
