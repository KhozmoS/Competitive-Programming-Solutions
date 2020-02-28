#include <bits/stdc++.h>


using namespace std;


int ar[101] , freq[26] , n;


int get_div(int x)
{
    int res = 1;
    for(int i = 2 ; i <= x ; i++)
        if(x % i == 0)
          res++;

    return res;
}

vector <int> ans;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;;

    for(int i = 0 ; i < n ; i++)
          cin>>ar[i];
    sort(ar , ar + n , [&](int a , int b){return get_div(a) < get_div(b);});

    int sol = 0;

    for(int k = 0 ; k < n ; k++){

        ans.push_back(ar[k]);

    for(int i = 0 ; i < n ; i++){
        if(i == k) continue;

        bool flag = true;
        for(int j = 0 ; j < ans.size() ; j++)
           if(__gcd(ar[i] , ans[j]) != 1)
              flag = false;

       if(flag)
          ans.push_back(ar[i]);
    }
      int ta = ans.size();
      sol = max(sol ,ta);

      ans.clear();
    }
    cout<<sol<<"\n";
}
