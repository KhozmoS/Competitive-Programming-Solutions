#include <bits/stdc++.h>


using namespace std;

#define db double
string cad;
const int MAX = 105;
struct CIRCLE{
    int x , y , rad;
    db r , g , b;
}C[MAX];
struct SQUARE{
    int x , y , side;
    db r , g , b;
}S[MAX];

int sq(int x){return x*x;}

int check_circle(int X , int Y , int i)
{
    if(sq(X - C[i].x) + sq(Y - C[i].y) == sq(C[i].rad))
        return 1;
    if(sq(X - C[i].x) + sq(Y - C[i].y) < sq(C[i].rad))
        return 2;

        return 0;
}
int check_square(int X , int Y , int i)
{
    if((X == S[i].x || X == S[i].x + S[i].side) && (Y >= S[i].y || Y <= S[i].y + S[i].side))
        return 1;
    if((X >= S[i].x || X <= S[i].x + S[i].side) && (Y == S[i].y || Y == S[i].y + S[i].side))
        return 1;
    if((X >= S[i].x && X <= S[i].x + S[i].side) && (Y >= S[i].y && Y <= S[i].y + S[i].side))
        return 2;

        return 0;
}
int main()
{
     ios_base::sync_with_stdio(0);cin.tie(0);
     cout<<setprecision(0)<<fixed;
     int t;cin>>t;

     for(int cas = 1 ; t-- ; cas++)
     {
         int N , Q;
         cin>>N>>Q;
         int sq = 0, circ = 0;
         for(int i = 0 ; i < N ; i++)
         {
             cin>>cad;
             if(cad[0] == 'S')
             {
                 cin>>S[sq++].x;
                 cin>>S[sq-1].y;
                 cin>>S[sq-1].side;
                 cin>>S[sq-1].r;
                 cin>>S[sq-1].g;
                 cin>>S[sq-1].b;
             }
             if(cad[0] == 'C')
             {
                 cin>>C[circ++].x;
                 cin>>C[circ-1].y;
                 cin>>C[circ-1].rad;
                 cin>>C[circ-1].r;
                 cin>>C[circ-1].g;
                 cin>>C[circ-1].b;
             }
         }
         cout<<"Case "<<cas<<":\n";
         for( ;Q--; )
         {
             db R = 0.00, G = 0.00, B = 0.00;
             int X , Y;
             cin>>X>>Y;
             bool clean = true;
             bool line = false;
             int cnt = 0;
             for(int i = 0 ; i < circ ; i++)
             {
                 if(check_circle(X, Y , i) == 1)
                     line = true;
                 if(check_circle(X, Y , i) == 2)
                 {
                     clean = false;
                     cnt++;
                     R += C[i].r;
                     G += C[i].g;
                     B += C[i].b;
                 }
             }
            // cout<<sq<<" "<<X<<" "<<Y<<"\n";
             for(int i = 0 ; i < sq ; i++)
             {
              //   cout<<S[i].x<<" "<<S[i].y<<" "<<S[i].side<<"\n";
                 if(check_square(X , Y , i) == 1)
                    line = true;
                 if(check_square(X , Y , i) == 2)
                 {
                     clean = false;
                     cnt++;
                     R += S[i].r;
                     G += S[i].g;
                     B += S[i].b;
                 }
             }
             if(line)
                 cout<<"(0, 0, 0)\n";
             else if(clean)
                 cout<<"(255, 255, 255)\n";
             else
                 cout<<"("<<R/db(cnt)<<", "<<G/db(cnt)<<", "<<B/db(cnt)<<")\n";
         }
             if(t)
             cout<<"\n";
     }
}
