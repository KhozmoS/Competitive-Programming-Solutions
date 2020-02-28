#include<bits/stdc++.h>


using namespace std;
const int MAX =  1e6 + 2;
bool mk[MAX];
vector <int> id;

int ar[1003] , n;


int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i = 1 ; i <= n ; i++) {
    cin>>ar[i];
    if(!mk[ar[i]]){
     id.push_back(ar[i]);
     mk[ar[i]] = true;
   }
  }
  int ans = 0;
  for(int i = 0 ; i < id.size() ; i++)
  {
    int x = -1;
    int c = 0;
     for(int j = 1 ; j <= n ; j++)
     {
         if(id[i] == ar[j]) continue;

         if(ar[j] != x)
          {
             ans = max(c , ans);
             x = ar[j]; 
             c = 1;         
             continue;
          }
          if(ar[j] == x)
            c++;  
          if(j == n)
            ans = max(ans , c);           
      }    
  }
  cout<<ans<<"\n";
}