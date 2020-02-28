#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define db double
#define all(c) (c).begin(),(c).end()
#define sz(c) (c).size()

typedef long long ll;
typedef pair <int , int> ii;
typedef pair <ii , int> iii;
typedef vector <int >vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const int MAX = 1e6+5;


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;cin>>n;
    int A = 0;
    int C = 0;
    int G = 0;
    int T = 0;

    string cad;cad.reserve(10000+5);

    cin>>cad;
    cad = " "+cad;
    for(int i = 1 ; i <= n ; i++)
    {
        A += cad[i]=='A';
        C += cad[i]=='C';
        G += cad[i]=='G';
        T += cad[i]=='T';
    }
    if(A <= min(C , min(G,T)))
    {
        cout<<min(min(A,C) , min(G,T))<<"\n";
        for(int i = 1 ; i <= n ; i++) cout<<'A';
        cout<<"\n";
    }
    else if(C <= min(A , min(G,T)))
    {
        cout<<min(min(A,C) , min(G,T))<<"\n";
        for(int i = 1 ; i <= n ; i++) cout<<'C';
        cout<<"\n";
    }
    else if(G <= min(A , min(C,T)))
    {
        cout<<min(min(A,C) , min(G,T))<<"\n";
        for(int i = 1 ; i <= n ; i++) cout<<'G';
        cout<<"\n";
    }
    else
    {
        cout<<min(min(A,C) , min(G,T))<<"\n";
        for(int i = 1 ; i <= n ; i++) cout<<'T';
        cout<<"\n";
    }


}
