#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define PB push_back
#define db double
const int MAX = 1e6+5;

typedef long long ll;
typedef pair <int , int> par;
typedef pair <par , int> trio;

multiset <par> S;
vector <int> ar[2];

int p[MAX];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++)
    {
        int x;cin>>x;
        p[x] = i;
        S.insert(par(x,i));
    }
    int cur = 0;
    int last = 0;
    while(S.size())
    {
        par nw;
        int e;
        while(S.size())
        {
            nw = *S.begin();
            if(nw.s<last){
                break;
            }

            e = nw.f;
            last = nw.s;
            ar[cur&1].PB(e);
            S.erase(nw);
        }
        last = 0;
        cur++;
        }
    if(ar[0].size())
    for(int i = 0 ; i < ar[0].size() ; i++)
        cout<<ar[0][i]<<(i==(ar[0].size()-1)?"\n":" ");
    if(ar[1].size())
    for(int i = 0 ; i < ar[1].size() ; i++)
        cout<<ar[1][i]<<(i==(ar[1].size()-1)?"\n":" ");
    else cout<<" \n";

    if(ar[0].size()==ar[1].size())
        cout<<"E\n";
    else if(ar[0].size()>ar[1].size())
        cout<<"A\n";
    else cout<<"B\n";
}
