#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 5;
#define PB push_back
vector <int> adl[MAX];
int n , m;
void AE(int a , int b)
{
    adl[a].PB(b);
    adl[b].PB(a);
}

bool mmk[MAX];

int diameter(int node)
{
    bool mk[MAX];

    queue <int> Q;
    Q.push(node);
    mk[node] = true;

    while(!Q.empty())
    {
        node = Q.front();Q.pop();


        for(auto x : adl[node]){

           if(mk[x]) continue;

           Q.push(x);
           mk[x] = true;
        }
    }

    int d[MAX];
    d[node] = 0;
    mk[node] = false;
    mmk[node] = true;
    Q.push(node);
    while(!Q.empty())
    {
        node = Q.front();Q.pop();


        for(auto x : adl[node]){

           if(!mk[x]) continue;
           d[x] = d[node] + 1;
           Q.push(x);
           mk[x] = false;
           mmk[x] = true;
        }
    }
    return d[node];
}


int main()
{
	cin.tie(0), ios_base::sync_with_stdio(0);

    cin>>n>>m;
    for(int i = 0 ; i < m ; i++)
    {
        int a , b;cin>>a>>b;

        AE(a , b);
    }
    vector <int> D;

    for(int i = 0 ; i < n ; i++)
        if(!mmk[i])
          D.PB(diameter(i));
	sort(D.begin() , D.end() , [&](const int &a , const int &b){return a > b;});
    int ans = D[0];
    for(int i = 1 ; i < D.size() ; i++)
    {
       int a = (D[0]&1 ? D[0]/2+1 : D[0]/2);
       int b = (D[i]&1 ? D[i]/2+1 : D[i]/2);
       ans = max(ans , a+b+1);
       if(i != 1){
          a = (D[i-1]&1 ? D[i-1]/2+1 : D[i-1]/2);
          b = (D[i]&1 ? D[i]/2+1 : D[i]/2);
          ans = max(ans , a + b + 2);
       }
    }

    cout<<ans<<"\n";
}
