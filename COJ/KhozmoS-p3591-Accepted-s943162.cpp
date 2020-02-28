#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000005;

int TA[MAXN] , A[MAXN];

int power(int x , int e)
{
    if(e == 0) return 1;

    if(e % 2 != 0)
    return (((power(x , e - 1)) % 3) * (x % 3)) % 3;

    int r = e / 2;
    return ((power(x , r) % 3) * (power(x , r) % 3)) % 3;
}

int sol , t , sum;
string cad;

int nump;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //cin>>t;
    int N , Q;
    cin>>N>>Q;

    cin>>cad;
    reverse(cad.begin() , cad.end());
    for(int i = 0 ; i < N ; i++)
    {
        A[i] = (cad[i] - '0') * power(2 , i);
         if(i != 0)
        TA[i] = TA[i - 1] + A[i];
       else
       TA[i] = A[i];

    }
    //cout<<cad[N - 3];
    sum = TA[N - 1]; char c;
    while(Q--)
    {
        cin>>c;
        if(c == 'P')
        {
            if(sum % 3 == 0) cout<<"Yes\n";
            else cout<<"No\n";
        }
        else if(c == 'C')
        {
            int pos; cin>>pos;
            if(cad[pos] == '0')
            {
              int ad = power(2 , pos);
              cad[pos] = '1';
              sum += ad;
              A[pos] = ad;
            }
            else
            {
              cad[pos] = '0';
              sum -= A[pos];
              A[pos] = 0;
            }
        }
        else
        {
            int pos , bit;
             cin>>pos>>bit;
            if((cad[pos] - '0') == 0 && (cad[pos] - '0') != bit)
            {
              int ad = power(2 , pos);
              cad[pos] = '1';
              sum += ad;
              A[pos] = ad;
            }
            else if((cad[pos] - '0') == 1 && (cad[pos] - '0') != bit)
            {
              cad[pos] = '0';
              sum -= A[pos];
              A[pos] = 0;
            }
        }
    }
    return 0;
}
