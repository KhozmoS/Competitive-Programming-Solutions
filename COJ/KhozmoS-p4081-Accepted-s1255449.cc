#include <bits/stdc++.h>

using namespace std;
string a , b;
void clean()
{
    string cad = "";
    for(int i = 0 ; i < a.size() ; i++)
    {
        if(a[i] != ' ')
            cad += a[i];
    }
    a = cad;
    cad = "";
    for(int i = 0 ; i < b.size() ; i++)
    {
        if(b[i] != ' ')
            cad += b[i];
    }
    b = cad;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    getline(cin , a);
    getline(cin , b);
    if(a==b){cout<<"Accepted\n";}
    else
    {
        clean();
        if(a==b){cout<<"Presentation Error\n";}
        else cout<<"Wrong Answer\n";
    }
}
