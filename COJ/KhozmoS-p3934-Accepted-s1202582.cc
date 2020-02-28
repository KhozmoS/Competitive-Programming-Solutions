#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int ans;
int arr[500][500] , n , m;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++) cin>>arr[i][j];

    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ;j <= m ; j++){
            int topleft = 0;
            int toprigth = 0;
            int downleft = 0;
            int downrigth = 0;
            for(int a = 1 ; a <= n ; a++)
                for(int b = 1 ; b <= m ; b++)
                    if(a < i && b < j) topleft = max(topleft , arr[a][b]);
                    else if(a < i && b > j) toprigth = max(toprigth , arr[a][b]);
                    else if(a > i && b < j)  downleft = max(downleft , arr[a][b]);
                    else if(a > i && b > j)  downrigth = max(downrigth , arr[a][b]);
            ans = max(ans , topleft + toprigth + downleft + downrigth + arr[i][j]);
        }
        cout<<ans<<"\n";
}
