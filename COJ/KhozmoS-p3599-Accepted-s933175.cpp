#include <bits/stdc++.h>

using namespace std;
string S;
string sub;
int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);
 cin>>S;
 int q;
 cin>>q;
 while(q--)
 {
   int i , j;
   cin>>i>>j;
   if(i > j)
   swap(i , j);
   int t = j - i;
   t++;
   sub = S.substr(i , t);
   //cout<<sub<<"\n";
     int k = 0; int l = t - 1;
     int sum;
     bool flag = false;bool ok = true;
     //out<<k<<" "<<l<<"\n";
     while(k <= l)
     {

       if(k + l == t - 1)
       {
         //cout<<"entre\n";
          if(!flag){
          sum = sub[k] + sub[l];
          flag = true;
          }
         else
         {
          if(sum != sub[k] + sub[l]){
          ok = false;
          break;
          }
         }
       }
       k++;l--;
     }
     if(!ok)
     cout<<"no\n";
     else
     cout<<"yes\n";
 }
    return 0;
}
