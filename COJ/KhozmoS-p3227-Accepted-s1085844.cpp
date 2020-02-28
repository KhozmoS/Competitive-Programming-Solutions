#include<bits/stdc++.h>


using namespace std;
const int MAXN = 1000005;
typedef long long ll;

vector <ll> v1;
vector <ll> v2;

ll may = 0;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;
   cin>>t;

   while(t--)
   {
    may = -1;
     int n;
     cin>>n;
    for(int i = 0 ; i < n ; i++)
    {
        ll x;
        cin>>x;
        if(x > may)
        may = x;

        v1.push_back(x);
    }
       bool sigo = 1;
       bool flag = false;
       while(sigo)
       {
        if(!flag)
        sort(v1.begin() , v1.end());
        else
        sort(v2.begin() , v2.end());

        int cont = 0;

        if(!flag)
        {
          for(int i = 0 ; i < (n) ; i++)
          {
            if(v1[i] == v1[i + 1])
            {
                ll x = v1[i] + v1[i + 1];
                v2.push_back(x);
                if(x > may)
                may = x;
                cont++;
                i++;
            }
            else
            v2.push_back(v1[i]);
          }
          if(cont == 0)
          sigo = false;

          flag = true;
          n -= cont;
          cont = 0;
          v1.clear();
        }
        else
        {
          for(int i = 0 ; i < (n) ; i++)
          {
            if(v2[i] == v2[i + 1])
            {
                ll x = v2[i] + v2[i + 1];
                v1.push_back(x);
                if(x > may)
                may = x;
                cont++;
                i++;
            }
            else
            v1.push_back(v2[i]);
          }
          if(cont == 0)
          sigo = false;

          flag = false;
          n -= cont;
          cont = 0;
          v2.clear();
        }
       }
       cout<<may<<"\n";

       v1.clear();
       v2.clear();
   }

  return 0;
}
