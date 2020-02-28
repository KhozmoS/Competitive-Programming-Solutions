#include <iostream>

using namespace std;

int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;++i)
   {
  string N;
  cin>>N;
  int ta=N.size();
    if(((((N[ta-2])-'0')*(2))+N[ta-1]-'0')%4==0)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}


    return 0;
}
