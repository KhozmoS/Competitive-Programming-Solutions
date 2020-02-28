#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
const int MAX = 1e6 + 5;
set <string> A;
int main()
{
    string cad;cin>>cad;
    for(int i = 0 ; i < cad.size() ; i++){
        string m = "";
        for(int j = i ; j < cad.size() ; j++)
        {
             m += cad[j];
             A.insert(m);
        }
    }
    cout<<A.size()<<"\n";
}
