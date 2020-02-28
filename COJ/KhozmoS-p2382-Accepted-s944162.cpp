#include <iostream>

using namespace std;
int m , d , b;
string num;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>num>>b>>d;
    int ta = num.size();

    for(int i = 0 ; i < ta ; i++)
    {
        m = (m * b + (num[i] - '0')) % d;
    }
     if(m == 0) cout<<"YES\n";

     else cout<<"NO\n";
    return 0;
}
