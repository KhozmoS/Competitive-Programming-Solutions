#include <bits/stdc++.h>

using namespace std;

int main()
{
    float A[105];
    int n;
    cin>>n;
    int ind=1;
    while(ind<=n)
    {
        cin>>A[ind];
        ind ++;
     }
    int m=0;
    int pos=0;
    ind=1;
    while(ind<=n)
    {
    if(A[ind]>=m)
    {
      m=A[ind];
      pos=ind;
    }
    ind ++;


    }
cout<<pos<<endl;


    return 0;
}