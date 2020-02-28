#include<bits/stdc++.h>


using namespace std;
#define PB push_back
const int mod = 10007;
typedef unsigned long long ll;
typedef vector <ll> vi;
const int MAX = 1e3 + 5;
int n , k;
bool mk[MAX];
int prime[MAX];
int ok[MAX];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int p = 0;
    for(int i = 2; i < MAX ; i++)
        if(!mk[i]){
            prime[p++] = i;
            if(p > 1)
                ok[prime[p-1] + prime[p-2] + 1] = 1;
            for(int j = i * i ; j < MAX ; j += i)
                mk[j] = true;
        }

    for(int i = 5 ; i < MAX ; i++){
        if(!mk[i] && ok[i])
            ok[i] += ok[i-1];
        else ok[i] = ok[i-1];
    }
    cin>>n>>k;

    if(ok[n] >= k)
        cout<<"YES\n";
    else cout<<"NO\n";
}
