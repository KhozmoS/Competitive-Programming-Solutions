#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define db double
#define all(c) (c).begin(),(c).end()
#define sz(c) (c).size()

typedef long long ll;
typedef pair <ll , ll> ii;
typedef pair <ii , int> iii;
typedef vector <int >vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const int MAX = 1e6+5;

ll ar[MAX];
int n;
ll even = 0;
ll odd = 0;
ll wood[3];


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i = 1 ; i <= n ; i++){    
        cin>>ar[i];        
        if(i&1) odd+=ar[i];
        else even+=ar[i];
    }
    if(n&1)
    {
        cout<<odd<<" "<<even<<"\n";
        return 0;
    }
    even = 0;
    odd = 0;
    for(int i = n/2 ; i >= 1 ; i--)
    {
        int lft = i;
        int rgt = n-i+1;
        wood[i&1] += ar[lft]+ar[rgt];
        if(i&1)
        {
            odd += ar[lft];
            even += ar[rgt];
        }
        else{
            even += ar[lft];
            odd += ar[rgt];
        }
        wood[(i&1)] = max(max(odd,even) , wood[(i&1)]);
        wood[(i&1)^1] = min(min(odd,even) , wood[(i&1)^1]);
    }
    cout<<wood[1]<<" "<<wood[0]<<"\n";
    return 0;
}
