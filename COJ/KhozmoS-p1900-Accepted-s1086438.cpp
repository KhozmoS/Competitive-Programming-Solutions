/*alurquiza*/
//1900
#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1e3 + 5;
pair<int,int> S[SIZE];

int dist(int i,int j){
    return max(abs(S[i].first - S[j].first),abs(S[i].second - S[j].second));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int N,K;
    cin >> N >> K;

    for(int i = 1;i <= K;i++)
        cin >> S[i].first >> S[i].second;

    S[0].first = S[0].second = 1;
    S[++K].first = S[K].second = N;

    sort(S,S + K + 1);
    int sol = 1 << 20;
    do{

        int aux = 0;
        for(int i = 1;i <= K;i++)
            aux += dist(i,i - 1);

        sol = min(aux,sol);
    }while(next_permutation(S + 1,S + K));

    cout << sol << '\n';

    return 0;
}
