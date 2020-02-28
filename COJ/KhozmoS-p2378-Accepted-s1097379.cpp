#include <bits/stdc++.h>

using namespace std;


const int MAX = 1e6 + 5;
map <int , short> mk;
//map <int , int> freq;

int fit , n ;
int ar[MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>fit){
    fit *= 1e7;
    cin>>n;
    for(int i = 0 ; i < n ; i++) cin>>ar[i] , mk[ar[i]]++;

    sort(ar , ar + n);
    bool flag = false;
    int a , b;
    for(int i = 0 ; i < n && !flag; i++)
    {
      if(ar[i] == fit - ar[i] && mk[ar[i]] > 1)
      {
        a = ar[i];
        b = ar[i];
        flag = 1;
      }
      if(ar[i] != fit - ar[i] && mk[fit - ar[i]])
      {
        a = ar[i];
        b = fit - ar[i];
        flag = 1;
      }
    }
    if(flag) cout<<"yes "<<a<<" "<<b<<"\n";
    else cout<<"danger\n";
    mk.clear();
}
    return 0;
}
