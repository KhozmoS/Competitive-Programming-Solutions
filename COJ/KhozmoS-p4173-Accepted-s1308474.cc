#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define db double
#define all(c) (c).begin(),(c).end()
#define sz(c) (c).size()

typedef long long ll;
typedef pair <int , int> ii;
typedef pair <ii , int> iii;
typedef vector <int >vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e9+7;
const int MAX = 1e6+5;


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;cin>>n;

    while(n--)
    {
        string in;
        cin>>in;
        int SZ = sz(in);
        in = " " + in;
        in = in + " ";
        bool ok = false;
        for(int i = 1 ; i <= SZ-2 ; i++){
            ok |= (in[i]==in[i+2] || (in[i]==in[i+3] && (in[i+1]==in[i+2])));
        }
        if(ok){
            cout<<"TAK\n";
        }
        else{
            cout<<"NIE\n";
        }
    }
}
