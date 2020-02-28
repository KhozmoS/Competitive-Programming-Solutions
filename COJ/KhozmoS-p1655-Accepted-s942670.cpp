#include <bits/stdc++.h>


using namespace std;

string cad , comp;
//int dp[MAXN];
int main()
{
   //ios_base::sync_with_stdio(0);cin.tie(0);

     while(cin>>cad>>comp)
     {
        int ver = cad.size();
        int ta = comp.size();

        int pos = 0;
        for(int i = 0 ; i < ta ; i++)
        {
            if(comp[i] == cad[pos])
            {
                pos++;
            }
        }
        if(pos == ver)
        cout<<"Yes\n";
        else cout<<"No\n";
     }
    return 0;
}
