#include <bits/stdc++.h>

using namespace std;
 string cad;
 int a , b , n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
     while(n--)
     {
       cin>>cad;
       char x = cad[0] - 'a';
       char y = cad[1] - '0';
        if(x % 2 == 0 && y % 2 == 0)
            cout<<"BLACK\n";
        else if(x % 2 == 1 && y % 2 == 1)
            cout<<"BLACK\n";
        else
            cout<<"WHITE\n";
     }

    return 0;
}
