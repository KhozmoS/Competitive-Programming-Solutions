#include <bits/stdc++.h>

using namespace std;

int exp_mod(int b, int e)
{
    if(e == 0) return 1;

    if(e % 2 == 1)
    return ((exp_mod(b , e - 1) % 10) * (b % 10)) % 10;
    if(e % 2 == 0)
    {
        int r = exp_mod(b , e / 2);
        return ((r % 10) * (r % 10)) % 10;
    }
}
int a , b;
int main()
{
    //cout << "Hello world!" << endl;
    int t;
    cin>>t;
    while(t--){
    cin>>a>>b;
    cout<<exp_mod(a ,b)<<"\n";
    }
    return 0;
}
