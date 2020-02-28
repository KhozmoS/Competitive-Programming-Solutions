#include <bits/stdc++.h>

using namespace std;

int main()
{
  string A;
  string B;
    while(cin>>A>>B){
   int ta=A.size();
   int tb=B.size();
   int cont=0;
    for(int i=0;i<ta;++i)
     for(int j=0;j<tb;++j)
      if(B[j]==A[i])
      {i++;cont++;}
      if(cont==ta)
      cout<<"Yes"<<endl;
      else
      cout<<"No"<<endl;
    }
    return 0;
}
