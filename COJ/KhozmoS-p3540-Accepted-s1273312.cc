#include <bits/stdc++.h>

using namespace std;

#define PB push_back
const int MAX = 1e3+5;
typedef long long ll;
int fail[MAX];
const ll mod = 4294967296;


struct matriz{
  ll m[55][55];

  matriz()
  {
      memset(m , 0 , sizeof(m));
  }
  matriz(int x)
  {
      memset(m , 0 , sizeof(m));
      for(int i = 0 ; i < 55 ; i++)
          m[i][i] = 1;
  }
  matriz operator * (const matriz &X)const{
        matriz res = matriz();
        for(int k = 0 ; k < 55 ; k++)
            for(int i = 0 ; i < 55 ; i++)
                for(int j = 0 ; j < 55 ; j++){
                    res.m[i][j] += (m[i][k]*X.m[k][j]%mod);
                    res.m[i][j] %= mod;
                }
        return res;
  };

};


void build_kmp(string P)
{
    int N = P.size();
    fail[0] = -1;
    int j = -1;
    int i = 0;
    while(i<N)
    {
        while(j > -1 && P[i] != P[j])
            j = fail[j];
        i++,j++;
        if(P[i]==P[j]) fail[i] = fail[j];
        else fail[i] = j;
    }
//    for(int i = 0 ; i < N ; i++)
//        cout<<fail[i]<<" ";
//        cout<<endl;
}

int kmp(string T , string P)
{
    int res = 0;
    int N = T.size();int M = P.size();
    int j , i; j = i = 0;
    while(i<N)
    {
        while(j>-1 && P[j]!=T[i]) j = fail[j];
        i++;
        j++;
        if(j==M){
           j = fail[j];
           res++;
        }
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int k;
    cin>>k;
    string txt;cin>>txt;
    int ans = -1;
    for(int i = 0 ; i < txt.size() ; i++)
    {
        string p="";
        for(int j = i ; j < txt.size() ; j++)
        {
            p+=txt[j];
            memset(fail , -1 , sizeof(fail));
            build_kmp(p);
            int cnt = kmp(txt,p);
            if(cnt==k) ans=max(ans,(int)p.size());
        }
    }
    cout<<ans<<"\n";

}
