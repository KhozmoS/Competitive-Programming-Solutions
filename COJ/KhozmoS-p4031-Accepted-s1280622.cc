#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {

        string cad;
        cin>>cad;
        if(cad.size()&1)
        {
            cout<<"no\n";
            continue;
        }
        bool ok = false;
        for(int i = 0 ; i < cad.size()/2 ; i++)
        {
            ok |= (cad[i]==cad[cad.size()-i-1]);
        }
        cout<<(ok?"no\n":"yes\n");
    }


}
