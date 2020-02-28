#include<bits/stdc++.h>
using namespace std;
   long long n,sol;
int main ()
{
    while(true){
        cin>>n;
        if(n == 0)
           break;
     for(int i = 0;i <= n;i++){
        sol += pow(i,2);
     }
        cout<<sol<<endl;
        sol = 0;
    }

    return 0;
}
