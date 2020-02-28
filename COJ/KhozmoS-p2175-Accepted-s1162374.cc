//KhozmoS

#include<bits/stdc++.h>


using namespace std;

#define PB push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int , int> II;
typedef vector <int> VI;
typedef vector <II> VII;

const int MAX = 1005;

int n, m , p[MAX] ;
VI adl[MAX] , white;


ll exp(ll a , ll b)
{
    ll res = 1;

    while(b)
    {
        if(b&1)
            res = (res * a) % 9;

        a = (a * a) % 9;
        b >>= 1;
    }
    return res;
}
const int maxn = 1e6 + 5;
bool mk[maxn];

int main()
{

  ios_base::sync_with_stdio(0),cin.tie(0);
  for(int i = 4 ; i <= 1e6 ; i += 2) mk[i] = true;

  for(int i = 3 ; i * i <= 1e6 ; i += 2)
    if(!mk[i])
      for(int j = i * i ; j <= 1e6 ; j += i) mk[j] = true;
  int t;cin>>t;
  while(t--)
  {
      int x;cin>>x;

      int a = x;
      int b = x;

      while(mk[a])a--;
      while(mk[b])b++;

      cout<<a<<" "<<b<<"\n";
  }



}
