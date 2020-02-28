#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
#define mod 1000000007
typedef long long ll;
typedef long double ld;
ll arr[MAX];

int a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("(entrada).in","r",stdin);
    arr[2]=1;
    for(int i=3;i<MAX-3;i++){
        arr[i]=(1+arr[i-1]*(i-2))%mod;
    }
    while(cin>>a)    {
        cout<<arr[a]<<"\n";
    }
}