#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    string ter="";
    while(true)
    {
        cin>>a;
        if(a<0)
        break;
         while(a > 0)
         {
             if(a%3==1)
              ter='1'+ter;
              else if(a%3==2)
               ter='2'+ter;
               else
               ter='0'+ter;
               a/=3;
         }
         //ter='1'+ter;
         cout<<ter<<endl;
         ter="";
    }
    return 0;
}
