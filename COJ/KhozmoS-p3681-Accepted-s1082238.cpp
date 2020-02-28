#include<bits/stdc++.h>


using namespace std;

const int MAX = 1e6 + 5;
const int inf = MAX - 5;

int ST[MAX * 4];
int prime[MAX];
int ar[MAX];
int pos;
set <int> primos;
set <int> :: iterator  ite;
void build(int node , int x , int y)
{
    if(x == y)
    {
        ST[node] = ar[x];
        return;
    }
    int mid = (x + y) / 2;
    build(node * 2 , x , mid);
    build(node * 2 + 1 , mid + 1 , y);

    ST[node] = min(ST[node * 2] , ST[node * 2 + 1]);
}

int query(int node , int x , int y , int a , int b)
{
    if(a > y || b < x)
        return inf;
    if(a <= x && b >= y)
        return ST[node];

    int mid = (x + y) / 2;
    return min(query(node * 2 , x , mid , a , b) , query(node * 2 + 1 , mid + 1 , y , a , b));
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   // cout<<inf<<"\n";
   //for(int i = 0 ; i < MAX ; i++) cout<<ar[i]<<"\n";
    ar[1] = inf;
    for(int i = 4 ; i < MAX ; i += 2)
        ar[i] = inf;

    for(int i = 3 ; i * i < MAX ; i += 2)
        if(ar[i] == 0)
        for(int j = i * i ; j < MAX ; j += (2 * i))
            ar[j] = inf;

    prime[pos++] = 2;
    primos.insert(2);
    for(int i = 3 ; i < MAX ; i += 2)
        if(!ar[i]){
            prime[pos++] = i;
            primos.insert(i);
        }

    for(int i = 0 ; i < pos - 2 ; i++)
        ar[prime[i]] = prime[i + 2] - prime[i] + 1;

    for(int i = 0 ; i < inf ; i++)
        if(!ar[i])
        ar[i] = inf;

    build(1 , 1 , inf);

    int Q;
    cin>>Q;
    primos.insert(0);
    primos.insert(-1);
    primos.insert(-2);
    while(Q--)
    {
        int a , b;
        cin>>a>>b;
        ite = primos.upper_bound(b);


        ite--;
        ite--;
        ite--;

        b = *ite;
        if(a > b){
            cout<<"-1\n";
            continue;
        }

        int sol = query(1 , 1 , inf , a , b);

        if(sol == inf)
            cout<<"-1\n";
        else
            cout<<sol<<"\n";
    }
    return 0;
}
