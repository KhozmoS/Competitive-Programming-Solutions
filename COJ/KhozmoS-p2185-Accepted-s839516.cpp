#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
int a,b;
int c=0;
cin>>a>>b;

if((a>=1)&&(a <= 50)&&(b<=50)&&(b >=1))
    cout<<a+b<<endl;
cout<<a-b<<endl;
cout<<a*b<<endl;
cout<<a/b<<endl;
cout<<a%b<<endl;

return 0;
}
