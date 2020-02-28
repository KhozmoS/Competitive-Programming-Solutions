#include <bits/stdc++.h>

using namespace std;


typedef pair <int , int> par;

int main()
{

   // cout<<(double)log10(1) * 1000<<"\n";

    int t;
    while( cin>>t && t){
    par ans;
    double may = -1.0;
    while(t--)
    {
        int a , b;
        cin>>a>>b;
        double c = (double)log2((double)a) * (double)b;

        if(c >= may){
            may = c ;ans = par(a , b);
        }
    }

    cout<<ans.first<<" "<<ans.second<<"\n";
    }
  return 0;
}
