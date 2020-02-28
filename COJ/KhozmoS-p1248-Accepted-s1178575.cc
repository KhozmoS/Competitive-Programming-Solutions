#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

int a , b;
int mk[11];

int prince[5] , p_copy[5];
int princess[5];

bool ok()
{
    int cnt = 0;
    sort(princess , princess + 3);
    sort(p_copy , p_copy + 3);

    do{
        cnt = 0;
        if(p_copy[0] > princess[0]) cnt++;
        if(p_copy[1] > princess[1]) cnt++;
        if(p_copy[2] > princess[2]) cnt++;
        if(cnt < 2) return false;
    }while(next_permutation(princess , princess+3));

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>princess[0]>>princess[1]>>princess[2]>>prince[0]>>prince[1] && prince[1])
    {
        int ans = -1;
        for(int i = 1 ; i <= 52 ; i++)
        {
            if(i != princess[0] && princess[1] != i && princess[2] != i)
            {
                if(i != prince[0] && i != prince[1])
                {
                    p_copy[0] = prince[0];
                    p_copy[1] = prince[1];
                    p_copy[2] = i;
                    if(ok() && ans == -1)
                        ans = i;
                }
            }
        }
        cout<<ans<<"\n";
    }

}
