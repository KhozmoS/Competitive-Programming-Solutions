#include<bits/stdc++.h>


#define n 10000005
using namespace std;
vector<int> triangular;
int arr[n];

void init()
{
    int suma = 1;
    for(int i=2; suma<n; i++){
        triangular.push_back(suma);
        suma += i;
    }
}

void solve()
{
    for(int i=0; i<n; i++) arr[i] = 0;
    
    int sum , tam = triangular.size();
    
    for(int i=0; i<tam; i++){
        for(int j=i; j<tam; j++){
            sum = triangular[i] + triangular[j];
            if(sum >= n) break;
            arr[sum] = 2;
        }
    }
    for(int i=0; i<tam; i++) arr[triangular[i]] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    init();
    solve();
    int N;
    while(cin >> N){
        if(arr[N] != 0) cout << arr[N] << "\n";
        else cout << "3\n";
    }
}
