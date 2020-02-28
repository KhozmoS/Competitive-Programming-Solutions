#include <bits/stdc++.h>


using namespace std;

const int MAX = 1e6 + 5;
string cad;

int pos;
int ans[1001] , n;

void out()
{
    sort(ans + 1 , ans + pos + 1);
    cout<<n<<" = ";
    for(int i = 1 ; i <= pos ; i++) cout<<ans[i]<<(i == pos ? "\n" : " + ");
}
void F(int x)
{
    if(!x) {out();return;}

    for(int i = 1 ; i <= x ; i++)
    {
        if(i < ans[pos]) continue;
        ans[++pos] = i;
        F(x - i);
        pos--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;

    while(t--){
    cin>>n,
    F(n);
    if(t)cout<<"\n";
    }

}
