#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define PB push_back
#define db double
const int MAX = 1e6+5;

typedef long long ll;
typedef pair <int , int> par;
typedef pair <par , int> trio;

string cad;
int k;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>cad>>k;

    for(int i = 0 ; i < cad.size() ; i++){
        int in , fn , mx;

        in = i;
        fn = in;
        mx = cad[i]-'0';

        for(int j = i+1 ; (j < cad.size() && j-i<=k); j++)
        {
           // cout<<i<<" "<<j<<"\n";

            if(cad[j]-'0'>mx){
                fn = j;
                mx = cad[j]-'0';
            }
        }
        k -= (fn-in);
       // cout<<mx<<" "<<k<<"\n";
        while(fn>in)
        {
            swap(cad[fn-1],cad[fn]);
            fn--;
        }
    }
    cout<<cad<<"\n";
}
