#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL MAXN = (5 * 1e18) + 7;
const int MAX = 100007;
vector<LL>fib;
map<int , bool> m;
int AB[MAX];
int N;
int A[MAX];
void tabla()
{
    LL x;
    fib.push_back((LL)1);
    fib.push_back((LL)1);
    for(int i = 2 ; i < 92 ; i++)
    {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }
    for(int i = 0 ; i < 90 ; i++)
    {
     for(int j = i + 1 ; j < 91 ; j++)
      {
           x = fib[i] + fib[j];
           m[x] = true;
      }
    }
     m[(LL)2] = false;
     //cout<<x;
}
 void update(int pos , int val)
 {
     for(int i = pos ; i <= N ; i += (i & -i))
      AB[i] += val;
 }
 int sum(int a , int b)
 {
     int suma = 0;
     int sumb = 0;
     a--;
     for(int i = a ; i > 0 ; i -= (i & -i))
     suma += AB[i];
     for(int i = b ; i > 0 ; i -= (i & -i))
     sumb += AB[i];
     return sumb - suma;
 }
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   tabla();
   //  cout<<(LL)MAXN;
   int Q;
   cin >> N >> Q;
   for(int i = 1 ; i <= N ; i++)
   {
     LL x;
     cin>>x;
     if(m[x])
     {
         A[i] = 1;
         update(i , 1);
     }
   }
   //cout<<m[3];
   while(Q--)
   {
       int q;
       int a , b;
       LL x;
       cin>>q;
       if(q == 1){
       cin>>a>>b;
       if(a > b)
       swap(a , b);
       }
       else
       cin>>a>>x;
       if(q == 1)
       {
           cout<<sum(a , b)<<"\n";
       }
       else if(q == 2)
       {
           if(m[x])
           {
               if(A[a] == 0){
               update(a , 1);
                A[a] = 1;
               }
           }
           else
           {
               if(A[a] == 1){
               update(a , -1);
               A[a] = 0;
               }
           }
       }
   }
    return 0;
}
