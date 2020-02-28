    #include <bits/stdc++.h>

    using namespace std;

    const int MAX = 1e5 + 5;
    typedef long long ll;
    typedef pair <int , int> par;
    map <ll , int> dp;

    ll ar[MAX];
    int c;
    par ans[MAX];


    int RMQ[MAX][20];
    int query(int a , int b)
    {
      int l = (int)log2(b - a + 1);

      return max(RMQ[a][l] , RMQ[b - (1 << (l)) + 1][l]);

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

     for(int i = 1 ; i <= c ; i++) RMQ[ans[i].second][0] = ans[i].first;

      for(int k = 1 ; (1 << k) <= n ; k++)
        for(int i = 1 ; i + (1 << k) - 1 <= n ; i++)
          RMQ[i][k] = max(RMQ[i][k - 1] , RMQ[i + (1 << (k - 1))][k - 1]);

      while(q--)
      {
        int a , b; cin>>a>>b;
        if(a > b) swap(a , b);


        int y = query(a , b);
       // cout<<y<<"\n";
        if(y >= a)
           cout<<"YES\n";
        else
           cout<<"NO\n";
      }
    }
