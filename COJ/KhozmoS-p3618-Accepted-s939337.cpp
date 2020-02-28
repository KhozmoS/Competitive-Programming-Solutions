#include <bits/stdc++.h>

using namespace std;
//vector <int> div;
string cad;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    /*
    cin>>cad;
    int ta = cad.size();

    div.push_back(1);
    for(int i = 2 ; i <= ta / 2 ; i++)
    if(ta % i == 0)
    div.push_back(i);


    for(int i = 0 ; i < div.size() ; i++)
    {
        int s = div[i];
        int k = 0;
        while(k + s <= ta - s)
        {

        }
    }
    */
    int t , n;
    cin>>t;
    while(t--)
{
    cin>>n;
    if(n == 3)
    cout<<"12\n";
    else{
    n += 1;
    n /= 2;
    cout<<2 *(n + 1)<<"\n";
    }

}
    return 0;
}
