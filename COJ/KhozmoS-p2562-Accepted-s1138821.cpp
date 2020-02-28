#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e6 + 5;
int pr[MAX] , p;
bool mk[MAX];
void criba()
{
  for(int i = 4 ; i <= MAX ; i += 2) mk[i] = true;
  
  for(int i = 3 ; i * i <= MAX ; i += 2)
    {
       if(!mk[i])
          for(int j = i * i ; j <= MAX ; j += i)
            mk[j] = true;
    }
       pr[++p] = 2;
    for(int i = 3 ; i <= MAX ; i += 2)
      if(!mk[i])
        pr[++p]  = i;
}

void solve(int x)
{
       for(int i = 1 ; i <= p , pr[i] * pr[i] <= x ; i++)
       {
           int d = pr[i];
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
   criba();
   int n; 
   
   while(cin>>n)
     solve(n);
   
   
   
}