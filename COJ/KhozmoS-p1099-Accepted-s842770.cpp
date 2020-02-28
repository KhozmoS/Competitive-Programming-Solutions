#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b,c;
    while(true)
    {
         cin>>a;
         if(a==0)
            break;
         cin>>b;
         cin>>c;
        if ((a*a)+(b*b)==(c*c))
            cout<<"right"<<endl;
        else if((a*a)==(b*b)+(c*c))
            cout<<"right"<<endl;
        else if((a*a)+(c*c)==(b*b))
            cout<<"right"<<endl;
        else
            cout<<"wrong"<<endl;
    }
       return 0;
}