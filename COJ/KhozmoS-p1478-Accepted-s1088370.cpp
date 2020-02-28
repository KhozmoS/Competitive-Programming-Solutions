#include <bits/stdc++.h>

using namespace std;

string a , b;
int i , j;
int ta , tb;
int D[1111][1111];

int F(int i ,int j)
{
    if(i == ta && j == tb)
    return a[i - 1] != b[j - 1];

    if(i == ta)
    return tb - j;

    if(j == tb)
    return ta - i;

    if(D[i][j] != -1) return D[i][j];

    if(a[i] == b[j]) return D[i][j] = F(i + 1 , j + 1);


    return D[i][j] = min (F(i , j + 1) + 1 , min(F(i + 1 , j) + 1,F(i + 1 , j + 1) + 1));
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

     memset(D , -1 , sizeof(D));

    cin>>a>>b;
    ta = a.size();
    tb = b.size();

    cout<<F(0 , 0);
    return 0;
}
