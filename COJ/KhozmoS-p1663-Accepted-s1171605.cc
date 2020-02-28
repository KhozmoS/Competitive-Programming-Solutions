#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector <ll> VI;

bool arr[105][105];
int x , y;
int n;
bool ok(){

   int sumf, sumc;
   for(int i = 1 ; i <= n ; i++){
        sumf = 0;
        sumc = 0;
        for(int j = 1 ; j <= n ; j++)
        {
           sumf  += arr[i][j];
           sumc += arr[j][i];
        }
        if(sumf & 1 || sumc & 1) return false;
   }
   return true;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    while(cin>>n && n)
    {
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
               cin>>arr[i][j];
        if(ok())
        {
            cout<<"OK\n";
            continue;
        }
        for(int i = 1 ;i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                if(arr[i][j]){
                    arr[i][j] = 0;
                    if(ok())
                    {
                        x = i;
                        y = j;
                        goto END;
                    }
                    arr[i][j] = 1;
                }
        cout<<"Corrupt\n";
        continue;
        END:n++;

        cout<<"Change bit ("<<x<<","<<y<<")\n";
    }
}
