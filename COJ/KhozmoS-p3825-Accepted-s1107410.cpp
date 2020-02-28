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

  fill(ar, ar + MAX, 1);
    cont = 2;
    for(int i = 2; i < MAX; i *= 2){
        ar[i] = cont;
        for(int j = i + i; j < MAX; j += i){
            ar[j] = cont;
        }
        cont++;
    }
  while(cin>>n>>x){

    int ans1 = log2(n) + 1;
    int ans2 = 1 << (ans1 - 1);

    cout<<ans1<<" "<<ans2<<" "<<ar[x]<<"\n";
  }
    return 0;
}
