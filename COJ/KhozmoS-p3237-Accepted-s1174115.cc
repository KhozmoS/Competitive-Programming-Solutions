#include<bits/stdc++.h>


using namespace std;
#define PB push_back
const int mod = 10007;
typedef unsigned long long ll;
typedef vector <ll> vi;

struct nod{

    char cad[7];

    int c;
    nod(char *ca , int cc)
    {
        c = cc;
        for(short i = 0 ; i < 7 ; i++) cad[i] = ca[i];
    }


     bool operator < (const nod &X)const {
        return c > X.c;
     }

};

bool is[10000005];
int ans;
short mk[10000005][7];
int tonum(char *x)
{
    int res = 0;
    for(int i = 0 ; i < strlen(x) ; i++)
        res = res*10 + x[i] - '0';
    return res;
}

void up(char *_1 , short i){
    _1[i] = char((_1[i] - '0' + 1)%10 + 48);
}
void down(char *_2 , short i){
    if(_2[i] == '0') _2[i] = '9';
    else _2[i] = char((_2[i] - '0' - 1) + 48);
}
void bfs(char *node , short sz)
{

    for(int i = 0 ; i < 10000005 ; i++)
        mk[i][sz] = 1005;


    priority_queue <nod> cola;
    cola.push(nod(node , 1));
    int idx = tonum(node);
    mk[idx][sz] = 1;

    while(!cola.empty())
    {
        char node[7];
        for(short i = 0 ; i < 7 ; i++) node[i] = cola.top().cad[i];
        short cost = cola.top().c;
        cola.pop();

        for(short i = 5 ; i > 5-sz ; i--)
        {
            
            down(node , i);
            int idx_2 = tonum(node);
            up(node , i);
            up(node , i);
            int idx_1 = tonum(node);
            
            //cout<<idx_1<<" "<<_1<<"\n";
            if(cost + 1 < mk[idx_1][sz])
            {
                if(!is[idx_1])
                {
                    cola.push(nod(node , 1));
                    mk[idx_1][sz] = 1;
                }
                else{
                    cola.push(nod(node , cost+1));
                    mk[idx_1][sz] = cost+1;
                }
            }
            down(node , i);
            down(node , i);
            if(cost + 1 < mk[idx_2][sz])
            {
                if(!is[idx_2])
                {
                    cola.push(nod(node , 1));
                    mk[idx_2][sz] = 1;
                }
                else{
                    cola.push(nod(node , cost+1));
                    mk[idx_2][sz] = cost+1;
                }
            }
            up(node , i);
        }
    }

}
int tonum1(string x , int k)
{
    int res = 0;
    for(int i = 0 ; i < k  ; i++)
        res = res*10 + x[i] - '0';
    return res;
}

char ini[6] = {'0' , '0' , '0' , '0' , '0' , '2'};

char ti[6];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    is[0] = true;
    is[1] = true;
    for(int i = 4 ; i < 10000000 ; i += 2)
        is[i] = true;
    for(int i = 3; i * i < 10000000 ; i += 2)
        if(!is[i])
            for(int j = i * i ; j < 10000000 ; j += i)
               is[j] = true;

    for(int i = 1 ; i <= 6 ; i++){
       for(int j = 0 ; j < 6 ; j++)
             ti[j] = ini[j];

             bfs(ti , i);
    }
    int t;

    cin>>t;

    while(t--)
    {
       string cad;int k;
       cad.reserve(7);
       cin>>k>>cad;
       ans = mk[tonum1(cad , k)][k] - 1;
       cout<<ans<<"\n";
    }
}
