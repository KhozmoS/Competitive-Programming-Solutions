#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define PB push_back


typedef long long ll;
typedef vector <int> vi;

const int MAX = 1e6;

const ll mod = 1e9+7;

int ar[] = {1 , 2, 3, 4, 5, 6, 7, 8, 9};
int freq[11];

bool c(int x , int y)
{
    if(freq[x] == freq[y]) return x < y;
    return freq[x]<freq[y];
    return false;
}
int main()
{
  string cad;cin>>cad;

  for(int i = 0 ; i < cad.size() ; i++)
  {
    freq[cad[i]-'0']++;
  }
  //cout<<freq[9]<<"\n";
  for(int i = 0 ; i < 9 ; i++)
  {
    for(int j = i+1 ; j < 9 ; j++)
    {
        if(freq[ar[i]] < freq[ar[j]])
            swap(ar[i] , ar[j]);
        if(freq[ar[i]] == freq[ar[j]] && ar[i] > ar[j])
            swap(ar[i] , ar[j]);
    }
  }
  for(int i = 0 ; i < 9 ; i++)
    cout<<ar[i]<<(i==8?"\n":" ");
}
