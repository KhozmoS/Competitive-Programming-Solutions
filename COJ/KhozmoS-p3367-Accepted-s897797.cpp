#include <bits/stdc++.h>
using namespace std;
const int MAX = 1002;
int stop = MAX;
int TA[MAX + 3];
bool isprime(int a)
{
    if(a == 2)
        return true;
    if(a % 2 == 0)
        return false;
    for(int i = 3 ; i * i <= a ; i++)
    {
        if(a % i == 0)
            return false;
    }
    return true;
}
void tabla()
{
    TA[1] = 0;
    int k = 2;
    int marc = 2;
    int num = 2;
    while(stop--){
    int sum = 0;
    for(int i = 0 ; i < marc ; i++)
    {
        if(isprime(num))
            sum += num;
        num++;
    }
    TA[k] = sum;
    k++;
      marc++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    tabla();
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        cout<<TA[n]<<"\n";
    }
    return 0;
}
