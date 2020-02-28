#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <double , double > ii;
int n;
double x1 , x2 , k , b;

vector <ii> in;
vector <ii> fn;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;

    cin>>x1>>x2;
    x1+=000000000000000.1;
    x2-=000000000000000.1;
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>k>>b;
        in.push_back(ii(k*x1+b,i));
        fn.push_back(ii(k*x2+b,i));
    }
    sort(in.begin(),in.end());
    sort(fn.begin(),fn.end());

    for(int i = 0 ; i < n ; i++)
    {
        if(in[i].second != fn[i].second)
        {
            cout<<"YES\n";
            return 0;
        }
        //cout<<in[i].second<<" ";
        //cout<<fn[i].second<<"\n";
    }
   // cout<<in[0].first<<" "<<fn[0].first<<"\n";
    //cout<<in[1].first<<" "<<fn[1].first<<"\n";
    cout<<"NO\n";
}
