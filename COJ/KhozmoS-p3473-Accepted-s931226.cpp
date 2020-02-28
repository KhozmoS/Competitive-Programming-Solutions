#include<bits/stdc++.h>

using namespace std;
 int ang[5];
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i = 0 ; i < 4 ; i++)
    cin>>ang[i] ;
    sort(ang , ang + 4);
    int contr = 0;
    for(int i = 0 ; i < 4 ; i++)
    if(ang[i] == 90)
    contr++;
    if(contr == 2)
    cout<<"right\n";
    else if(ang[0] == ang[1] && ang[0] < 90 && ang[2] == ang[3] && ang[2] > 90)
    cout<<"isosceles\n";
    else
    cout<<"none of the previous\n";
    return 0;
}
