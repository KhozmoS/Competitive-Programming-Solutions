#include <iostream>

using namespace std;
typedef long long ll;
ll pol_ans[2005] , pol_1[2005] , pol_2[2005] , n , m;

int main()
{
    cin>>n;
    for(int i = 0 ; i <= n ; i++)
        cin>>pol_1[i];
    cin>>m;
    for(int i = 0 ; i <= m ; i++)
        cin>>pol_2[i];
    for(int i = 0 ; i <= n ; i++)
        for(int j = 0 ; j <= m ; j++)
        {
           pol_ans[i + j] += (pol_1[i] * pol_2[j]);
        }
    for(int i = 0 ; i <= n+m ; i++)
            cout<<pol_ans[i]<<(i == (n+m) ? "\n" :  " ");
}
