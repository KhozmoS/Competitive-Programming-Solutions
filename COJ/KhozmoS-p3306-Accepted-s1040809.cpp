#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000;

int n , t;

int ar[mod + 5];
int ir , r;


int todec(string a , string b)
{
    int n1 = 0;

    reverse(a.begin() , a.end());
    reverse(b.begin() , b.end());
    for(int i = 0 ; i < a.size() ; i++)
    {
        n1 += (pow(8 , i)) * (a[i] - '0');
    }
     int n2 = 0;
    for(int i = 0 ; i < b.size() ; i++)
    {
        n2 += (pow(8 , i)) * (b[i] - '0');
    }

    return n1 + n2;
}

char H[] = {'0' , '1' , '2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' ,'a' ,'b' ,'c' ,'d' ,'e' ,'f'};

string tohex(int x)
{
    string sol = "";

    while(x != 0)
    {
        sol += H[x % 16];
        x /= 16;
    }
    reverse(sol.begin() , sol.end());
    return sol;
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

   string a , b;
   cin>>a>>b;

   cout<<"0x"<<tohex(todec(a , b));

}
