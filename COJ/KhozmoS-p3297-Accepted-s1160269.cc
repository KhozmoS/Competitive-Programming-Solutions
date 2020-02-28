    //KhozmoS

    #include<bits/stdc++.h>


    using namespace std;

    #define PB push_back
    #define f first
    #define s second

    typedef long long ll;
    typedef pair<int , int> II;
    typedef vector <int> VI;
    typedef vector <int> VI;
    typedef vector <II> VII;

    const int MAX = 1e6*5+5;

    int bit[MAX] , n , k;

    void update(int pos , int v)
    {

        while(pos < MAX)
        {
            bit[pos] += v;
            pos += (pos & -pos);
        }
    }
    int query(int pos)
    {
        int res = 0;
        while(pos > 0)
        {
            res += bit[pos];
            pos ^= (pos & -pos);
        }
        return res;
    }
    int bin(int x)
    {
      int minok = 1e9;
      int sz = (int)pow(2 , 19);
      int pos = sz;
      int sumlost = 0;

      while(sz)
      {
          if(bit[pos] + sumlost >= x)
          {
              minok = min(minok , pos);
              pos = pos - (sz/2);
              sz >>= 1;
          }
          else{
              sumlost += bit[pos];
              pos = pos + (sz/2);
              sz >>= 1;
          }
      }
      return minok;
    }
    int main()
    {
         ios_base::sync_with_stdio(0);cin.tie(0);
         while(cin>>n>>k){
         if(!n && !k)return 0;

         for(int i = 1 ; i <= n ; i++)
             update(i , 1);
         int state = 1;
         int cur = 1;
         while(n != 1)
         {
             int pe = (k-1) % n + 1;
             if(cur-1 >= MAX)return 0;
             int to = query(cur-1);

             int x = to+1;

             if(state&1)
             x = n - to;

             int cant = n-1;

             if(pe > x){
                pe -= x;
                if(state&1)
                to = 0;
                else to = MAX - 2;
             }

             if(state&1)
                  pe = to + pe;
             else
               if(to == MAX-2)
                  pe = n - pe+1;
               else
                  pe = x - pe+1;

             if(!pe || pe > n)return 0;

             int e = bin(pe);
             if(e <= 0)return 0; 
             update(e , -1);
             if(e >= MAX)return 0; 
             x = query(e);
             if((state & 1)  && cant - x == 0) x = 0;
             else if(!(state&1) && !x) x = cant;

             if(state&1)
             x = 1 + x;

             if(x > n-1 || !x)return 0;
             
             cur = bin(x);

             n--;
             state++;
         }
          if(cur <= 0) return 0;
          update(cur , -1);

          cout<<cur<<"\n";
         }

    }
