#include<bits/stdc++.h>


using namespace std;

int t;
string n;

int main()
{
    cin>>t;
    
    while(t--)
    {
       cin>>n;
       
       int sum = 0;
       
       int len = n.size();
       
       for(int i = 0 ; i < len ; i++) sum += (n[i] - '0');
       
       cout<<(!((n[len - 1] - '0') % 2) && !(sum % 3) ? "YES\n" : "NO\n"); 
    }
    
}