#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000005;

bool mk[MAXN];
int sol[MAXN] ,val[MAXN];
int may;
int N , M;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        cin>>N;
        may = -1;
    for(int i = 0 ; i < N ; i++)
    {
        cin>>val[i];
        sol[i] = 1;
    }
       for(int i = 0 ; i < N ; i++)
       for(int j = i ; j >= 0 ; j--)
       {
         if(val[i] > val[j])
         {
           if(sol[i] < sol[j] + 1)
           sol[i] = sol[j] + 1;
         }
         if(may < sol[i])
         may = sol[i];
       }
       cout<<may<<"\n";
    }
}
//1 6 2 3 5
