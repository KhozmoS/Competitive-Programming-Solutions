#include <bits/stdc++.h>

using namespace std;


typedef long long ll;


ll p[66];
ll n;

void pot()
{
    p[0] = 1ll;
    for(int i = 1 ; i <= 64 ; i++)
        p[i] = p[i-1] * 2ll;
}

int count_bit(ll x)
{
    int res = 0;
    for(ll i = 0 ; i <= 63 ; i++)
        if(p[i] & x) res++;
    return res;
}

ll fr[70];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    pot();

    cin>>n;

    bool flag = false;
    int cnt = 0;bool wow = false;
    for(ll i = 1 ; i <= 63 ; i++)
    {
        ll N = n*i;

            cnt = count_bit(N);
            memset(fr , 0 , sizeof(fr));
            if(i>=cnt){
                flag = true;
                int cnt = 0;
                for(int j = 0 ; j <= 63 ; j++)
                    if(N&(p[j])){
                        fr[j]++;
                        cnt++;
                    }
                while(cnt<i)
                {
                    for(int j = 1 ; j <= 63 ; j++)
                    {
                        if(fr[j])
                        {
                           // cout<<j<<"\n";
                            fr[j-1] += 2ll;
                            fr[j]--;
                            break;
                        }
                    }
                    cnt++;
                    //cout<<"w\n";
                }

                cout<<cnt<<"\n";
                for(int j = 0 ; j <= 63 ; j++)
                    if(fr[j]){
                        while(fr[j]--)
                            cout<<p[j]<<" ";
                    }
                cout<<"\n";

            }

    if(flag) break;
    }

    if(!flag)
    {
        cout<<"-1\n";
        while(true);
        return 0;
    }
}
