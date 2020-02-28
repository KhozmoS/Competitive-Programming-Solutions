#include <bits/stdc++.h>

using namespace std;


#define f first
#define s second
#define pb push_back
#define db long double
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int > ii;
typedef pair <ii , int > iii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e7+5;
const int MAX = 1e6+5;
const int mx[] = {0,1,1,1,0,-1,-1,-1};
const int my[] = {1,1,0,-1,-1,-1,0,1};

bool mk[mod];

void criba() {
    mk[0] = 1;
    mk[1] = 1;
    for(int i = 4 ; i < mod ; i += 2) mk[i] = 1;
    for(int i = 3 ; i * i < mod ; i += 2)
        if(!mk[i]) for(int j = i*i ; j < mod ; j += i)
                        mk[j] = 1;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    criba();
    int cnt = 0;
    string in;
    int k;
    while( cin>>k>>in ) {
        cnt = 0;
        int num = 0;
        bool ok = true;
        for(int i = 0 ; i <= sz(in) ; ++i) {
//            cout<<num<<" "<<cnt<<" "<<k<<"\n";
            if(cnt%k==0 && cnt) {
                ok &= !mk[num];
//                cout<<num<<"\n";
                num = 0;
            }
            if(i != sz(in))
                num = num*10 + (in[i]-48);

            cnt++;
        }
        cout<<(ok ? ":)" : ":(")<<"\n";
    }
}
