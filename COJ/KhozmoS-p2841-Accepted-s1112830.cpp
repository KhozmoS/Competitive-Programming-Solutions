#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef pair <int , int> par;
const int MAX = 1e5 + 5;
priority_queue <par> cola;
int ar[MAX];

int md[MAX] , mi[MAX];

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;;
   ar[0] = -1;
   ar[n + 1] = -1;
   for(int i = 1 ; i <= n ; i++) cin>>ar[i];

   for(int i = 1 ; i <= n + 1 ; i++)
   {
       if(cola.empty()) cola.push(par(ar[i] , i));

       else{
        while(!cola.empty())
        {
            par p = cola.top();
            if(p.f > ar[i]){
               md[p.s] = i;
               //cout<<"wa\n";
               cola.pop();
            }
            else{
               break;
            }
        }
            cola.push(par(ar[i] , i));
       }
   }
   while(!cola.empty()) cola.pop();
   //if(cola.empty()) cout<<"wa\n";
   for(int i = n ; i >= 0 ; i--)
   {
     if(cola.empty()) cola.push(par(ar[i] , i));

       else{
        while(!cola.empty())
        {
            par p = cola.top();
            //cout<<ar[c]<<"\n";
           // cout<<c<<"\n";
            if(p.f > ar[i]){
               mi[p.s] = i;
               cola.pop();
            }
            else
               break;

        }
        cola.push(par(ar[i] , i));
       }
   }

    int ans = 0;

    for(int i = 1 ; i <= n ; i++)
    {
       int dim = ar[i] * ((md[i]-1) - (mi[i]+1) + 1);
       ans = max(dim , ans);
    }
    cout<<ans<<"\n";
    return 0;
}
