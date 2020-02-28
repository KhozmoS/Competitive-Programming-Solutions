#include <bits/stdc++.h>

using namespace std;


#define PB push_back
#define db  double
typedef long long ll;
typedef vector <int> vi;

const db eps = 1e-10;
typedef pair <int , int> p;
const int MAX = 1e6;
int n;
p ar[MAX];


bool ok(db &x)
{
    db mx = -1e18;
    bool flag = false;
    //cout<<mx<<"\n";
    for(int i = 1 ; i <= n ; i++)
    {
        if(ar[i].second < 0)
        {
            if(flag)
            if(((db)ar[i].second)*x+((db)ar[i].first)<mx)
                return true;
        }
        if(ar[i].second > 0){
            mx = max(mx , ((db)ar[i].second)*x+((db)ar[i].first));
            flag = true;
        }
    }
    return false;
}
void f()
{
    db in = 0.0; db fn = 1e10;
    bool flag = false;

    while(in+eps<fn)
    {
        db mt = (in+fn)/2.0;

        if(ok(mt)){
            fn = mt;
            flag = true;
        }
        else in = mt;
    }
    if(!flag)
        cout<<"-1\n";
    else
    cout<<setprecision(7)<<fixed<<fn<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i = 1 ; i <= n ; i++)
        cin>>ar[i].first>>ar[i].second;
    sort(ar+1 , ar+1+n);
    f();
}
