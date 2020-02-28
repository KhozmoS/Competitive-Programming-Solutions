#include<bits/stdc++.h>

using namespace std;
string num;
char zero = '0';
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
    cin>>num;
    int za = num.size();
    for(int i = 0 ; i < za ; i++)
    {
        num += zero;
    }
    cout<<num<<"\n";
    }
    return 0;
}
