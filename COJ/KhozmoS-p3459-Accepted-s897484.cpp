#include <bits/stdc++.h>

using namespace std;
long long TAC[22];
long long TAT[22];
void tablac(){
    TAC[0] = 0;

  for(int i = 1 ; i <= 20 ; i++)
  {
      TAC[i] = (TAC[i - 1] * i) + 1;
  }
}
int tr;
void tablat(){
  TAT[1] = 0;
  TAT[2] = 8;
   for(int i = 3 ; i <= 20 ; i++)
   {
       TAT[i] = (i * i * i) + TAT[i - 1];
   }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    tablac();
    tablat();
    int t;
    cin>>t;
     for(int i = 0 ; i < t ; i++)
     {
       cin>>tr;
       cout<<TAC[tr]<<" "<<TAT[tr]<<"\n";
     }

    return 0;
}
