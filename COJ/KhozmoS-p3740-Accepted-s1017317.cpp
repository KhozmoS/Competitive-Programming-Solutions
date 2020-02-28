#include <bits/stdc++.h>

using namespace std;
const int MAXN = 111111;
typedef long long LL;
int porgusto;
int t , n;
int arr[MAXN];

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  /*  int a[MAXN];
    a[0] = 1; a[1] = 2;
    swap(a[0] , a[1]);
    cout<<a[0]<<" "<<a[1];*/
    cin>>t;

    while(t--)
    {
        cin>>n;
        int pos;
        for(int i = 0 ; i < n ; i++){

        cin>>arr[i];
        if(arr[i] == 1)
        pos = i;

        }
        int sol = 0;
        for(int i = 0 ; i < n ; i++)
        {
         if(arr[pos % n] == n) break;

        int com;
        if(pos == 0) com = n - 1;
        else com = pos - 1;

         if(arr[pos % n] + 1 != arr[(pos + 1) % n] || arr[pos % n] + 1 == arr[com % n] || (arr[pos % n] == 1 && arr[(pos + 1) % n] == n) )
         {
           if(arr[pos % n] == 1 && arr[(pos + 1) % n ] == n && n != 2)
           {
             swap(arr[pos % n] , arr[(pos + 1) % n ]);
             sol += 2;
           }
           else if(arr[pos % n] + 1 == arr[com % n] && n != 2)
           {
              swap(arr[pos % n] , arr[com % n]);
              sol += 2;
              pos--;
           }
           else if(arr[pos % n] + 1 != arr[(pos + 1) % n])
           {
             swap(arr[(pos + 1) % n] , arr[(pos + 2) % n]);
             sol += 2;
           }
         }
          pos++;

          //cout<<sol<<'\n';
        }
        cout<<sol<<"\n";
    }

    return 0;
}
