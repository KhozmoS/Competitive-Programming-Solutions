#include <bits/stdc++.h>

using namespace std;

int main()
{
  string cad;
    cin>>cad;
    int sol=0;
     int ta=cad.size();
      for(int i=0;i<ta;i++){
       sol+=(cad[i]-'0'-16);
      }
      cout<<sol<<endl;

    return 0;
}
