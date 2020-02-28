#include <bits/stdc++.h>


using namespace std;
const int MAXN = 45005;

int diet[MAXN] , A[MAXN] ,P[MAXN];

int n , c;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin>>n>>c;
 
    for(int i = 1 ; i <= n ; i++) cin>>P[i]>>A[i];

    for(int i = 1 ; i <= n; i++)
    for(int j = c - P[i] ; j >= 0 ; j--)
    diet[j + P[i]] = max(diet[j + P[i]] , diet[j] + A[i]);

    cout<<diet[c]<<"\n";
    return 0;
}
