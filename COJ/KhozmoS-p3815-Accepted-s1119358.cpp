 #include <bits/stdc++.h>

using namespace std;

const int MAX = 1000007;

typedef long long ll;

ll arx[MAX] , ary[MAX] ,  s;
ll corx[MAX] , cory[MAX];


int binx(int in , int fn , ll pos)
{
   int md = (in + fn) >> 1;

   if(fn - in < 5)
   {
      for(int i = in ; i <= fn ; i++)
        if(arx[i] >= pos)
          return i;

   }
   if(arx[md] < pos)
     return binx(md , fn , pos);

     return binx(in , md , pos);

}

int biny(int in , int fn , ll pos)
{
   int md = (in + fn) >> 1;

   if(fn - in < 5)
   {
      for(int i = in ; i <= fn ; i++)
        if(ary[i] >= pos)
          return i;

   }
   if(ary[md] < pos)
     return biny(md , fn , pos);

     return biny(in , md , pos);

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll x = 0;
    arx[0] = 1ll;
    corx[0] = 0;
    s = 1;
    x--;
    for(int i = 1 ; i < MAX ; i++){
        arx[i] = arx[i - 1] + s;
        s+=2;
        corx[i] = x;
        if(x < 0)
          x-- ,x *= -1;
        else
          x++ , x *= -1;
    }
    ll y = 0;
    ary[0] = 1ll;
    cory[0] = y;
    s = 2;
    y++;
    for(int i = 1 ; i < MAX ; i++)
    {
        ary[i] = ary[i - 1] + s;
        s+=2;
        cory[i] = y;

        if(y < 0)
          y-- , y *= -1;
        else
          y *= -1;
    }
   
    int t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;

        ll yu = biny(0 , MAX - 2, n);

        if(ary[yu] == 1){
            cout<<"0 0\n";
            continue;
        }

        ll yd = yu - 1;
        ll yres;

        if(abs(ary[yu] - n) < abs(ary[yd] - n))
        {
            ll cy = cory[yu];

            if(cy > 0)
              yres = cy - abs(ary[yu] - n);
            else
              yres = cy;
        }
        else
        {
            ll cy = cory[yd];
            //cout<<cy<<" "<<abs(yd-n)<<"\n";
            if(cy > 0)
              yres = cy - abs(ary[yd] - n);
            else
              yres = cy;
        }

        ll xu = binx(0 , MAX - 2, n);

        ll xres;

        ll cx = corx[xu];

        if(cx > 0)
          xres = cx - abs(arx[xu] - n);
        else
          xres = cx + abs(arx[xu] - n);

        cout<<xres<<" "<<yres<<"\n";
    }
    return 0;
}
