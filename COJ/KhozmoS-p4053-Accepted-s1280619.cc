#include <bits/stdc++.h>

using namespace std;
int arr[500][500];
        int ansr[500];
        int ansc[500];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int r , c;
        
        cin>>r>>c;
        
        memset(ansr , 0 , sizeof(ansr));
        memset(ansc , 0 , sizeof(ansc));

        for(int i = 1 ; i <= r ; i++){
            string cad;cin>>cad;
            for(int j = 1 ; j <= c ; j++){
                arr[i][j] = cad[j-1]-48;
                ansr[i] += arr[i][j];
                ansc[j] += arr[i][j];
            }
        }
       for(int i = 1 ; i <= r ; i++)
           cout<<ansr[i]<<(i==r?"\n":" ");
           
       for(int i = 1 ; i <= c ; i++)
           cout<<ansc[i]<<(i==c?"\n":" ");
    }
}
