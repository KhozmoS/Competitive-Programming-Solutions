#include <bits/stdc++.h>

using namespace std;
int a;int c;int d;
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>a;
    string b;
    cin>>b;
    for(int i=0;i<a;i++){
        if(isupper(b[i]))
           c++;
           else
            d++;
    }
    cout<<c<<" "<<d;

    return 0;
}
