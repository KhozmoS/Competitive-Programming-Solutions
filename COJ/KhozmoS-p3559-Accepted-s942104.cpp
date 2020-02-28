#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1005;
typedef pair <int , int> par;
vector <int> pri;
bool comp[MAXN];
void criba()
{
       for(int i = 4 ; i < MAXN ; i += 2)
       comp[i] = true;

       for(int i = 3 ; i * i < MAXN ; i += 2)
       {
           if(!comp[i])
           {
               for(int j = i * i ; j < MAXN ; j += i)
                 comp[j] = true;
           }
       }
       pri.push_back(2);
       for(int i = 3 ; i < MAXN ; i += 2)
       if(!comp[i])
       pri.push_back(i);
}
int A[MAXN] , B[MAXN] , C[MAXN];
int maxpri;
void fact(int x , int num)
{    if(num == 1){
    if(x % 2 == 0)
    {
      while(x % 2 == 0)
      {
          x /= 2;
          A[2]++;
          if(maxpri < 2)
          maxpri = 2;
      }
    }
    for(int i = 1 ; i < pri.size() ; i++)
    {
        if(x == 1)
        break;
        while(x % pri[i] == 0)
        {
            x /= pri[i];
            if(maxpri < pri[i])
            maxpri = pri[i];
            A[pri[i]]++;
        }
    }}
    if(num == 2){
    if(x % 2 == 0)
    {
      while(x % 2 == 0)
      {
          x /= 2;
          if(maxpri < 2)
            maxpri = 2;
          B[2]++;
      }
    }
    for(int i = 1 ; i < pri.size() ; i++)
    {
        if(x == 1)
        break;
        while(x % pri[i] == 0)
        {
            x /= pri[i];
            if(maxpri < pri[i])
            maxpri = pri[i];
            B[pri[i]]++;
        }
    }}
}
int t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    criba();
    int ta = pri.size();
    cin>>t;
    while(t--)
    {
        maxpri = 0;
        int n , a , b;
        cin>>n>>a>>b;
        fact(a , 1);
        fact(b , 2);
        int pos = 2;
        while(true)
        {
          for(int i = 0 ; i < ta ; i++)
          {
              C[pri[i]] = A[pri[i]] + B[pri[i]];
          }
          if(pos == n)
          break;
          for(int i = 0 ; i < ta ; i++)
          {
              A[pri[i]] = B[pri[i]];
              B[pri[i]] = C[pri[i]];
              C[pri[i]] = 0;
          }
          pos++;
        }
        for(int i = 0 ; i < ta ; i++)
        {
           if(C[pri[i]] != 0)
           {
               cout<<pri[i]<<" "<<C[pri[i]]<<"\n";
           }
        }
        cout<<"\n";
        for(int i = 0 ; i < ta ; i++)
        {
           A[pri[i]] = B[pri[i]] = C[pri[i]] = 0;
        }

    }

    return 0;
}
