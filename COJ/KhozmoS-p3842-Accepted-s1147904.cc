#include <bits/stdc++.h>

using namespace std;

int n,k,a,b;
vector < pair < int, int > >  x;
multiset < int > s;

int main(){

    scanf("%d%d", &n, &k);

    for (int i = 0 ; i < n ; i++){
        scanf("%d%d", &a, &b);
        x.push_back(make_pair(b,a));
    }

    sort (x.begin(), x.end());

    for (int i = 0 ; i < n - 1 ; i++){
        if (x[i].first == x[i + 1].first)swap(x[i], x[i + 1]);
    }

    int sol = 0;
    for (int i = 0 ; i < k ; i++){
        s.insert(0);
    }

    for (int i = 0 ; i < n ; i++){
        multiset < int >::iterator pos = s.lower_bound(x[i].second);

        if (pos != s.end() and x[i].second == *pos){
            s.erase(pos);
            s.insert(x[i].first);
            sol++;
        }
        else{
            if (pos != s.begin()){
                pos--;
                s.erase(pos);
                s.insert(x[i].first);
                sol++;
            }
        }
    }

    printf("%d\n", sol);

return 0;

}
