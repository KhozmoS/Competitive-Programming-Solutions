#include<bits/stdc++.h>

using namespace std;

typedef pair <int, int> par;

const int MAXN = 1e6 + 7;

int A[MAXN];
set <int> S;
vector <par> R;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> A[i];
        S.insert(A[i]);
    }

    int sol = 0;
    set <int> :: iterator it;
    for(it = S.begin(); it != S.end(); it++)
    {
        int x = (*it);
        int i = 1, j;
        while(i <= N)
        {
            j = i;
            bool esta = false;
            while(A[j] % x == 0 && j <= N)
            {
                if(A[j] == x)
                    esta = true;
                j++;
            }

            if(esta && sol < j - i)
            {
                sol = j - i;
                R.clear();
                R.push_back(par(i, j - 1));
            }
            else if(esta && sol == j - i)
                R.push_back(par(i, j - 1));

            i = j + 1;
        }
    }
    sort(R.begin(), R.end());
    cout << sol << ' ' << R.size() << "\n";
    for(int i = 0; i < R.size(); i++)
        cout << R[i].first << ' ' << R[i].second << "\n";

    return 0;
}


