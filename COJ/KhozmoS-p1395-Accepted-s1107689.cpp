#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000007;

map <int , int> m;
typedef pair <int , int> par;


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin>>t;
    par ar[t + 5];
    double ans[t + 5];
    int may = -1;
    for(int i = 0 ; i < t ; i++){
        int x;
        cin>>x;
        if(x == 1){
            ans[i] = --x;
            continue;
        }
        ar[i].first = x;
        if(m.find(x) != m.end())
        {
            ar[i].second = m[x];
            continue;
        }

        m[x] = i;
        may = max(may , x);
        ar[i].second = m[x];
    }

    double ant = 0.0;
    for(int i = 2; i <= may; i++){
        int pos;
        if(m.find(i) != m.end())
        {
        pos = m[i];
        ans[pos] = log10(i) + ant;
        }
        ant = log10(i) + ant;
    }
    for(int i = 0; i < t ; i++)
        cout<<((int)ans[ar[i].second]) + 1<<"\n";

   return 0;
}
