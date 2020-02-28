#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()
#define db double

typedef long long ll;
typedef pair <int,int> ii;
typedef pair <ii , int> iii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const int MAX = 1e6+5;

int mx[] = {1, 0 , 1, 0};
int my[] = {0 , 1 , 0 , -1};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    if((n%4)%2)
    {
        cout<<"NIE\n";
        return 0;
    }
    int x = 1;
    int y = 2;
    cout<<1<<" "<<1<<"\n";
    cout<<1<<" "<<2<<"\n";
    int cur = 0;
    int area = 0;
    while(cur<((n-4)-(n%4)))
    {
        x += mx[cur%4];
        y += my[cur%4];
        cout<<x<<" "<<y<<"\n";
        cur++;
        if(cur%4==0)
            area += 3;

    }
    cur = 0;
    if(n%4)
    {
       x += (n-area-3);
       while(cur<3)
       {
            x += mx[cur%4];
            y += my[cur%4];
            cout<<x<<" "<<y<<"\n";
            cur++;
       }
       cout<<x<<" "<<1<<"\n";
    }
    else{
        x += (n-area);
        cout<<x<<" "<<2<<"\n";
        cout<<x<<" "<<1<<"\n";
    }
}
