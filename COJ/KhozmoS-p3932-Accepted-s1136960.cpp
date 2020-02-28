#include <bits/stdc++.h>

using namespace std;

string num;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;

    cin>>t;
    while(t--)
    {
      cin>>num;
      if(num == "0") {cout<<"0\n"; continue;}

      if(num[0] == '-')
      {
        string sec = "";
        for(int i = 1 ; i < num.size() ; i++)
          sec += num[i];
        sort(sec.begin() , sec.end());
        reverse(sec.begin() , sec.end());
        cout<<'-'<<sec<<"\n";
        continue;
      }
      char in = '9';
      int pos = 0;
      for(int i = 0 ; i < num.size() ; i++)
       {
          if(num[i] <= in && num[i] != '0'){
           in = num[i];
           pos = i;
           }
       }
      string sec = "";
      for(int i = 0 ; i < num.size() ; i++)
      if(i != pos)
       sec += num[i];
      sort(sec.begin() , sec.end());
      cout<<in<<sec<<"\n";
    }

}
