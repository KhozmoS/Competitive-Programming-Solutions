#include<bits/stdc++.h>

using namespace std;
   vector <int> judge;
    int sum,grl,jds,N;
     const int MAX = 10;
 int main ()
 {
     grl = 1;
     cin>>N;
      for(int i = 0; i < N ; i++)
      {
         for(int j = 0; j < MAX ; j++)
         {
             cin>>jds;
             judge.push_back(jds);
         }
           sort(judge.begin(),judge.end());
            for(int j = 1;j < MAX - 1; j++)
            {
                sum += judge [j];
            }
            cout<<grl<<" "<<sum<<endl;
            sum = 0;
            grl++;
            judge.clear();

      }
     return 0;
 }
