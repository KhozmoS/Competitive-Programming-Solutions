#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define db double
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int> ii;
typedef pair <ii , int> iii;
typedef vector <int> vi;
typedef vector < vi > vvi;
typedef vector < ii > vii;
typedef vector < vii > vvii;

const int mod = 1e9+7;
const int MAX = 1e6+5;

int table[24][1005] , N , T , K;
int arr[1000005];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string typ;cin>>typ;
    if(typ == "MULTIPLEXOR")
    {
        cin>>N>>T>>K;
        for(int i = 1 ; i <= N ; i++)
            for(int j = 1 ; j <= K ; j++)
                cin>>table[i][j];
        int it = 1;
        for(int i = it ; i <= K ; i += T)
        {
            for(int k = 1 ; k <= N ; k++){
                int cnt = T;
                int j = i;
                while(cnt--)
                {
                    if(j == K && k == N){
                        cout<<table[k][j]<<"\n";
                    }
                    else
                        cout<<table[k][j]<<" ";
                    j++;
                }
            }
        }
    }
    else{
        cin>>N>>T>>K;
        for(int i = 1 ; i <= N*K ; i++)
            cin>>arr[i];

        int it = 1;
        int pos = 1;
        for(int i = it ; i <= K ; i += T)
        {
            for(int k = 1 ; k <= N ; k++){
                int cnt = T;
                int j = i;
                while(cnt--)
                {
                    if(j == K && k == N){
                        table[k][j] = arr[pos++];
                    }
                    else
                        table[k][j] = arr[pos++];
                    j++;
                }
            }
        }
        for(int i = 1 ; i <= N ; i++)
            for(int j = 1 ; j <= K ; j++)
                cout<<table[i][j]<<(j == K ? "\n" : " ");
    }
}

