#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX = 1e5 + 5;

vector <ll> prime;

bool mk[MAX];

void criba()
{
  prime.push_back(2);
  for(int i = 4 ; i < MAX ; i += 2)
     mk[i] = true;

  for(int i = 3 ; i * i <= MAX ; i += 2)
   if(!mk[i])

   for(int j = i * i ; j < MAX ; j += 2 * i)
    mk[j] = true;

  for(ll i = 3 ; i < MAX ; i += 2)
    if(!mk[i])
      prime.push_back(i);
 }

 int ta ,a;
int e , p , n;

void solve(int x) {
    for(int i = 0; i < p && prime[i] * prime[i] <= x; i++) {
        int aux = 0;
        while(x % prime[i] == 0) {
            x /= prime[i];
            aux++;
        }
        e ^= aux;
    }

    if(x != 1)e ^= 1;
}
int main()
{

 ios_base::sync_with_stdio(0);cin.tie(0);
  criba();
  p = prime.size();
  //ta = prime.size();
 int t;
  cin>>t;
    while(t--) {
        cin >> n;
        e = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a;
            solve(a);
        }
        if(e != 0) {
            cout << "Poo\n";
        } else {
            cout << "Mak\n";
        }
    }
 return 0;
}
