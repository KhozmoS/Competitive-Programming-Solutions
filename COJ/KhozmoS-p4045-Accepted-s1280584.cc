#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

const int MAX = 1e5+5;

#define PB push_back
#define db double
#define f first
#define s second


int t, n , p;
ll finish[MAX];

typedef pair <int , int> par;
typedef pair <ll , par> trio;
par dancers[MAX];

db sq(db x)
{
    return x*x;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        double a , b , p , q;
        cin>>p>>q>>a>>b;
        if(a<b) swap(a,b);
        if(p<q) swap(p,q);
        double r = (db)1.0*(((db)2.0*p*q*a)+((sq(p)-sq(q))*sqrt(sq(p)+sq(q)-sq(a))))/(sq(p)+sq(q));
        if(p*q<=a*b && (sq(p)+sq(q)) <= (sq(a)+sq(b)) && (p+q)<=(a+b) && min(p,q) <= min(a,b))
        {
        if(((b>=r) && p>a)|| (p<=a&&q<=b))
            cout<<"yes\n";

        else cout<<"no\n";
        }
        else cout<<"no\n";
    }
}
