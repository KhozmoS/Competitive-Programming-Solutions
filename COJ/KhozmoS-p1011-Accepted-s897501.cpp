#include<bits/stdc++.h>
using namespace std;
 int NG, NM , mayg , maym , t , x;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>t;
     for(int k = 0 ; k < t ; k++)
     {
         cin>>NG>>NM;
        for(int i = 0 ; i < NG ; i++)
        {
            cin>>x;
            if(x > mayg)
               mayg = x;
        }
       for(int  j = 0 ; j < NM ; j++)
       {
           cin>>x;
           if(x > maym)
            maym = x;
       }
       if(mayg >= maym)
        cout<<"Godzilla"<<"\n";
       else
        cout<<"MechaGodzilla"<<"\n";
       mayg = 0;
       maym = 0;
     }
   return 0;
}

