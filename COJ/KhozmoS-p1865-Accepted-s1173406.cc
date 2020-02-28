#include <bits/stdc++.h>

using namespace std;

map <string , int> mk;

int main()
{

    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string cad;
        cin>>cad;
        for(int i = 0 ; i < cad.size() ; i++){
            string ins = "";
            for(int j = i ; j < cad.size() ; j++){
                 ins += cad[j];
                 mk[ins]++;
            }
        }
    }
    int n;
    cin>>n;
    while(n--)
    {
        string cad;cin>>cad;

        cout<<mk[cad]<<"\n";
    }
}
