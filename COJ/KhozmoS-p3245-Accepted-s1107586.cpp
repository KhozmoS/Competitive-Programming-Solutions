#include <bits/stdc++.h>


using namespace std;
const int MAX = 1e3 + 5;
typedef long long ll;


vector <int> pri;
bool mk[105];


void criba()
{
  for(int i = 2 ; i * i <= 105 ; i++)
     if(!mk[i]){ pri.push_back(i);
     for(int j = i * i ; j < 105 ; j += i)
        mk[j] = true;
     }
}
ll ans[105];
ll men;
int pos;
bool comp(ll a , ll b)
{
    return a > b;
}
void ver()
{
   ll num = 1;
   ll cop[105];
   for(int i = 0 ; i < pos ; i++)
       cop[i] = ans[i];
   sort(cop , cop + pos , comp);

   for(int i = 0 ; i < pos ; i++)
   {
       cop[i]--;
       ll v = 1;
       while(cop[i]--)
           v *= pri[i];

       num *= v;
       if(num < 0) return;
   }
   if(!men) men = num;

   men = min(men , num);
}
void back(ll x)
{
    if(x == 1){
        ver();
        return;
    }
    for(ll i = 2 ; i <= x ; i++)
    {
        if(x % i == 0)
        {
            ans[pos++] = i;

            back(x / i);
            pos--;
        }
    }
}
int main()
{
    criba();
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        men = 1;
        pos = 0;
        ll n;
        cin>>n;
        ll ans1 = 111111111111111111ll;
        for(n = n ; n <= 200 ; n++){
        ll c = n - 1;
        while(c--)
            men *= 2ll;
        if(men < 0) men = 111111111111111111ll;
        back(n);
        if(men > 1)
        ans1 = min(ans1 , men);
        }
        cout<<ans1<<"\n";
    }

    return 0;
}
