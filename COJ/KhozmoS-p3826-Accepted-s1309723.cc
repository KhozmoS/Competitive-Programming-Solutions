#include <bits/stdc++.h>

using namespace std;

typedef pair <int , int> ii;
typedef long long ll;
const ll mod = 1000000007;

ll a , b , c , d;

struct matriz{

    ll m[3][3];
    matriz(){
        m[0][0] = b;
        m[0][1] = a*c%mod;
        m[0][2] = a*d%mod;
        m[1][0] = 0;
        m[1][1] = c;
        m[1][2] = d;
        m[2][0] = 1;
        m[2][1] = 0;
        m[2][2] = 0;
    }
    matriz operator * (matriz M)const{
        matriz nw;
        memset(nw.m , 0 , sizeof(nw.m));

        for(int i = 0 ; i < 3 ; i++)
            for(int j = 0 ; j < 3 ; j++)
                for(int k = 0 ; k < 3 ; k++)
                    nw.m[i][j] = (nw.m[i][j] + (M.m[k][j] * m[i][k] % mod)) % mod;
        return nw;
    }

    matriz exp(int b)
    {
        matriz res;
        memset(res.m , 0 , sizeof(res.m));
        matriz A = matriz();
        res.m[0][0] = 1;res.m[1][1] = 1;res.m[2][2] = 1;
        while(b)
        {
            if(b&1)
                res = res * A;
            b >>= 1;
            A = A * A;
        }
        return res;
    }

};

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>a>>b>>c>>d;
   int q;cin>>q;
   while(q--)
   {
       matriz tmp = matriz();
//       for(int i = 0 ; i < 3 ; i++){
//                for(int j = 0 ; j < 3 ; j++) cout<<tmp.m[i][j]<<" ";
//                cout<<"\n";
//           }
       int rec[] = {a,1,0};
       int n;cin>>n;
       int curr = n;
       n = (n+1)/2-1;
       if(n<1)
       {
           cout<<rec[2-curr]<<"\n";
       }
       else{
           //cout<<n<<"\n";
           matriz ans = tmp.exp(n);
//           for(int i = 0 ; i < 3 ; i++){
//                for(int j = 0 ; j < 3 ; j++) cout<<ans.m[i][j]<<" ";
//                cout<<"\n";
//           }
           ll res[3];
           memset(res , 0 , sizeof(res));

            for(int i = 0 ; i < 3 ; i++)
                for(int k = 0 ;k < 3 ; k++)
                   res[i] =  (res[i] + ((ll)rec[k] * ans.m[i][k] % mod)) % mod;

           cout<<res[(curr&1)]<<"\n";
       }
   }
}
