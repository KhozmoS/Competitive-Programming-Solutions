 #include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6 + 5;
typedef long long ll;
#define f first
#define s second
typedef pair <int , int> par;
int ST[MAX * 4];
void prop(int node)
{
    ST[node * 2] = 1;
    ST[node * 2 + 1] = 1;
}

int query(int node , int x , int y , int a , int b)
{
    if(a > y || b < x)
        return 1;
    if(a <= x && b >= y)
    {
        int ret = ST[node];
        ST[node] = 1;
        return ret;
    }
    if(ST[node])
        prop(node);

    int mid = (x + y) / 2;
    int ret = 1;
    ret *= query(node * 2 , x , mid , a , b);
    ret *= query(node * 2 + 1 , mid + 1 , y , a , b);
    ST[node] = (ST[node * 2] && ST[node * 2 + 1]);
    return ret;
}

stack <par> pila;
int n , a , b;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(ST , 0 , sizeof(ST));
        cin>>n;
        while(n--){
          cin>>a>>b;
          if(a > b) swap(a , b);
          pila.push(make_pair(a , b));
        }
        int sol = 0;
        while(!pila.empty())
        {
           par p = pila.top();
           pila.pop();
           a = p.f;
           b = p.s;
           if(!query(1 , 1 , 1e6 , a , b))
            sol++;
        }
        cout<<sol<<"\n";
    }
    return 0;
}
