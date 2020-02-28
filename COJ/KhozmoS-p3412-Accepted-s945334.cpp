#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;
int A[MAXN], abi[MAXN];
int n , m , mayi; int sol;

 void update(int pos , int val)
 {
     for(int i = pos ; i <= n ; i += (i & -i))
     abi[i] += val;
 }

 int sum(int a , int b)
 {
     int suma = 0; int sumb = 0;
     a--;
     for(int i = a ; i > 0 ; i -= (i & -i))
     suma += abi[i];
     for(int i = b ; i > 0 ; i -= (i & -i))
     sumb += abi[i];

     return sumb - suma;
 }
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

        cin>>n>>m;
        for(int i = 0 ; i < n ; i++){
         cin>>A[i];
        }
        bool flag = false;
        int sol = 0;
        for(int i = 0 ; i < n ; i++){
        int sum = 0;
        for(int j = i ; j < n ; j++)
        {
            sum += A[j];
            if(sum > m) break;

            if(sum == m)
            {
                sol = sum;
                flag = true;
                break;
            }
            if(sol < sum)
            sol = sum;
        }
        if(flag) break;
        }
        cout<<sol<<"\n";
        return 0;
}
