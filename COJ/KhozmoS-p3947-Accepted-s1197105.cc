#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define PB push_back

typedef long long ll;
typedef vector <int> vi;

ll X;
int num[14] , n;
vi pr;

void ans()
{
    ll sol = 0;

    for(int mask = 1 ; mask < (1<<n) ; mask++)
    {
        int cnt = 0;
        ll pro = 1;
        ll g = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if((mask & (1 << i)))
            {
               cnt++;
               if(!g)
               {
                   g = num[i];
                   pro = num[i];
                   continue;
               }
               g = __gcd((ll)num[i] , pro);

               pro *= num[i];
               pro /= g;

            }
        }
       // cout<<pro<<" "<<cnt<<"\n";
        if(cnt&1)
            sol += (ll)(X/pro);
        else
            sol -= (ll)(X/pro);
    }
    cout<<sol<<"\n";
}
bool mk[110];
int main()
{

    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>X>>n;bool ok = false;
    for(int i = 0 ; i < n ; i++){
        cin>>num[i];
    }
    if(ok) {cout<<X<<"\n";}
    ans();
}
