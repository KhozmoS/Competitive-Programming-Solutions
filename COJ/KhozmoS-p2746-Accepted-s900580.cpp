#include<bits/stdc++.h>

using namespace std;
string a;int contf;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>a;
    int ta = a.size();
    for(int i = 0 ; i < ta ; i++)
    {
        if(a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U')
            contf++;
    }
    cout<<contf<<" "<<ta - contf<<"\n";
}
