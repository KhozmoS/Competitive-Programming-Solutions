//n^3 log n solution's


#include <bits/stdc++.h>

using namespace std;

int n , m;
char arr[505][505];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n>>m;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            cin>>arr[i][j];

    for(int i = 1 ; i < n ; i++)
        for(int j = i+1 ; j <= n ; j++)
        {
            string a = "";
            string b = "";
            bool ok = false, imp = false;
            int cnt = 0;
            for(int k = 1 ; k <= n ; k++)
            {
                if(!ok && arr[i][k] != arr[j][k])
                    ok = true;
                if(ok)
                    cnt++;
                if(cnt<=m)
                {
                    a += arr[i][k];
                    b += arr[j][k];
                }
                if(cnt > m && arr[i][k] != arr[j][k])
                    imp = true;
            }
            if(imp)
               continue;
            sort(a.begin() , a.end());
            sort(b.begin() , b.end());
            if(a==b)
            {
                cout<<"DA\n";
                return 0;
            }
        }
    cout<<"NE\n";
}
