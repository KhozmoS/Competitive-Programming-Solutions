#include<cstdio>
#include<iostream>
using namespace std;
long long a,b;
int main()
{
cin>>a>>b;
cout<<((((a+b)+(a-b))+(b+a))+(b-a))<<endl;
return 0;
}