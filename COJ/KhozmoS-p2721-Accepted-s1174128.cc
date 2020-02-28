#include<bits/stdc++.h>


using namespace std;
#define PB push_back
const int mod = 10007;
typedef unsigned long long ll;
typedef vector <ll> vi;
const int MAX = 1e2 + 5;
int n;
int ar[MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n; for(int i = 0 ; i < n ; i++) cin>>ar[i];
    sort(ar , ar + n);
    while(ar[n-1] != ar[0])
    {
        ar[n-1] = ar[n-1] - ar[0];
        sort(ar , ar + n);
    }
    for(int i = 1 ; i < n ; i++) ar[i] += ar[i-1];
    cout<<ar[n-1]<<"\n";
}
