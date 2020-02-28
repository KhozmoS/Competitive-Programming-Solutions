#include <bits/stdc++.h>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0); 
   string cad ; int t; cin>>t;
   while(t--)
   cin>>cad , reverse(cad.begin() , cad.end()) , cout<<cad<<"\n";
}
