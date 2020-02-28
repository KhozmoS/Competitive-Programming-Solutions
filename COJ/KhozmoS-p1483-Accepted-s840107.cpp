#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,y;
    string fig;
    cin >> fig;
    if(fig == "square")
    {
         cin>> x;
         cout  << x*x;
    }
    else
    {
          cin >> x>>y;
          cout << x*y;

     

    }

	return 0;

}