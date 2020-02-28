#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e3+5;
string ar[MAX];
vector <string> RI;
vector <string> DRI;
vector <string> DI;

int n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;


    bool flag = false;  bool fr = false;

    for(int i = 1 ; i <= n ; i++)
        cin>>ar[i];
    long long ans = 0;
    for(int i = 1 ; i <= n ; i++){
            flag = false; fr = false;
            bool wa = false;
        for(int j = 0 ; j < ar[i].size() ; j++)
        {
          if(!fr && ar[i][j] == 'R' && !wa)
          {
              fr = true;
          }
          else if(ar[i][j] == 'D' && !flag)
          {
              flag = true;
              wa = true;
          }
          else if(ar[i][j] == 'R' && flag)
          {
              ans++;
              flag = false;
          }
        }
        if(flag && fr)
           DRI.push_back(ar[i]);
        else if(flag)
           DI.push_back(ar[i]);
        else if(fr){
         //  cout<<ar[i]<<"\n";
           RI.push_back(ar[i]);
        }
    }
    flag = false;

    int i = 0; int j = 0 ; int k = 0;
    int mj = DI.size();
    int mi = DRI.size();
    int mk = RI.size();
   // cout<<ans<<"\n";
  //  cout<<mj<<" "<<mi<<" "<<mk<<"\n";
    while(i < DRI.size() || j < DI.size() || k < RI.size())
    {
        if(!flag && j < mj)
        {
            j++;
            flag = true;
        }
        else if(!flag && i < mi)
        {
            i++;
            flag = true;
        }
        else if(flag && i < mi)
        {
            i++;
            ans++;
        }
        else if(flag && k < mk)
        {
            k++;
            ans++;
            flag = false;
        }
        else
        {
            k++;
            j++;
            i++;
        }
    }

    cout<<ans<<"\n";
    return 0;
}
