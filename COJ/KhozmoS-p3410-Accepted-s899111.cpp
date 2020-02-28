#include <bits/stdc++.h>

using namespace std;
int N , a , r ;
int A[2015];
bool marc[2015];
vector<int>year;
int main()
{
  cin>>N;
  for(int i = 0 ; i < N ; i++)
  {
      cin>>a>>r;
      A[a] += r;
      if(marc[a] == false)
      year.push_back(a);
      marc[a] = true;
  }
   sort(year.begin(),year.end());
   int ta = year.size();
   for(int i = 0 ; i < ta ; i++)
   {
       cout<<year[i]<<" "<<A[year[i]]<<"\n";
   }

    return 0;
}
