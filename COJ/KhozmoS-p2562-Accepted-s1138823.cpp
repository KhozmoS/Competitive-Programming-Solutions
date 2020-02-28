#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e6 + 5;
int pr[MAX] , p;
bool mk[MAX];


void solve(int x)
{
       for(int i = 2 ; i * i <= x ; i++)
       {
           int d = i;
           if(!(x % d))
           {
              int e = 0;
              while(!(x % d))
              {
                 e++;
                 x /= d;
              }
              cout<<'('<<d<<'('<<e<<')'<<')';
           }
       }
       if(x - 1)
           cout<<'('<<x<<'('<<1<<')'<<')';
           cout<<'\n';
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
  
   int n; 
   
   while(cin>>n)
     solve(n);
   
   
   
}