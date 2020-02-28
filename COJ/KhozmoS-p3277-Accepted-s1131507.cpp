#include<bits/stdc++.h>

using namespace std;
vector <int> v;
int x , dist , n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    int t = n;
    while(n--)
    {
       cin>>x;
       v.push_back(x);
    }
    sort(v.begin() , v.end());
    int ta = v.size();
     if(t == 1)
     dist = 0;
     else
     {
         dist = v[1] - v[0];
     }
     bool flag = false;
     for(int i = 0  ; i < ta - 1 ; i++)
     {
         if(v[i] + dist != v[i + 1])
         {
             flag = true;
             break;
         }
     }
     if(!flag)
     cout<<"YES\n";
     else
     cout<<"NO\n";
    return 0;
}
