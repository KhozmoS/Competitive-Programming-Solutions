#include <bits/stdc++.h>

using namespace std;

int main()
{
   string cad ; int t; cin>>t;
   while(t--)
   cin>>cad , reverse(cad.begin() , cad.end()) , cout<<cad<<"\n";
}
