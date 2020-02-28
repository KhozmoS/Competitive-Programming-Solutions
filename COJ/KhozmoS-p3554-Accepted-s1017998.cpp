#include <bits/stdc++.h>

using namespace std;

const int MAXN = 125;

int freqg[MAXN];
int freqS[MAXN];

int ini = 65;
int fin = 122;

int n , m;
string g , S;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    /*char c = 'z';
    int x = (int)c;
    cout<<x<<"\n";
    */ cin>>n>>m;
    cin>>g>>S;
     int x = 0; int y = n - 1;
     for(int i = x ; i <= y ; i ++)
     freqg[g[i]]++;

     for(int i = x ; i <= y ; i++)
     freqS[S[i]]++;

     int sol = 0;
     //cout<<freqS[65]<<"\n";
     while(y < m)
     {
       bool flag = true;
       for(int i = ini ; i <= fin ; i++)
       if(freqg[i] != freqS[i])
       flag = false;

       if(flag) sol++;

       x++; y++;
       freqS[S[x - 1]]--;
       freqS[S[y]]++;
     }
     cout<<sol<<"\n";
    return 0;
}
