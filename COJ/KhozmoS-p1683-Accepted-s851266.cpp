#include<bits/stdc++.h>

using namespace std;
int main()
{
    int a;
    cin>>a;
   int N;
     for(int j=0;j<a;++j)
     {
   cin>>N;
    int s=0;

   for(int i=1;i<N;++i)
    if(N%i==0)
     s+=i;

     if(s==N)
     cout<<"Perfect"<<endl;
     else if(s<N)
     cout<<"Deficient"<<endl;
     else
     cout<<"Abundant"<<endl;
     }
    return 0;
}
