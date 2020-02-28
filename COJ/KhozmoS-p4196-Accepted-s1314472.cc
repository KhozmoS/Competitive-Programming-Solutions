#include <bits/stdc++.h>

using namespace std;

int rev[5005][5005][2];
int op[5005];
bool mko[5005];
int cl[5005];
bool mkc[5005];

string cad;
int main()
{
    cad.reserve(5005);
    cin>>cad;
    cad = " "+cad;
    int n = cad.size()-1;
    for(int i = 1 ; i <= n ; i++){
        int o = 0;
        int c = 0;
        for(int j = i ; j <= n ; j++){
            o += (cad[j]=='(' ? -1 : 1);
            if(o == -1)
            {
                c++;
                o = 0;
            }
            rev[i][j][0] = o;
            rev[i][j][1] = c;
        }
    }
    int o = 0;
    int c = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        o += (cad[i]=='(' ? 1 : -1);
        if(o == -1)
        {
            c++;
            o = 0;
        }
        op[i] = o;
        mko[i] = c;
    }
    o = 0;
    c = 0;
    for(int i = n ; i >= 1 ; i--)
    {
        o += (cad[i]=='(' ? -1 : 1);
        if(o == -1)
        {
            c++;
            o = 0;
        }
        cl[i] = o;
        mkc[i] = c;
    }
    if(op[n]==0 && !mko[n])
    {
        cout<<"possible\n";
        return 0;
    }
    //cout<<op[2]<<" "<<rev[3][3][0]<<" "<<rev[3][3][1]<<" "<<cl[4]<<"\n";
    for(int i = 1; i <= n ; i++)
        for(int j = i ; j <= n ; j++)
        {
            if(!mko[i-1] && !mkc[j+1] && op[i-1]==(rev[i][j][1]+(cl[j+1]-rev[i][j][0])) && (cl[j+1]>=rev[i][j][0]))
            {
                //cout<<cl[j+1]<<" "<<rev[i][j][0]<<" "<<i<<" "<<j<<"\n";
                cout<<"possible\n";
                return 0;
            }
        }
    cout<<"impossible\n";
}
