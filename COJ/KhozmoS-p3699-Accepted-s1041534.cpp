#include <bits/stdc++.h>


using namespace std;
const int MAXN = 105;


int ar[MAXN];
int n;
int s1 , s2 , may;
int f , s;
int est = 1;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
     cin>>n;

     for(int i = 0 ; i < n ; i++)
     cin>>ar[i];

     while(n >= 2)
     {
         may = -1; s1 = -1; s2 = -1;
         for(int i = 0 ; i < n - 1; i++)
         {
           if(ar[i] + ar[i + 1] > may)
           {
             may = ar[i] + ar[i + 1];
             s1 = i;
             s2 = i + 1;
           }
         }
         ar[s1] = ar[s1] + ar[s2];
         for(int i = s2 ; i < n - 1 ; i++)
         ar[i] = ar[i + 1];

         if(est == 1)
         f += may;
         else
         s += may;

         est *= -1;
         n--;
     }
     if(f > s)
        cout<<"First\n";
     else if(f == s)
        cout<<"Tie\n";
     else
        cout<<"Second\n";
    return 0;
}
