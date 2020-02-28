#include <bits/stdc++.h>

using namespace std;

struct par{
    int a, b;
    par(int aa, int bb){
        a = aa; b = bb;
    }
    par(){par(0, 0);}
    bool operator < (const par &p1) const{
        return b < p1.b;
    }
};

const int MAX = 1e5 + 5;


par arr[MAX];

multiset<int, greater<int> > fines;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, M;
    cin >>N >>M;

    for(int i = 0; i < N; i++){
        int a, b;
        cin >>a >>b;
        arr[i] = par(a, b);
    }

    int s = 0;

    sort(arr, arr+N);

    for(int i = 0; i < N; i++){
        auto itr = fines.lower_bound( arr[i].a );
        if(itr != fines.end()){
            fines.erase(itr);
            fines.insert(arr[i].b);
            s++;
        }else if(fines.size() < M){
            fines.insert(arr[i].b);
            s++;
        }
    }

    cout <<s <<"\n";
    return 0;
}

/*
5 2
1 2
2 3
3 5
4 5
2 2
*/
