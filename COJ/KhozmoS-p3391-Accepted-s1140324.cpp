#include <bits/stdc++.h>

using namespace std;
typedef pair  <int , int > par;
#define iter set <par> :: iterator
const int MAX = 1e5 + 5;
set <par> S;
int ST[MAX * 4] , ar[MAX] , n , q , a , b;
void build(int node , int x , int y)
{
    if(x == y)
    {
        ST[node] = 0;
       iter it = S.find(par(ar[x] , x));
       if(it != S.begin()){
           it--;
           if(it -> first == ar[x])
           {
              ST[node] = it -> second;
           }

       }
       return;
    }

    int mt = (x + y) >> 1;

    build(node * 2 , x , mt);
    build(node * 2 + 1, mt + 1 , y);

    ST[node] = max(ST[node * 2] , ST[node * 2 + 1]);
}
int query(int node , int x , int y)
{
    if(x > a) return 0;

    if(y <= a)
        return ST[node];

    int mt = (x + y) >> 1;

    int a1 = query(node * 2 , x , mt) ;
    int a2 = query(node * 2 + 1 , mt + 1 , y) ;
    return max(a1 , a2);
}
void update(int node , int x , int y)
{
    if(x > a || y < a) return;

    if(x == y)
    {
        if(x == a)
        {
            ST[node] = 0;
            iter it = S.find(par(ar[a] , a));
            if(it != S.begin()){ it--;
              if(it -> first == ar[a])
                 ST[node] = (it -> second);
            }
        }
        return;
    }

    int mt = (x + y) >> 1;
    update(node * 2 , x , mt);
    update(node * 2 + 1, ++mt , y);
    ST[node] = max(ST[node * 2] , ST[node * 2 + 1]);
}char ty;
int main()
{
    //freopen(".in", "r", stdin);


    int auxa , auxb;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;

    for(int i = 1 ; i <= n ; i++) {cin>>ar[i];
    S.insert(par(ar[i] , i));
    }
    build(1 , 1 , n);
    while(q--)
    {
        cin>>ty>>a;
        if(!(ty - 'E'))
        {
            cout<<a - query(1 , 1 , n)<<"\n";
            continue;
        }
        cin>>b;
        iter it = S.find(par(ar[a] , a));
        if(it != S.end()){
        it++;

        auxa = a; auxb = b;
        iter itt = it;
        itt--;
        int x , y; x = itt->first; y = itt->second;
        S.erase(itt);
        b = it -> first;
        a = it -> second;
        if(x == it->first)
        update(1 , 1 , n);

        }
        S.insert(par(auxb , auxa));
        b = auxb;
        a = auxa;
        ar[a] = b;
        update(1 ,1 , n);
        it = S.find(par(b , a));
        it++;
        if(it != S.end()){
        if(it -> first == b)
        {
            a = it->second;
            update(1 , 1 , n);
        }
        }
    }
}
