#include <bits/stdc++.h>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
  //  memset(D , -1 , sizeof(D));

     int t;
     cin>>t;
     while(t--)
     {
       int n;
       cin>>n;
       map<int , int > m;
       m[0]++;
       int sum = 0;
       int sol = 0;
       for(int i  = 0 ; i < n ; i++)
       {
         int x;
         cin>>x;
         sum += x;
         sol += m[sum - 47];
         m[sum]++;
       }
        cout<<sol<<"\n";

     }


    return 0;
}
