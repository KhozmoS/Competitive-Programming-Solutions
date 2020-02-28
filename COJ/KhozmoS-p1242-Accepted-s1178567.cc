#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e8 + 5;

int n , k;

int dig1[11];
int dig2[11];
int pot[11] , tot1 , tot2;
int pref1[11] , pref2[11];
int cur1[11] , cur2[11];
void cont1(int cnt)
{
        for(int i = 0 ; i < 10 ; i++)
            dig1[i] += (cur1[i] * pot[tot1-cnt]);
        for(int j = 0 ; j < 10 ; j++)
            dig1[j] += pot[tot1-cnt-1] * (tot1-cnt);
}
//1
void cont2(int cnt)
{
       for(int i = 0 ; i < 10 ; i++)
            dig2[i] += (cur2[i] * pot[tot2-cnt]);
        for(int j = 0 ; j < 10 ; j++)
            dig2[j] += pot[tot2-cnt-1] * (tot2-cnt);
}
void F(int num , int cnt)
{
    if(cnt && pref1[cnt-1] > num)
    {
        cont1(cnt);
        return;
    }

    if(cnt == tot1){
        for(int i = 0 ; i < 10 ; i++)
            dig1[i] += cur1[i];
        return;
    }

    for(int i = 0 ; i < 10 ; i++)
    {
         if(!cnt && !i) continue;
         int p = num*10+i;
         if(p > pref1[cnt])
            continue;


         cur1[i]++;
         F(p , cnt+1);
         cur1[i]--;
    }
}
void f(int num , int cnt)
{
    if(cnt && pref2[cnt-1] > num)
    {
        cont2(cnt);
        return;
    }

    if(cnt == tot2){
        for(int i = 0 ; i < 10 ; i++)
            dig2[i] += cur2[i];
        return;
    }
    for(int i = 0 ; i < 10 ; i++)
    {
         if(!cnt && !i) continue;
         int p = num*10+i;
         if(p > pref2[cnt])
            continue;
         cur2[i]++;
         f(p , cnt+1);
         cur2[i]--;
    }
}
void transf1(int x)
{
    while(x)
    {
        pref1[tot1] = x%10;
        x/=10;
        tot1++;
    }
    reverse(pref1 , pref1 + tot1);
    for(int i = 1 ; i < tot1 ; i++)
        pref1[i] = pref1[i-1] * 10 + pref1[i];
}
void transf2(int x)
{
    while(x)
    {
        pref2[tot2] = x%10;
        x/=10;
        tot2++;
    }
    reverse(pref2 , pref2 + tot2);
    for(int i = 1 ; i < tot2 ; i++)
        pref2[i] = pref2[i-1] * 10 + pref2[i];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a , b;
    pot[0] = 1;
    for(int i = 1 ; i < 10 ; i++)
        pot[i] = pot[i-1] * 10;

    while(cin>>a>>b && a)
    {
        memset(dig1 , 0 , sizeof(dig1));
        memset(dig2 , 0 , sizeof(dig2));
        tot1 = 0;
        tot2 = 0;
        a--;
        transf2(a);
        transf1(b);

        for(int i = 1 ; i < tot1 ; i++)
        {
            for(int d = 0 ; d < 10 ; d++)
            {
                int m = max(i -2 , 0);
                 if(i > 1)
                    dig1[d] += pot[m] * 9 * (i-1);
                 if(d)
                    dig1[d] += pot[i-1];
            }
        }
        for(int i = 1 ; i < tot2 ; i++)
        {
            for(int d = 0 ; d < 10 ; d++)
            {
                int m = max(i -2 , 0);
                 if(i > 1)
                    dig2[d] += pot[m] * 9 * (i-1);
                 if(d)
                    dig2[d] += pot[i-1];
            }
        }

       F(0 , 0);
       f(0, 0);

        for(int i = 0 ; i < 10 ; i++)
            cout<<dig1[i]-dig2[i]<<(i == 9?"\n":" ");
    }
}
