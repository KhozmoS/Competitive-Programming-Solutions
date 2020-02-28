#include<bits/stdc++.h>

using namespace std;

int main()
{
 string cad; int t;
cin>>t; cin>>cad;
 sort(cad.begin() , cad.end());
cout<<cad[t / 2]<<"\n";
}