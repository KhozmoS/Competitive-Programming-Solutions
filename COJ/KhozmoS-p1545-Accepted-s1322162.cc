#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e2+5;

const int mx[] = {1 , 0 , -1 , 0};
const int my[] = {0 , -1 , 0 , 1};

int n , arr[MAX][MAX];

int countDfs( int x , int y ) {
    int cnt = 1;
    int v = arr[x][y];
    arr[x][y] = 0;
    for( int i = 0 ; i < 4 ; i++ )
    {
        int nx = x + mx[i];
        int ny = y + my[i];
        if( arr[nx][ny] && arr[nx][ny] == v)
            cnt += countDfs( nx , ny );
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while( cin>>n && n ) {
        memset( arr , 0 , sizeof( arr ) );
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= n ; j++ )
                arr[i][j] = n;
        for( int i = 1 ; i < n ; i++ )
            for( int j = 1 ; j <= n ; j++ ) {
                int x , y;
                cin>>x>>y;
                arr[x][y] = i;
            }
        bool ok = true;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= n ; j++ ) {
                // cout<<arr[i][j]<<(j==n ? "\n" : " ");
                if( arr[i][j] && countDfs( i, j ) != n)
                    ok = false;
            }
        cout<<(ok ? "good\n" : "wrong\n");
    }

}
