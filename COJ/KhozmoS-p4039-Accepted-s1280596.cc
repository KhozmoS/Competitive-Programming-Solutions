#include<bits/stdc++.h>


using namespace std;

const int MAX = 1e3+5;
#define PB push_back
vector <int> p;
bool mk[MAX];


int ans[1000005];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //CRIBA DE ERASTOTENES
    for(int i = 4 ; i < MAX ; i += 2) mk[i] = true;
    for(int i = 3 ; i * i < MAX ; i += 2)
    {
        if(!mk[i])
            for(int j = i*i ; j < MAX ; j += i)
                mk[j] = true;
    }
    for(int i = 2 ; i < MAX ; i++)
        if(!mk[i]) p.PB(i);
    for(int i = 1 ; i <= 1000000 ; i++)
    {
        int n = i;
        ans[n] = 1;
        for(int j = 0; p[j]*p[j]<=n && j < p.size() ; j++)
        {
            int e = 0;
            if(n%p[j]==0)
            {
                while(n%p[j]==0)
                {
                    e++;
                    n/=p[j];
                }
                ans[i] *= (e+1);
            }
        }
       // ans[i]--;
       // ans[i] -= (i%2==0);

        if(n-1)
            ans[i] *= 2;

    }

    int t;cin>>t;
    for(int i = 1 ; t-- ; i++)
    {
        int n;cin>>n;
        cout<<"Case #"<<i<<": "<<n-ans[n]-(n&1)<<"\n";
    }
}
