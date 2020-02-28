#include <bits/stdc++.h>

using namespace std;

int t;
string a , b;
int ar[1111111];


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    for(int i = 1 ; i <= t ; i++)
    cin>>ar[i];

    sort(ar + 1 , ar + t + 1);
    reverse(ar + 1 , ar + t + 1);
    int sol = 0;
    for(int i = 1 ; i <= t ; i++)
    {
     if(ar[i] + i > sol)
     sol = ar[i] + i;
    }
    cout<<sol + 1<<"\n";
    return 0;
}
