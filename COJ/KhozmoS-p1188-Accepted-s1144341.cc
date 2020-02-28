#include <bits/stdc++.h>

using namespace std;
int a=0;
int b=0;
int p=0;
int d=0;
int arr[25];
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>a>>b;
   while(b!=0){
    arr[p++]=b%10;
    b=(int)b/10;
   }
   while(a!=0){
    for(int i=0;i<25;i++){
        d+=a%10*arr[i];
    }
    a=(int)a/10;
   }
   cout<<d<<endl;
    return 0;
}