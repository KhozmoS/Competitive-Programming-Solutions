#include <bits/stdc++.h>

using namespace std;
const int MAX = 1005;
set <string> S;
int ans;
string ar[MAX]; int n , m;
string arr[MAX];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i = 0 ; i < n ; i++) cin>>ar[i];
    for(int i = 0 ; i < m ; i++) cin>>arr[i];

    for(int i = 0 ; i < n ; i++){
         string ma = "";
        for(int j = 0 ; j < m ; j++){
           string ins = "";
           for(int k = 0 ; k < min(ar[i].size() , arr[j].size()) ; k++)
               if(ar[i][k] == arr[j][k])
                {
                  ins += ar[i][k];
                }
                else
                {
                    ins += ar[i][k];
                    break;
                }
           if(ma.size() < ins.size()) ma = ins;
        }
        S.insert(ma);
    }
    for(set <string> :: iterator it = S.begin() ; it != S.end() ; it++)
    {
        ans += (*it).size();
        //cout<<*it<<"\n";
    }
    cout<<ans<<"\n";
}
