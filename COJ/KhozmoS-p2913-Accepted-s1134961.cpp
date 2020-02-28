#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;
bool prime[105];
ll primes[105];
int cp;
void Criba(){
        fill(prime,prime + 101, 1);
        for(int i = 4; i <= 100; i+=2)prime[i] = 0;
        primes[cp++] = 2;
        for(ll i = 3; i <= 100; i+=2){
                if(prime[i]){
                        primes[cp++] = i;
            for(ll h = i*i; h <= 100; h+=2*i){
                prime[h] = 0;
            }
                }
        }
}
struct nodo{
        ll val,cantD;
        int prim[13];
};
map<ll,bool> visited;
ll BFS(ll n){
    nodo x;
    pair<ll,ll> res = make_pair(1,1);
    x.val = 1;
    x.cantD = 1;
    visited[x.val] = 1;
    for(int i = 0; i < 13; i++)x.prim[i] = 0;
    queue<nodo> cola;
    cola.push(x);
    while(!cola.empty()){
        nodo aux = cola.front();
        cola.pop();
        for(int i = 0; i < 13; i++){
                nodo k;
                k.val = aux.val;
            for(int h = 0; h < 13; h++){
                k.prim[h] = aux.prim[h];
            }
            if(!i || k.prim[i] < k.prim[i-1]){
                k.prim[i]++;
                k.val*=primes[i];
                if(k.val <= n){
                k.cantD = 1;
                for(int h = 0; h < 13; h++){
                    k.cantD*=(k.prim[h]+1);
                }

                 if(k.cantD > res.first || (k.cantD == res.first && k.val < res.second)){
                    res.first = k.cantD;
                    res.second = k.val;
                 }
                 if(!visited[k.val]){
                    visited[k.val] = 1;
                    cola.push(k);
                 }
                }
            }
        }
    }
    return res.second;
}
int p[13];
int main()
{
    Criba();
    ll n;
    int t;
    scanf("%d",&t);
    while(t--){
            visited.clear();
        scanf("%lld",&n);

        printf("%lld\n",BFS(n));
    }
    return 0;
}