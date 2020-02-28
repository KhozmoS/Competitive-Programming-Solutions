#include<bits/stdc++.h>

using namespace std;
  double x,y;
int  main ()
{
    while(true)
    {
        cin>>x>>y;
         if(x == 0 && y == 0){
            cout<<"AXIS"<<endl;
            break;
         }
         else
         {
             if(x == 0 || y == 0)
                cout<<"AXIS"<<endl;
             else if(x > 0 && y > 0)
                cout<<"Q1"<<endl;
             else if(x > 0 && y < 0)
                cout<<"Q4"<<endl;
             else if(x < 0 && y < 0)
                cout<<"Q3"<<endl;
             else
                cout<<"Q2"<<endl;
         }
    }
    return 0;
}
