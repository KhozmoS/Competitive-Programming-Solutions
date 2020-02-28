#include <bits/stdc++.h>

using namespace std;


#define f first
#define s second
#define pb push_back
#define db double
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int > ii;
typedef pair <ii , int > iii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e9+5;
const int MAX = 1e6+5;

int mx;int mn = 1e9+5;
bool mk[MAX];
char c;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    cin>>c;

    string in;
    int cnt = 0;
    while(t--) {
        string res = "";
        getline(cin,in);
        if(!cnt){
            in = c+in;
            cnt++;
        }
        for(int i = 0 ; i < sz(in) ; i++) {
            if(in[i] == 'a' || in[i] == 'e' || in[i] == 'i' || in[i] == 'o' || in[i] == 'u')
            {
                res = res + in[i]+"p"+in[i];
            }
            else res += in[i];
        }
        cout<<res<<"\n";
    }


}
