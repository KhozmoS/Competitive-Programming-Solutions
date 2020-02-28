#include <bits/stdc++.h>

using namespace std;

vector < int > di;

string cad;
bool flag; int sol;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    di.push_back(1);
    cin>>cad;
    int ta = cad.size();
     for(int i = 2 ; i <= ta / 2 ; i ++){
     if(ta % i == 0){
     di.push_back(i);
     }
     }
     //cout<<di[1];
     for(int i = 0 ; i < di.size() ; i ++)
     {
         int k = 0;
         flag = false;
         int s = di[i];
         while(k + s < ta - s)
         {
             string ant = cad.substr(k , s);
             k += s;
             if(ant != cad.substr(k , s)){
             flag = true;
             break;
             }
         }
         if(!flag){
         sol = s;
         break;
         }
     }
     if(!flag)
     cout<<sol<<"\n";
     else
     cout<<0<<"\n";
    return 0;
}
