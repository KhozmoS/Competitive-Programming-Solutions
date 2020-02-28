#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

const int MAX = 1e5+5;

#define PB push_back
#define db double
#define f first
#define s second


int t, n , p;
ll finish[MAX];

typedef pair <int , int> par;
typedef pair <ll , par> trio;
par dancers[MAX];



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--)
    {
        memset(finish, 0 , sizeof(finish));

        cin>>n>>p;
        vector <trio> v;
        ll time = 0;
        for(int i = 1 ; i <= p ; i++){
            cin>>dancers[i].f>>dancers[i].s;
            int x = dancers[i].f;
            int y = dancers[i].s;

            v.PB(trio(max(finish[x] , finish[y])+1 , par(0,i)));
            ll sm = max(finish[x] , finish[y]);
            finish[x] = sm + (abs(x-y)+10);
            finish[y] = sm + (abs(x-y)+10);

            time = max(finish[x] , time);
            //cout<<time<<" "<<x<<" "<<y<<"\n";
            v.PB(trio(finish[x] , par(1,i)));
        }
        set <int> in;
        int st = 0;
        sort(v.begin() , v.end());
        for(int i = 0 ; i < v.size() ; i++)
        {
            if(!v[i].s.f){ in.insert(v[i].s.s);
                st = max(st , (int)in.size());
            }
            else
                in.erase(v[i].s.s);
        }
        cout<<time<<" "<<st*2ll<<"\n";
    }
}
