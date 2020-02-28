#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+5;


const int mx[] = {0 , 1, 1, 1, 0  , -1, -1, -1};
const int my[] = {1 , 1, 0, -1, -1, -1, 0, 1};
#define f first
#define s second
typedef pair <int , int> ii;

struct node {

    long long l , r , money;
    node(int L , int R, int Money) {
        l = L;
        r = R;
        money = Money;
    }
    node(){
        l = 0;
        r = 0;
        money = 0;
    }
}ar[MAX];

int n , d , cnt;

vector <ii> ans;

int moveRight( int i , int t ) {
    while(t--) {
        i = ar[i].r;
    }
    return i;
}
int moveLeft( int i , int t ) {
    while(t--) {
        i = ar[i].l;
    }
    return i;
}
bool mk[MAX];

void Delete( int i , bool save = false) {
    if(mk[i]) return;
    if( save ) {
        ans.push_back(ii(i,ar[i].money));
    }
    mk[i] = true;
//    cout<<i+1<<"\n";
    ar[ar[i].r].l = ar[i].l;
    ar[ar[i].l].r = ar[i].r;
    if(ar[ar[i].r].l == ar[i].r && !mk[ar[i].r]) {
        mk[ar[i].r] = true;
        ans.push_back(ii(ar[i].r,ar[ar[i].r].money));
    }

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    while(cin>>n>>d) {
        cnt = n;
        ans.clear();
        for(int i = 0 ; i < n ; i++)
        {
            ar[i].l = (i-1+n)%n;
            ar[i].r = (i+1)%n;
            ar[i].money = d;
            mk[i] = false;
        }
        int tmp = 0;
        for(int i = 1; i < n ; i++) {
            char c;
            int R , A;
            cin>>c>>R>>A;
            if(cnt==1) continue;

            if(c=='C') {
                tmp = moveRight(tmp,R);
                ar[tmp].money += A;

                if(ar[tmp].money%2==0) {
//                    ar[tmp].money += A;
                    Delete(ar[tmp].l);
                    Delete(ar[tmp].r);
                    cnt -= 2;
                } else {
//                    ar[tmp].money += A;
                    int aux = moveRight(tmp,1);
                    Delete(tmp , 1);
                    tmp = aux;
                    cnt -= 1;
                }
            } else {
                tmp = moveLeft(tmp,R);
                ar[tmp].money += A;
                if(ar[tmp].money%2==0) {
                    Delete(ar[tmp].l);
                    Delete(ar[tmp].r);
                    cnt -= 2;
                } else {
//                    ar[tmp].money += A;
                    int aux = moveLeft(tmp,1);
                    Delete(tmp,1);
                    tmp = aux;
                    cnt -= 1;
                }
            }
        }
        for(int i = 0 ; i < n; i++) {
            if(!mk[i])
                ans.push_back(ii(i,ar[i].money));
        }

        sort(ans.begin(),ans.end());

        for(int i = 0 ; i < ans.size() ; i++) {
            cout<<ans[i].f+1<<" "<<ans[i].s<<"\n";
        }
    }

}
