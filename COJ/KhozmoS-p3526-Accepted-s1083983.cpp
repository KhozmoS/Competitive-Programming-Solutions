#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 5;
int n , ar[MAX + 5];
void update(int pos)
{
    for(int i = pos ; i > 0 ; i -= (i & -i))
        ar[i]++;

}
stack <int> pila;
int query(int pos)
{
    int sum = 0;

    for(int i = pos ; i <= MAX ; i += (i & -i))
        sum += ar[i];

    return sum;
}
int A[MAX];

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;

   for(int i = 0 ; i < n ; i++) cin>>A[i]; reverse(A , A + n);

   for(int i = 0 ; i < n ; i++)
   pila.push(query(A[i] + 1)) , update(A[i]);
   while(!pila.empty())
     cout<<pila.top()<<" " , pila.pop();
    return 0;
}
