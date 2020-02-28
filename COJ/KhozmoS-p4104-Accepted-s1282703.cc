#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define PB push_back
#define db double
const int MAX = 1e6+5;

typedef long long ll;
typedef pair <int , int> par;
typedef pair <par , int> trio;


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string cad;
    cin>>cad;
    int mas = 0;
    int menos = 0;
    for(int i = 0 ; i < cad.size() ; i++)
    {
        if(cad[i]=='+') mas++;
        if(cad[i]=='-') menos++;
    }
    cout<<(mas/2)-(menos/2)<<"\n";
}
