#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 5;
int go[MAX];
int ar[MAX];
bool mk[MAX];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n , m , start;
    cin>>n>>m>>start;

    for(int i = 1 ; i <= n ; i++)
    {
        int a , b;
        cin>>a>>b;
        ar[i] = a;
        if(!go[b])
            go[b] = i;



    }
    int ans = 0;
    //cout<<go[2]<<"\n";
    //cout<<go[1]<<"\n";
    while(go[start])
    {
      //  cout<<start<<"\n";
        //cout<<"wa\n";
        if(mk[start]) {ans = -1 ; break;}
        mk[start] = true;
        start = ar[go[start]];
        ans++;

    }
    cout<<ans<<"\n";
    return 0;
}
