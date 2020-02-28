#include <bits/stdc++.h>

using namespace std;
const int MAX = 21;
int ar[MAX];
typedef unsigned long long ll;

string A[MAX] , B[MAX];
int n  , m;

set <string > mka;
set <string> mkb;

bool F(string x , bool group)
{
    if(group && mka.find(x) != mka.end())
         return false;
    if(!group && mkb.find(x) != mkb.end())
         return false;
    if(group)
         mka.insert(x);
    else
         mkb.insert(x);
    if(group)
    {
        bool flag = false;

        for(int i = 0 ; i < n ; i++)
        {
            bool f = true;
            if(A[i].size() < x.size())
            {
                for(int j = 0 ; j < A[i].size() ; j++)
                    if(A[i][j] != x[j]){
                      f = false;
                      break;
                    }
                if(f)
                {
                   string r = "";
                   for(int j = A[i].size() ; j < x.size() ; j++)
                    r += x[j];
                 //  cout<<r<<"\n";
                   flag = F(r , group);

                   if(flag) return true;
                }
            }
            if(A[i].size() > x.size())
            {
                for(int j = 0 ; j < x.size() ; j++)
                    if(A[i][j] != x[j]){
                      f = false;
                      break;
                    }
                if(f)
                {
                   string r = "";
                   for(int j = x.size() ; j < A[i].size() ; j++)
                    r += A[i][j];
                  // cout<<r<<"\n";
                   flag = F(r , !group);

                   if(flag) return true;
                }
            }
            if(A[i].size() == x.size()){
               if(A[i] == x) return true;
            }
        }

    }

    if(!group)
    {
        bool flag = false;

        for(int i = 0 ; i < m ; i++)
        {
            bool f = true;
            if(B[i].size() < x.size())
            {
                for(int j = 0 ; j < B[i].size() ; j++)
                    if(B[i][j] != x[j]){
                      f = false;
                      break;
                    }
                if(f)
                {
                   string r = "";
                   for(int j = B[i].size() ; j < x.size() ; j++)
                    r += x[j];
                   // cout<<r<<"\n";
                   flag = F(r , group);
                   if(flag) return true;
                }
            }
            if(B[i].size() > x.size())
            {
                for(int j = 0 ; j < x.size() ; j++)
                    if(B[i][j] != x[j]){
                      f = false;
                      break;
                    }
                if(f)
                {
                   string r = "";
                   for(int j = x.size() ; j < B[i].size() ; j++)
                    r += B[i][j];
                  // cout<<r<<"\n";
                   flag = F(r , !group);
                   if(flag) return true;
                }
            }
            if(B[i].size() == x.size()){
               if(B[i] == x) return true;
            }
        }

    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;

   for(int i = 0 ; i < n ; i++) cin>>A[i];
   for(int i = 0 ; i < m ; i++) cin>>B[i];
   bool ans = false;
   for(int i = 0 ; i < n ; i++)
   {
       ans = F(A[i] , false);
       if(ans){
        cout<<"S\n";
        return 0;
       }
   }


       cout<<"N\n";
    return 0;
}
