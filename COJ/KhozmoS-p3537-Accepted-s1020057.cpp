#include <bits/stdc++.h>

using namespace std;

int N, SOL, K;
int arr[1007];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    while(K != N){

        for(int i = 0; i < N; i++)
            if(arr[i] <= K && arr[i] != -1){
                arr[i] = -1;
                K++;
            }
        if(K != N)SOL++;
        //cout << "K " << K << " SOL " << SOL << "\n";
        //system("pause");
        for(int i = N - 1; i >= 0; i--)
            if(arr[i] <= K && arr[i] != -1){
                arr[i] = -1;
                K++;
            }
        if(K != N)SOL++;
        //cout << "K " << K << " SOL " << SOL << "\n";
        //system("pause");
    }
    cout << SOL << "\n";

    return 0;
}
