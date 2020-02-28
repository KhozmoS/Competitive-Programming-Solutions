#include<bits/stdc++.h>

using namespace std;

int main()
{
 int n,a,i;
 float s = 0;
 cin>>n;
    for(i=1;i<=n;++i)
    {
    cin>>a;
    s=s+a;



    }
    printf("%.2f",s/n);
return 0;
}