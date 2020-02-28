#include<bits/stdc++.h>
using namespace std;


  int a,cont1,sol,cont3,cont9,cont27 ,contc = 1;
int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
     for(int i = 0; i < n ;i++){
    cin>>a;
       while(sol < a)
       {
           if(sol + 27 <= a){
             sol += 27;
             cont27++;
           }
           else if(sol + 9 <= a ){
            sol += 9;
            cont9++;
           }
           else if(sol + 3 <= a){
            sol += 3;
            cont3++;
           }
           else if(sol + 1 <= a){
            sol += 1;
            cont1++;
           }
       }
       cout<<"Case #"<<contc<<": "<<cont1<<" Coppers "<<cont3<<" Triads "<<cont9<<" Nonas "<<cont27<<" Cubics "<<"\n";
       sol = 0 , contc++ ,cont1 = 0, cont3 = 0 , cont9 = 0 , cont27 = 0;
     }
    return 0;
}
