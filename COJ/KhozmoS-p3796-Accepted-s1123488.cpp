#include <bits/stdc++.h>

using namespace std;

string n , m;
long long pot[70];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
     pot[0] = 1;
     for(int i = 1 ; i < 64 ; i++)
        pot[i] = pot[i - 1] * 2;

     int t;

     cin>>t;

     while(t--)
     {
       long long a , b;int pos;
       cin>>a>>b>>pos;

       a = log2(a);
       b = log2(b);

       n = "1";
       m = "1";

       while(a--) n += '0';
       while(b--) m += '0';

       while(n.size() < 32)
            n = '0' + n;


       reverse(n.begin() , n.end());
       reverse(m.begin() , m.end());

       int tn = n.size();
       int j = 0;

       for(int i = pos ; j < m.size() ; j++ , i++)
       {
           if(i >= tn)
              n += m[j];
           else
              n[i] = m[j];
       }


       long long ans = 0;
       for(int i = 0 ; i < n.size() ; i++)
          if(n[i] == '1')
          ans += pot[i];

       cout<<ans<<"\n";
     }

    return 0;
}
