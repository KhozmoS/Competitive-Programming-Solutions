#include<bits/stdc++.h>
#define MAXN 100007
int AB[MAXN];
int N , l , v , t , x ,cont;
using namespace std;
void update(int pos , int value)
{
    for(int i = pos ; i <= N ; i += (i & -i))
        AB[i] += value;

}
int sum(int a , int b)
{
    int suma = 0;
    int sumb = 0;
    a--;
    for(int i = a ; i > 0 ; i -= (i & -i))
    {
      suma += AB[i];
    }
    for(int i = b ; i > 0 ; i -= (i & -i))
    {
      sumb += AB[i];
    }
    return sumb - suma;
}

int main()
{
    cont = 1;
    ios_base::sync_with_stdio(0);cin.tie(0);
    int q;
    int t;
    cin>>t;
    for(int m = 0 ; m < t ; m++){
    cin>>N>>q;
    for(int i = 1 ; i <= N ; i++)
    {
        cin>>x;
        update(i , x);
    }
    cout<<"Case "<<cont<<":"<<"\n";
    cont++;
    int k = q;
     while(k--)
     {
    cin>>q;
    if(q == 1)
    {
        cin>>l;
        l++;
        int sol = sum(l , l);
        cout<<sol<<"\n";
        update(l , sol * -1);
    }
    else if(q == 2)
    {
        cin>>l>>v;
        l++;
        update(l , v);
    }
    else
    {
        int i , j;
        cin>>i>>j;
        i++;j++;
        cout<<sum(i , j)<<"\n";
    }
     }
     for(int o = 1 ; o <= N ; o++)
     {
         AB[o] = 0;
     }
    }
    return 0;
}
