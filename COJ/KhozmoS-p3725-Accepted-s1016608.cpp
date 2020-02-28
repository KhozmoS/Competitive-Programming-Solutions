#include <bits/stdc++.h>

using namespace std;


int t , l , a;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //cout << "Hello world!" << endl;
    cin>>t;

    while(t--)
    {
       int sol = 0;
       cin>>l>>a;

       for(int i = 1 ; i <= min(l , a) ; i++)
       {
          if(l % i == 0 && a % i == 0)
          {
              sol = (l / i) * (a / i);
          }
       }
        cout<<sol<<"\n";
    }

    return 0;
}
