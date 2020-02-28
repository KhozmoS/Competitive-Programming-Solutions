#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 1e6+5;
#define PB push_back
bool ok[MAX];
string code[] = {"" , "" , "ABC" , "DEF" , "GHI" , "JKL" , "MNO" , "PQRS" , "TUV" , "WXYZ"};

struct node{
    char val;
    int child[30];
    node(char x)
    {
        val = x;
        memset(child , 0 , sizeof(child));
    }
    node()
    {
        memset(child , 0 , sizeof(child));
    }
};

vector < node > trie;

string num;
bool finish = false;

int cnt()
{
    int res = 0;
    for(int i =0 ; i < num.size() ; i++)
        res += (num[i]=='1');
    return res;
}
bool dfs(int node , string cur, int pos)
{
    if(finish) return true;
   // cout<<node<<"\n";

    //if(node>=trie.size()) return false;

    if(ok[node] && cur.size()==(num.size()-cnt()))
    {
        cout<<cur<<"\n";
        finish = true;
        return finish;
    }

    if(pos==num.size()){
       return false;
    }
    bool res = false;
    int idx = 0;
    idx = num[pos]-48;

    //cout<<idx<<"\n";

    for(int i = 0 ; i<code[idx].size() ; i++)
    {
        char x = code[idx][i];

        if(trie[node].child[x-'A'])
            res |= dfs(trie[node].child[x-'A'] , cur+x , pos+1);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    trie.PB(node('*'));
    int n;cin>>n;
    //build trie
    while(n--)
    {
        string cad;
        cin>>cad;
        int idx = 0;
        for(int i = 0 ; i < cad.size() ; i++)
        {
            //cout<<trie[idx].child[cad[i]-'A']<<"\n";

            if(!(trie[idx].child[cad[i]-'A']))
            {
                trie[idx].child[cad[i]-'A'] = trie.size();
                trie.PB(node(cad[i]));
            }
            idx = trie[idx].child[cad[i]-'A'];
            if(i==cad.size()-1)
                ok[idx] = true;
        }
    }
    //cout<<trie.size()<<"\n";
    int m;cin>>m;
    while(m--)
    {
        cin>>num;
        finish = false;
        if(cnt() || !dfs(0 , "" , 0))
            cout<<"no solution\n";

    }
}
