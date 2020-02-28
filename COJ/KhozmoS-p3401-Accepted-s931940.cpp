#include<bits/stdc++.h>

using namespace std;

string cad , s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>cad;
    cin>>s;
    /*sadffaas
    a
    */
    int tcad = cad.size();
    int ts = s.size();
    int i = 0;int sol = 0;
    //cout<<cad.substr(5 , 1)<<"\n";
    while(i + ts - 1 < tcad)
    {
        if(s == cad.substr(i ,  ts)){
        sol++;
        i += ts;
        continue;
        }
       // cout<<i<<" ";
        i++;
    }
    //cout<<"\n";
    //cout<<cad.substr(5 , 6)<<"\n";
    cout<<sol<<"\n";
    return 0;
}
