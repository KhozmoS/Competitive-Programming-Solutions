#include <bits/stdc++.h>

using namespace std;

int main()
{
 double A[1001];
 int ind=1;
 int n;
 cin>>n;
    while(ind<=n){
    cin>>A[ind];
    ind++;}
     int l=0 ;double m=0;
    for(ind=1;ind<=n;ind++)
     {if(A[ind]>=m){
     m=A[ind];
      l=ind;

     }


     }
      cout<<l;
        return 0;

}