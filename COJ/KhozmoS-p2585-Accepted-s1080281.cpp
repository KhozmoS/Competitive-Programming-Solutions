#include <bits/stdc++.h>

using namespace std;

const int MAX = 55;

int ta[MAX];
vector<int> query;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string cad;
    cin>>cad;

    int t = cad.size();
    for(int i = 0 ; i < t ; i++)
    if(cad[i] == '#')
     query.push_back(i + 1);
    else
     ta[i + 1] += (ta[i] + 1);

     ta[t + 1] += ta[t];

    int x = 0;

    for(int i = 0 ; i < query.size() ; i++)
      x ^= ta[query[i] - 1];

    x ^= ta[t + 1];

    if(!query.size())
      {
        cout<<"Rabbit\n";
        return 0;
      }

    if(x)
      cout<<"Cat\n";
    else
      cout<<"Rabbit\n";

    return 0;
}
