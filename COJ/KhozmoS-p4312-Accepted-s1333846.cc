#include <bits/stdc++.h>

using namespace std;


typedef  long long ll;



#define u first.first
#define d first.second

#define f first
#define s second
#define pb push_back

const int mx[] = {0 , 1 , 0 , -1};
const int my[] = {1 , 0 , -1 , 0};

typedef pair <int , int> ii;
typedef pair < ii , ii > item;

const int MAX = 1e6+5;

set <int> S;
vector <ii> ans;
int freq[MAX] , ar[MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    while(cin>>n) {

        S.clear();
        ans.clear();
        for(int i = 1 ; i <= n-2 ; i++) {
            int x;cin>>x;
            freq[x]++;
            ar[i] = x;
        }
        for(int i = 1 ; i <= n ; i++)
        {
            if(!freq[i]) S.insert(i);
        }
        for(int i = 1 ; i <= n-2 ; i++) {
            if(!S.size()) break;
            int tmp = *S.begin();
            S.erase(tmp);
            ii p = ii(tmp , ar[i]);
            if(tmp > ar[i]) swap(p.f , p.s);
            ans.pb(p);
            freq[ar[i]]--;
            if(!freq[ar[i]]) S.insert(ar[i]);
        }
        if(S.size() == 2) {
            set <int> :: iterator it;
            it = S.begin();
            int a = *it;it++;
            int b = *it;
            ans.pb(ii(a,b));
            sort(ans.begin(),ans.end());
            for(int i = 0 ; i < ans.size() ; i++) {
                cout<<ans[i].f<<" "<<ans[i].s<<"\n";
            }
        } else {
            cout<<"-1\n";
        }
    }
}
