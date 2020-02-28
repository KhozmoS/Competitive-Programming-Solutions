#include <bits/stdc++.h>
 
using namespace std;
 
#define f first
#define s second
 
//typedef pair <int , int> par;
const int MAX = 1e6 + 5;
stack <int> pila;
int ar[MAX*3];
 
int md[MAX] , mi[MAX];
 
int main()
{
   //ios_base::sync_with_stdio(0);cin.tie(0);
 
 //int t;scanf("%d",&t);
 
 //for(int cas = 1 ; t-- ; cas++)
 //{
   int n;scanf("%d",&n);
   ar[0] = -1;
   ar[n + 1] = -1;
   for(int i = 1 ; i <= n ; i++) scanf("%d" , &ar[i]);
 
   for(int i = 1 ; i <= n + 1 ; i++)
   {
      
        while(!pila.empty())
        {
            int x = pila.top();
            if(ar[x] > ar[i]){
               md[x] = i;
               //cout<<"wa\n";
               pila.pop();
            }
            else{
               break;
            }
        }
            pila.push(i);
       
   }
   while(!pila.empty()) pila.pop();
   //if(cola.empty()) cout<<"wa\n";
   for(int i = n ; i >= 0 ; i--)
   {
     
        while(!pila.empty())
        {
            int x = pila.top();
            //cout<<ar[c]<<"\n";
           // cout<<c<<"\n";
            if(ar[x] > ar[i]){
               mi[x] = i;
               pila.pop();
            }
            else
               break;
 
        }
        pila.push(i);
       
   }
 
    long long ans = 0;
 
    for(int i = 1 ; i <= n ; i++)
    {
       long long dim = (long long)ar[i] * (long long)((md[i]-1) - (mi[i]+1) + 1);
       ans = max(dim , ans);
    }
    printf("%d\n",(int)ans);
    while(!pila.empty()) pila.pop();
//}
    return 0;
}
