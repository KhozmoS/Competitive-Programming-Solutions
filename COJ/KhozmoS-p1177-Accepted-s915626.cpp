#include <bits/stdc++.h>

using namespace std;
int n;
string cad , sol , s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(true)
    {
        cin>>n;
        if(n == 0)
        break;
        cin>>cad;
        if(n == 0)
        break;
        int ta = cad.size();
        int c = ta / n;
        int i = 0;
        while(i < ta)
        {
          for(int j = i ; j < i + c ; j++)
           sol += cad[j];
           reverse(sol.begin(),sol.end());
           s += sol;
           //cout<<sol<<"\n";
           sol = "";
           i += c;
        }
        cout<<s<<"\n";
        sol = "";s = "";

    }
    return 0;
}
