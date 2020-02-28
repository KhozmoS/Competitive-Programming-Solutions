#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 100005;
const int maxn = (int)sqrt(MAX) + 1;
int B = (int)(sqrt(100000))+1ll , n , q ;
ll ar[MAX] , sum[maxn + 5];

multiset <ll> mk;

vector <ll> SQ[maxn + 5];

char typ;

void update(int a , int b , ll x)
{
    priority_queue <ll> Q;

    int posa = a / B;
    int posb = b / B;
    for(int i = a ; (int)(i / B) == posa && i <= b; i++)
    {
        Q.push(ar[i]);
        ar[i] += x;
    }
    int ta = SQ[posa].size();
    for(int i = ta - 1 ; i >= 0 && !Q.empty() ; i--)
    {
        ll y = SQ[posa][i];
        if(Q.top() == y)
        {
            SQ[posa][i] += x;
            Q.pop();
        }
    }
    while(!Q.empty()) Q.pop();

    sort(SQ[posa].begin() , SQ[posa].end());

    posa++;
    for(int i = posa ; i < posb ; i++)
        sum[i] += x;
    if(posb < posa) return;
    int in = posb * B;
    for(int i = in ; i <= b ; i++)
    {
        Q.push(ar[i]);
        ar[i] += x;
    }
    ta = SQ[posb].size();
    for(int i = ta - 1 ; i >= 0 && !Q.empty(); i--)
    {
        ll y = SQ[posb][i];
        if(Q.top() == y)
        {
            SQ[posb][i] += x;
            Q.pop();
        }
    }
    while(!Q.empty()) Q.pop();

    sort(SQ[posb].begin() , SQ[posb].end());
}
int query(int a , int b)
{
    int res = 0;
    int posa = a / B;
    int posb = b / B;
    ll x = max(ar[a] + sum[posa] , ar[b] + sum[posb]);
   // cout<<a<<" "<<b<<" "<<posa<<" "<<posb<<"\n";

    for(int i = a+1 ; (int)(i / B) == posa && i < b ; i++)
     {
          bool flag = false;
          //cout<<ar[a]<<" "<<ar[i]<<"\n";
          if(ar[a] < ar[i])
          {
              flag = true;
             // cout<<"wa\n";
          }
          if(flag && posa == posb && ar[b] < ar[i])
            res++;
          else if(flag && posa != posb && (ar[b] + sum[posb]) < (ar[i] + sum[posa]))
            res++;
     }

     int posaa = posa + 1;
     for(int i = posaa ; i < posb ; i++)
     {
         int ta = SQ[i].size();
         res += (ta - (upper_bound(SQ[i].begin() , SQ[i].end() , x - sum[i]) - SQ[i].begin()));
     }
     if(posb < posaa) return res;

     int in = posb * B;
     for(int i = in ; i < b ; i++)
     {
         bool flag = false;
         if(ar[b] < ar[i])
            flag = true;
         if(flag && (ar[a] + sum[posa]) < (ar[i] + sum[posb]))
            res++;
     }
     return res;

}

int main()
{
  /* vector <int> A;
   A.push_back(1);
   A.push_back(2);
   A.push_back(3);
   cout<<(upper_bound(A.begin() , A.end() , 2) - A.begin());*/
   ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;


    for(int i = 0 ; i < n ; i++)
    {
        cin>>ar[i];
        SQ[i / B].push_back(ar[i]);
    }
    for(int i = 0 ; i <= maxn ; i++)
        sort(SQ[i].begin() , SQ[i].end());
    while(q--)
    {
        int a , b;
        cin>>typ>>a>>b;
        if(a > b) swap(a , b);
        a--;b--;
        if(!(typ - 'U'))
        {
            ll x; cin>>x;
            update(a , b , x);
            continue;
        }
        cout<<query(a , b)<<"\n";
    }

}
