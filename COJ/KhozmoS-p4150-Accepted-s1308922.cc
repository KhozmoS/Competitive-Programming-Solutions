#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define db double
#define all(c) (c).begin(),(c).end()
#define sz(c) (c).size()

typedef long long ll;
typedef pair <ll , ll> ii;
typedef pair <ii , int> iii;
typedef vector <int >vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const int MAX = 1e6+5;

ll ar[MAX];
int n;
ll even = 0;
ll odd = 0;
ll wood[3];
ll wood1[3];
void f(int lft , int rgt , int rmn , bool player)
{
    if(rmn <= 3)
    {
        wood[player] += ar[lft]+ar[rgt];
        wood[player^1] += (rmn==2?0:ar[lft+1]);
        return;
    }
    if(rmn == 4)
    {
        ll sm = max(ar[lft]+ar[rgt] , max(even , odd));
        wood[player] += sm;
        wood[player^1] += (even+odd-sm);
        return;
    }
    if((lft%2)!=(rgt%2))
    {
        int podd = (lft%2?lft:rgt);
        int peven = (lft%2?rgt:lft);
        ll fodd = odd-ar[podd];
        ll feven = even-ar[peven];
        if(ar[lft]+ar[rgt]+min(fodd,feven) > max(odd,even))
        {
            odd = fodd;
            even = feven;
            wood[player] += ar[lft]+ar[rgt];
            f(lft+1,rgt-1,rmn-2,player^1);
            return;
        }
        else if(odd>even)
        {
            if(lft%2)
            {
                odd -= ar[lft];
                wood[player] += ar[lft];
                f(lft+1,rgt,rmn-1,player^1);
                return;
            }
            if(rgt%2)
            {
                odd -= ar[rgt];
                wood[player] += ar[rgt];
                f(lft,rgt-1,rmn-1,player^1);
                return;
            }
        }
        else
        {
            if(lft%2==0)
            {
                even -= ar[lft];
                wood[player] += ar[lft];
                f(lft+1,rgt,rmn-1,player^1);
                return;
            }
            if(rgt%2==0)
            {
                even -= ar[rgt];
                wood[player] += ar[rgt];
                f(lft,rgt-1,rmn-1,player^1);
                return;
            }
        }
    }
    if(lft%2)
    {
        odd -= ar[lft]+ar[rgt];
        wood[player] += ar[lft]+ar[rgt];
        f(lft+1,rgt-1,rmn-2,player^1);
        return;
    }
    if(lft%2==0)
    {
        even -= ar[lft]+ar[rgt];
        wood[player] += ar[lft]+ar[rgt];
        f(lft+1,rgt-1,rmn-2,player^1);
        return ;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i = 1 ; i <= n ; i++){
        cin>>ar[i];
        if(i&1) odd+=ar[i];
        else even+=ar[i];
    }
  
    if(n==1)
    {
        cout<<max(even,odd)<<" "<<min(even,odd)<<"\n";
        return 0;
        
    }
    f(1, n , n , 0);
    even = 0;
    odd = 0;
    for(int i = n/2 ; i >= 1 ; i--)
    {
        int lft = i;
        int rgt = n-i+1;
        wood1[i&1] += ar[lft]+ar[rgt];
        if(i&1)
        {
            odd += ar[lft];
            even += ar[rgt];
        }
        else{
            even += ar[lft];
            odd += ar[rgt];
        }
        wood1[(i&1)] = max(max(odd,even) , wood1[(i&1)]);
        wood1[(i&1)^1] = min(min(odd,even) , wood1[(i&1)^1]);
    }
    
    if((n%5>=3 && (n%3)!=4) || n&1)
    {
        cout<<wood[0]<<" "<<wood[1]<<"\n";
    }
    else{
        cout<<wood1[1]<<" "<<wood1[0]<<"\n";
    }
    return 0;
}
