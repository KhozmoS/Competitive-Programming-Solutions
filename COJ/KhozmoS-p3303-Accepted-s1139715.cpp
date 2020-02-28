#include<bits/stdc++.h>


using namespace std;

#define div first
#define pos second

typedef long long ll;
typedef pair <int , int> par;
const int MAX = 1e7 * 3;
par ar[MAX];
int c;
void f(int x , int p)
{
    //if(!(x % 2)) ar[++c] = par(2 , p);

    for(int i = 1 ; i * i <= x ; i++)
        if(x % i == 0){
         if(i != 1)
         ar[++c] = par(i , p);
         if(x / i != i)
         ar[++c] = par(x / i , p);
        }
}
int bin(int in , int fn , int v1 , int v2)
{
    int mt = (in + fn) >> 1;

    if(fn - in < 3)
    {
        for(int i = fn ; i >= in ; i--)
            if(ar[i].div == v1 && ar[i].pos <= v2){
             //cout<<ar[i].div<<" "<<ar[i].pos<<"\n";
             return i;
            }
        return 0;
    }
    if(ar[mt].div < v1)
        return bin(mt , fn , v1 , v2);
    if(ar[mt].div > v1)
        return bin(in , mt , v1 , v2);
    if(ar[mt].pos >= v2)
        return bin(in , mt , v1 ,v2);
    return bin(mt , fn , v1 , v2);
}
int bin1(int in , int fn , int v1 , int v2)
{
    int mt = (in + fn) >> 1;

    if(fn - in < 3)
    {
        for(int i = in ; i <= fn ; i++){
            if(ar[i].div == v1 && ar[i].pos >= v2){
           //  cout<<ar[i].div<<" "<<ar[i].pos<<" "<<v2<<"\n";
             return i;
            }
        }
        return 0;
    }
    if(ar[mt].div < v1)
        return bin1(mt , fn , v1 , v2);
    if(ar[mt].div > v1)
        return bin1(in , mt , v1 , v2);

    if(ar[mt].pos >= v2)
        return bin1(in , mt , v1 ,v2);
    return bin1(mt , fn , v1 , v2);
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   int n; cin>>n;

   for(int i = 1 ; i <= n ; i++){
      int x;
      cin>>x;
      f(x , i);
   }
   sort(ar + 1 , ar + c + 1);
   int q; cin>>q;
  // for(int i = 1 ; i <= c ; i++)
    // cout<<ar[i].div<<" "<<ar[i].pos<<"\n";
   while(q--)
   {
       int i , j , k;
       
       cin>>i>>j>>k;
       if(i > j) swap(i , j);
       if(k == 1) {cout<<j - i + 1<<"\n";continue;}
       int b = bin(1 , c , k , j);
       int a = bin1(1 , c , k , i);
       if(!a || !b) {cout<<"0\n";continue;}
     //  cout<<b<<"\n";
       //cout<<a<<"\n";
       cout<<b - a + 1<<"\n";
   }
}

/*
11 12 22 21
1
2
i = L , long de la sub
j = n , los num del dom
k = la dif valida

i = 1
j = 1 2 3 ... n
dp[i][j] = dp[i - 1][j - k] + dp[i - 1][(j - k) + 1] + ... + dp[i - 1][j + k]
1 2
*/
// n = 5 k = 2 l = 3
// n

