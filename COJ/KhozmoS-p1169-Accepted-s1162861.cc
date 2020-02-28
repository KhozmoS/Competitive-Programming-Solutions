//KhozmoS

#include<bits/stdc++.h>


using namespace std;

#define PB push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int , int> II;
typedef vector <int> VI;
typedef vector <II> VII;

const int MAX = 105;
int a , b;
VI adl[MAX];
ll dp[MAX][MAX][MAX] , ar[MAX];
int hotelfula[MAX];
queue <int> ones;
int main()
{
   // cout<<F("0")<<"\n";
	//ios_base::sync_with_stdio(0);cin.tie(0);
    int n , g;cin>>n>>g;
    int cur_room = 0;
    for(int i = 0 ; i < g ; i++)
    {
        int x;cin>>x;

        while(x)
        {
            if(cur_room == n)
            {
                while(x)
                {
                    int r = ones.front();ones.pop();
                    hotelfula[r]++;
                    x--;
                }
            }
            else{
            if(x > 1){
            hotelfula[cur_room++] = 2 ; x -= 2;
            }
            else if(x == 1){hotelfula[cur_room++] = 1 , x-- , ones.push(cur_room-1);}
            }
        }
    }
    for(int i = 0 ; i < n ; i++)
        cout<<hotelfula[i]<<"\n";
}
