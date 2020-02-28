#include <bits/stdc++.h>

using namespace std;
vector<int>v;
int n , x;
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
     for(int i = 0 ; i < n ; i++)
     {
       cin>>x;
       v.push_back(x);
     }
      sort(v.begin(),v.end());
       for(int i = 0 ; i < n ; i++)
         cout<<v[i]<<"\n";
    return 0;
}
