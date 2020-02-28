#include<bits/stdc++.h>
using namespace std;

int main()
{
int N[103];
int ind;
int n;
cin>>n;
for(ind = 1;ind<=n;++ind)
cin>>N[ind];
ind=1;
float s=0;
while(ind<=n)
{
s=s+N[ind];
ind++;
}

printf("%.2f",s/n);




return 0;
}