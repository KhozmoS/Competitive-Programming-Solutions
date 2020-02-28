#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define PB push_back
#define db double

map <string , bool> mp;

typedef pair <int , string> par;
vector < par > v;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        bool flag = false;
        int n;cin>>n;

        v.clear();
        int N = n;
        while(n--)
        {
            string cad;cin>>cad;
            v.PB(par(cad.size() , cad));
        }
        sort(v.begin() , v.end());
        reverse(v.begin() , v.end());
        for(int i = 0 ; i < N ; i++)
        {

            string cad = v[i].s;
           // cout<<cad<<"\n";
            if(mp.find(cad) != mp.end())
               flag = true;
            string pre = "";
            for(int j = 0 ; j < v[i].f ; j++)
            {
                pre += v[i].s[j];
                mp[pre] = true;
            }
            //out<<pre<<"\n";
        }
        if(flag)
            cout<<"NO\n";
        else cout<<"YES\n";
        mp.clear();
    }
}
