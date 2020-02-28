#include <bits/stdc++.h>

using namespace std;


const int MAX = 500005;
const int LOGN = 20;

#define L first.second
#define R first.first
#define K second.first
#define Pos second.second

typedef pair <int , int> ii;
typedef pair <ii , ii> querys;


int bit[MAX] , N , n , id;
int ar[MAX] , last[MAX] , answer[MAX];
map <int , int> mp;
querys Q[MAX];

void update(int x , int v) {
    for(; x < MAX ; x += (x&-x))
        bit[x] += v;
}

int query(int x) {
    int res = 0;
    for(; x > 0 ; x -= (x&-x))
        res += bit[x];
    return res;
}


int bit_search(int v)
{
	int sum = 0;
	int pos = 0;

	for(int i=LOGN; i>=0; i--)
	{
		if(pos + (1 << i) <= N && sum + bit[pos + (1 << i)] < v)
		{
			sum += bit[pos + (1 << i)];
			pos += (1 << i);
		}
	}

	return pos + 1;
}
//bool mk[MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>n){
        mp.clear();
        id = 0;
        memset(bit , 0 , sizeof(bit));
        memset(last , 0 , sizeof(last));
//        memset(mk , 0 , sizeof(mk));

        for(int i = 1 ; i <= n ; i++) {
            int x;cin>>x;
            if(mp.find(x) == mp.end()) {
                mp[x] = ++id;
            }
            ar[i] = x;
        }

        int q;cin>>q;

        for(int i = 1 ; i <= q; i++) {
            cin>>Q[i].L>>Q[i].R>>Q[i].K;
            if(Q[i].L > Q[i].R)
                swap(Q[i].L , Q[i].R);
            Q[i].Pos = i;
        }
        sort(Q+1 , Q+1+q);
        N = 0;

        for(int i = 1 ; i <= q ; i++) {
            int res = 0;

            for(int j = N+1 ; j <= Q[i].R ; j++) {
                id = mp[ar[j]];
                N = j;
                if(last[id]) {
                    update(last[id] , -1);
                }

                last[id] = j;
                update(j , 1);
            }
            res = bit_search(query(Q[i].L-1) + Q[i].K);

            answer[Q[i].Pos] = (res <= N ? ar[res] : -1);
        }
    //    for(int i = 1 ; i <= N ; i++) {
    //        cout<<query(i)<<" ";
    //    }
    //    cout<<"\n";
        for(int i = 1 ; i <= q ; i++) {
            if(answer[i] == -1) {
                cout<<":(\n";
            }
            else cout<<answer[i]<<"\n";
        }
    }
}
