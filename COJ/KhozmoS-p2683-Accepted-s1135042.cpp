#include <bits/stdc++.h>

using namespace std;


char A[] = {'0' , '1' , '2', '3', '4', '5', '6','7','8','9','A','B' , 'C' , 'D' , 'E' , 'F' , 'G'};

string conv(int n , int b)
{
    string res = "";

    while(n != 0)
    {
        res  = A[n % b] + res;
        n /= b;
    }
    return res;
}
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n , b;cin>>n>>b;

        cout<<conv(n , b)<<"\n";
    }
  return 0;
}
