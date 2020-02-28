#include<bits/stdc++.h>
#define MAXN 250000
using namespace std;
const int MAY = 1000005;
vector<int>p;
int contt;
   int it;
  bool mk[MAXN];
  int prime [MAXN];
  void criba()
  {
    int s = 2;
    mk[1] = true;
    while(s < MAXN / 2)
    {
       if(s != 2 && s % 2 == 0)s++;
      for(int i = s + s ; i <= MAXN ; i += s)
      {
         mk[i] = true;
      }
      do{
      s ++;
      }while(mk[s]);

    }

  }
  bool factoriza(int n)
  {
    p.clear();
    int e = 0;
    if(n % 2 == 0){
    while(n % 2 == 0)
     n /= 2,e++;
     if(e > 1)
     return false;
     p.push_back(2);
    }
      for(int i = 3 ; i * i <= n  ; i += 2)
      {
        e = 0;
        if(n % i == 0)
        {
          while(n % i == 0)
          {
            e++;
            if(e > 1)
            return false;
            n /= i;
          }
        p.push_back(i);
        }
        if(p.size() > 3)
        return false;
      }
      if(n > 1){
       p.push_back(n);
      }

      if(p.size() != 3)
      return false;
      int cont = 0;
      for(int i = 0 ; i < 3 ; i++)
       if(!mk[p[i]])
       cont++;
      if(cont == 3){
      //cout<<cont<<"\n";
      return true;
      }
      return false;
  }
int TA[MAY];
void tabla()
{
  TA[30] = 1;
  for(int i = 31 ; i < MAY ; i++)
  {
    if(factoriza(i))
    TA[i] = (TA[i - 1] + 1);
    else
    TA[i] = TA[i - 1];
  }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
   criba();
   tabla();
   //cout<<mk[9]<<"\n";
   //cout<<TA[30]<<"\n";
   //cout<<factoriza(42)<<"\n";
   int n;
    //cout<<factoriza(30)<<"\n";
    cin>>n;
    while(n--)
    {
        int a , b;
        cin>>a>>b;
        //cout<<TA[31]<<"\n";
        cout<<TA[b] - TA[a - 1]<<"\n";
    }

    return 0;
}
