#include<bits/stdc++.h>

using namespace std;
 int n;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(true){
        cin>>n;
        if(n == 0)
            break;
         else if(n == 1)
           cout<< 0 <<"\n";
         else if(n == 2)
            cout<< 0 <<"\n";
         else
        cout<<(6 * ((n - 2) * 4)) / 2<<"\n";
         }
    return 0;
}
