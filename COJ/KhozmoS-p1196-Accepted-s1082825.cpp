#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
#define f first
#define s second
typedef pair <int , int > par;
typedef pair <int , par> trio;

const int MAX = 1e6 + 5;
int ar[20];
int n;
bool mk[20];
void out()
{
    for(int i = 0 ; i < n ; i++)
        cout<<ar[i] , cout<<(i + 1 == n ? "\n" : " ");
}
bool prime(int x)
{
    if(x % 2 == 0)
        return false;

    for(int i = 3 ; i * i <= x ; i += 2)
        if(x % i == 0)
        return false;

    return true;
}
void F(int pos , int ant)
{
    if(pos == n)
    {
        out();
        return;
    }
    for(int i = 2 ; i <= n ; i++)
    {
        if(!mk[i] && prime(i + ant))
        {
            bool flag = true;
            if(pos == n - 1){
               flag = false;
            if(prime(i + 1))
               flag = true;
            }
            if(flag){
            mk[i] = true;
            ar[pos] = i;
            F(pos + 1 , i);
            mk[i] = false;
            }
        }
    }
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   int t;
   cin>>t;
   for(int cas = 1 ; t-- ; cas++){
   cin>>n;
   ar[0] = 1;
   cout<<"Case "<<cas<<":\n";
   F(1 , 1);
   }
    return 0;
}
