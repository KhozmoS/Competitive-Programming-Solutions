#include <bits/stdc++.h>

using namespace std;
//vector <int> div;
//string cad;
//bool map[12];
 int sol; int izq , der; int apple , pos;
 int n , m;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n>>m;
    cin>>apple;
    izq = 1; der = m;
    while(apple--)
    {
        cin>>pos;
        if(pos < 1 || pos > n)
        continue;
        if(izq <= pos && der >= pos)
        continue;
        else if(izq > pos)
        {
            sol += (izq - pos);
            izq = pos;
            der = (pos + m) - 1;
        }
        else if(der < pos)
        {
            sol += (pos - der);
            der = pos;
            izq = (pos - m) + 1;
        }
    }
     cout<<sol<<"\n";
    return 0;
}
