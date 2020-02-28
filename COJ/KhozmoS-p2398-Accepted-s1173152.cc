#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;

char v[20]; int sz , n;
map <string , bool> mk;
void F(int idx , string cad , int cntv , int cntc)
{
    if(idx == n)
    {
        if(cad.size() == sz && cntv >= 1 && cntc >= 2 && mk.find(cad) == mk.end())
            cout<<cad<<"\n";
        mk[cad] = true;
        return;
    }
    bool is = (v[idx] == 'a' || v[idx] == 'e' || v[idx] == 'u' || v[idx] == 'o' || v[idx] == 'i');
    F(idx+1 , cad + v[idx] , cntv + is , cntc + !is);
    F(idx+1 , cad , cntv , cntc);
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   int t;
   cin>>t;
   while(t--)
   {
       cin>>sz>>n;
       for(int i = 0 ; i < n ; i++)
           cin>>v[i];
       sort(v , v + n);
       F(0 , "" , 0 , 0);
       mk.clear();
       if(t)
            cout<<"\n";
   }
}
