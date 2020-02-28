#include<bits/stdc++.h>


using namespace std;

int t;
char n[1005];

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;

    while(t--)
    {
       scanf("%s" , &n);

       int sum = 0;

       int len = strlen(n);

       for(int i = 0 ; i < len ; i++) sum += (n[i] - '0');

       cout<<(!((n[len - 1] - '0') % 2) && !(sum % 3) ? "YES\n" : "NO\n");
    }

}
