    #include <bits/stdc++.h>

    using namespace std;

    const int MAX = 1e5 + 5;
    typedef long long ll;
    typedef pair <int , int> par;
    map <ll , int> dp;

    ll ar[MAX];
    int c;
    par ans[MAX];
    int bin1(int in , int fn , int v)
    {
      int mt = (in + fn) >> 1;
      if(fn - in < 5)
      {
         for(int i = in ; i <= fn ; i++)
         {
            if(ans[i].first >= v)
               return i;
         }
         return MAX;
      }

      if(ans[mt].first >= v)
         return bin1(in , mt , v);


      return bin1(mt , fn , v);

    }
    int RMQ[MAX][20];
    int query(int a)
    {
      int l = (int)log2(c - a + 1);

      return min(RMQ[a][l] , RMQ[c - (1 << (l)) + 1][l]);

    }

    int main()
    {
      memset(RMQ , MAX , sizeof(RMQ));
      ios_base::sync_with_stdio(0);cin.tie(0);
      int n , q;
      cin>>n>>q;

      for(int i =  1 ; i <= n ;i++){

        cin>>ar[i];
        if(!ar[i])
          ans[++c] = par(i , i);
        ar[i] += ar[i- 1];
        if(dp.find(ar[i]) != dp.end())
        {
            ans[++c] = par(dp[ar[i]]+1 , i);
        }

           dp[ar[i]] = i;
      }
      sort(ans + 1 , ans + c + 1);

     for(int i = 1 ; i <= c ; i++) RMQ[i][0] = ans[i].second;

      for(int k = 1 ; (1 << k) <= c ; k++)
        for(int i = 1 ; i + (1 << k) - 1 <= c ; i++)
          RMQ[i][k] = min(RMQ[i][k - 1] , RMQ[i + (1 << (k - 1))][k - 1]);
   
      while(q--)
      {
        int a , b; cin>>a>>b;
        if(a > b) swap(a , b);

        int x = bin1(1 ,  c , a);
        if(x > c)
        {
           cout<<"NO\n";
           continue;
        }
        int y = query(x);
       // cout<<y<<"\n";
        if(y <= b)
           cout<<"YES\n";
        else
           cout<<"NO\n";
      }
    }
