#include <bits/stdc++.h>

using namespace std;

string a , b  , cad;
int sum , A , B;
char alp[30];
void crear()
{
    for(int i = 1 ; i <= 26 ; i++)
        alp[i] = char((i - 1) + 'A');
}
int main()
{
    crear();
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>cad;
    for(int i = 0 ; i < cad.size() ; i++) sum += (cad[i] - 'A') + 1;
    A = sum / 2;
    B = sum - A;

    while(A)
    {
        a += alp[min(A , 26)];
        A -= min(A , 26);
    }
    while(B)
    {
        b += alp[min(B , 26)];
        B -= min(B , 26);
    }
    cout<<a<<" "<<b<<"\n";
    return 0;
}
