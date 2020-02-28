#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

struct node {

    int cnt;
    int next[30];

    node(){
       cnt = 0;
       memset(next , 0 , sizeof(0));
    }

}Trie[MAX];

string cad;

int sz , ans;
void F(int node , int pos)
{

    if(pos == cad.size())
        return;

    int nxt = Trie[node].next[cad[pos]-'a'];
    if(!nxt){nxt = sz; Trie[node].next[cad[pos]-'a'] = sz;sz++;}
    Trie[nxt].cnt++;
    F(nxt , pos+1);
}
void solve(int node)
{
     for(int i = 0 ; i <= 25 ; i++)
     {
         int nxt = Trie[node].next[i];
         if(!Trie[nxt].cnt) continue;

         ans += (Trie[node].cnt != Trie[nxt].cnt ? Trie[nxt].cnt : 0);

         solve(nxt);
     }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;

    while(cin>>n)
    {
        ans = 0;
        sz = 1;
        for(int i = 1 ; i <= n; i++)
        {
            cin>>cad;
            F(0 , 0);
        }
        Trie[0].cnt = 0;
        solve(0);
        cout<<setprecision(2)<<fixed<<(1.0*ans / (1.0 * n))<<"\n";
        for(int i = 0 ; i < sz ; i++)
        {
            Trie[i].cnt = 0;
            memset(Trie[i].next , 0 , sizeof(Trie[i].next));
        }
    }
}
