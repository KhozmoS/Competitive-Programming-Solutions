#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6;

typedef long long ll;
ll Bas = 311;
const ll mod = 1e9 + 7;
ll H[MAX] , B , P[MAX];
int arr[55][55];int n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            cin>>arr[i][j];
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
        {
            if(arr[i][j] != 1)
            {
                bool ok = false;
                for(int k = 1 ; k <= n ; k++)
                    for(int l = 1 ; l <= n ; l++)
                    {
                        if(k != i && l != j && arr[k][j] + arr[i][l] == arr[i][j])
                            ok = true;
                    }
                if(!ok){
                    cout<<"No\n";
                    return 0;
                }
            }
        }
        cout<<"Yes\n";
}
