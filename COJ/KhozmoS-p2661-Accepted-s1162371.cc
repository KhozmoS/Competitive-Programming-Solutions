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
bool mk[MAX];

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

int main()
{

  ios_base::sync_with_stdio(0),cin.tie(0);

  string txt;
  while(cin>>txt)
  {
      int res = 0;

      for(int i = 0 ; i < txt.size() ; i++)
        res = (res * 10 + (txt[i]-'0')) % 3;

      if(!res) cout<<1<<"\n";
      else if(res == 1) cout<<7<<"\n";
      else cout<<"4\n";
  }



}
