#include <bits/stdc++.h>

using namespace std;
const int MAXN = 5005;
int Fib[MAXN];
bool mk[MAXN];
void tabla()
{
    Fib[0] = 1;
    Fib[1] = 1;
    for(int i = 2 ; ; i++)
    {
        Fib[i] = Fib[i - 1] + Fib[i - 2];
        if(Fib[i] <= 5000)
        mk[Fib[i]] = true;
        else
        break;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //tabla();
    int t , n;
    cin>>t;
    while(t--)
    {

        cin>>n;
        cout<<--n<<"\n";
    }
    return 0;
}
