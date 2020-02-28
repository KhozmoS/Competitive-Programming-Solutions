#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
vector <int> pri;
const int MAXN = 25000;
bool comp[MAXN];

 void criba()
 {
   for(int i = 4 ; i < MAXN ; i += 2)
   comp[i] = true;
   for(int i = 3 ; i * i < MAXN ; i++)
   {
       if(!comp[i])
       {
           for(int j = i + i ; j < MAXN ; j += i)
           comp[j] = true;
       }
   }
   pri.push_back(2);
   //for(int i = 0 ; i < 20 ; i++)
   //cout<<comp[i]<<"\n";
   for(int i = 3 ; i < MAXN ; i += 2)
   if(!comp[i])
   pri.push_back(i);
 }
 int fact(int x)
 {

     int may = 0;
     while(x % 2 == 0)
     {
         may = x;
         x /= 2;
     }
     for(int i = 1 ; i < MAXN ; i++)
     {
         if(x == 1)
         return may;
         while(x % pri[i] == 0)
         {
             may = pri[i];
             x /= pri[i];
         }
     }
 }
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    criba();
    //for(int i = 0 ; i < 20 ; i++)
    //cout<<pri[i]<<" \n";
    int t;
    cin>>t; int com; int sol;
    int may = -1;
    while(t--)
    {
        int a;
        cin>>a;
         com = fact(a);
        if(com > may){
        may = com;
        sol = a;
        }
    }
    cout<<sol<<'\n';
    return 0;
}
//1501
