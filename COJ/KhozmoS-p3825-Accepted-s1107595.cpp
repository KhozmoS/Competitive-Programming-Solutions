#include <bits/stdc++.h>

using namespace std;
int q , a , b;
int n , x;
int cont;
const int MAX = 500005;
int ar[MAX];
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);


  while(cin>>n>>x){

    int ans1 = log2(n) + 1;
    int ans2 = 1 << (ans1 - 1);
    int ans3 = 1;
    while(x % 2 == 0){
            x /= 2;
            ans3++;
        }
    cout<<ans1<<" "<<ans2<<" "<<ans3<<"\n";
  }
    return 0;
}
