#include<bits/stdc++.h>


using namespace std;
#define PB push_back
const int mod = 10007;
typedef unsigned long long ll;
typedef vector <ll> vi;
const int MAX = 1e6 + 5;
ll AC[MAX];
int ans[MAX];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i = 1 ; i < MAX ; i++){
        AC[i] = AC[i-1] + (ll)i+1;
        int j = i-1;
        while(j >= 0 && AC[i] - AC[j] < MAX)
        {
            ans[AC[i]-AC[j]]++;
            j--;
        }
    }
    int n;
    while(cin>>n && n) cout<<ans[n]<<"\n";

}
