#include<bits/stdc++.h>

using namespace std;

int per[10];
int fact(int x)
{
 int ret = 1;
 for(int i = 2 ; i <= x ; i++) ret *= i;
 
 return ret;
}
int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);
for(int i = 0 ; i < 10 ; i++) per[i] = i + 1;
int t;
cin>>t;
while(t--)
{
 int n;
 cin>>n;
sort(per , per + n);
int cont = 0;
int ver = fact(n);
do{
 if(cont == ver / 3)
{
  for(int i = 0 ; i < n ; i++) cout<<per[i]; cout<<"\n";
}
cont++;
}while(next_permutation(per , per + n));
}

return 0;
}