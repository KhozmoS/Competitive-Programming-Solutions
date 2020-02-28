#include<bits/stdc++.h>


using namespace std;

int n;
int ar[3000];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
     int n , x;
        cin>>n>>x;
        for(int i = 0 ; i < n ; i++) cin>>ar[i];
        bool flag = false;
        for(int i = 0 ; i < n ; i++)
            for(int j = i + 1 ; j < n ; j++)
                for(int k = j + 1 ; k < n ; k++)
                    if((ar[i] ^ ar[j] ^ ar[k]) == x)
                        flag = true;

        if(flag) cout<<"YES\n";
        else cout<<"NO";
}
