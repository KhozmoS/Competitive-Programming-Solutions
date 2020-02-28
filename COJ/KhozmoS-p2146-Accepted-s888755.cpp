#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

  LL D,V;
int main ()
{
    cin>>D>>V;
     if(V == 3 && D == 3)
        cout<<"yes"<<endl;
     else if((V * (V - 3)) / 2 == D)
        cout<<"yes"<<endl;
     else
        cout<<"no"<<endl;

    return 0;
}
