#include <iostream>

using namespace std;

int main()
{
int n;
cin>>n;
 for(int i=0;i<n;i++)
{ string N;
 cin>>N;
 int ta=N.size();
 int s=0;
 for(int i=0;i<ta;++i)
 s=s+(N[i]-'0');

 if(s%3==0&&(N[ta-1]-'0')%2==0)
 cout<<"YES"<<endl;
 else
 cout<<"NO"<<endl;
}





    return 0;
}