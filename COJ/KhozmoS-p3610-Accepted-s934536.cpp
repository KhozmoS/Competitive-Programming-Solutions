#include<bits/stdc++.h>


using namespace std;

string cad;
int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>cad;
    int sol = 0;
     bool flag = true;
     for(int i = 1 ; i < cad.size() ; i++)
     if(cad[i] != cad[i - 1])
     sol++;
     cout<<(sol + 1) / 2<<"\n"; 
return 0;
}