#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100005;


long long n , k;

stack <int> pila;

int main()
{

    cin>>n>>k;

         bool flag = false;
         long long num; int pos; int a;
          for(int i = 1 ; i <= n ; i++)
          {
              if((n - i) >= k)
              {
                   flag = true;
                    num = i + k;
                    a = i;
                    //cout<<"wa";
                    break;
              }
              else
              {
               pila.push(i);
               k -= (long long)(n - i);
               continue;
              }

          }
            for(int i = a ; i <= n ; i++)
            {
                if(num == a){
                  cout<<a<<" ";
                  a = 1111111111;
                 continue;
                }

                if(i == a)
                    continue;

                if(num == i)
                {
                  cout<<i<<" "<<a<<" ";
                }
                else
                    cout<<i<<" ";



            }

          while(!pila.empty())
          {
            int x = pila.top();
            pila.pop();
            cout<<x<<" ";
          }

    return 0;
}
