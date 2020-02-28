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
const int mx[] = {0,1,1,1,0,-1,-1,-1};
const int my[] = {1,1,0,-1,-1,-1,0,1};

int n , t , ar[MAX] , q;


int main()
{
   // ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;string c;
  cin>>c;
  while(t--) {
    string in;
    while(true) {
        in = "";
        string res = "";
        getline(cin,in);
        in = c + in;
        c = "";
        if(in=="*") break;
        string word = "";
        for(int i = 0 ; i < sz(in) ;i++) {

            if(in[i] >= 'a' && in[i] <= 'z' || in[i] >= 'A' && in[i] <='Z') {

                word += in[i];
            } else {
                char s = word[0];
                word[0] = tolower(word[0]);
                reverse(all(word));
                if(isupper(s)) {
                    word[0] = toupper(word[0]);
                }
                res += word;
                res += in[i];
                word = "";
            }
        }
        if(sz(word)) {
            char s = word[0];
            word[0] = tolower(word[0]);
            reverse(all(word));
            if(isupper(s)) {
                word[0] = toupper(word[0]);             
            }
             res += word;
        }
        cout<<res<<"\n";
    }
    if(t)
        cout<<"\n";
  }

}
/*
13
0 0 1

1 1

2 0 1

3 0 2

4 0 3

5 0 4

6 1

7 1

8 1

9 1

*/
