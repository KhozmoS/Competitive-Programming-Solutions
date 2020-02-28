#include <bits/stdc++.h>

using namespace std;


#define cik(i, a, b, c) for(int i =(a); i <=(b); i +=(c))
#define bi pair<int, int>
#define f first
#define s second
#define mkp make_pair

const int maxn = 5005;
#define PB push_back

int h , m;

bool mk[10000];

void calc_angle(int a , int b)
{
    int c = abs(a - b);
    mk[c*6] = true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ti = 0;
    while(h != 60)
    {
        calc_angle(h , m);
        ti++ , m++;
        if(ti == 12){
            h++;
            ti = 0;
        }
    }
    int n;
    while(cin>>n)
        cout<<(mk[n]?"Y\n":"N\n");

}