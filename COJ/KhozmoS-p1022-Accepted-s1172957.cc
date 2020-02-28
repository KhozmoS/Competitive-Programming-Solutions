#include<bits/stdc++.h>

using namespace std;

int ar[105] , t , n;

int main()
{
    cin>>t;

    while(t--)
    {
        cin>>n;
        int ans = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            cin>>ar[i];
            for(int j = i-1 ; j > 0 ; j--)
                if(ar[j] > ar[i])
                   ans++;
        }
        cout<<"Optimal train swapping takes "<<ans<<" swaps.\n";
    }

    /*
	int N, K;
	scanf("%d%d", &N, &K);
	vector<string> V(N);
	for (int i = 0; i < N; ++i) {
		cin >> V[i];
	}
	string ref = V[0];
	sort(ref.begin(), ref.end());
	int hr = 0;
	for (int i = 1; i < ref.size(); ++i) {
		if(ref[i] == ref[i-1])
			hr = 1;
	}
	for (int i = 0; i < N; ++i) {
		string t = V[i];
		sort(t.begin(), t.end());
		if(ref != t){
			cout << -1 << endl;
			return 0;
		}
	}
	vector<int> CNT(N, 0);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < V[0].size(); ++j) {
			if(V[0][j] != V[i][j])
				CNT[i]++;
		}
	}

	for (int i = 0; i < V[0].size(); ++i) {
		for (int j = i+1; j < V[0].size(); ++j) {
			char a = V[0][i];
			char b = V[0][j];
			for (int k = 0; k < N; ++k) {
				if(a != V[k][i])
					CNT[k]--;
				if(b != V[k][j])
					CNT[k]--;
			}
			swap(a, b);
			for (int k = 0; k < N; ++k) {
				if(a != V[k][i])
					CNT[k]++;
				if(b != V[k][j])
					CNT[k]++;
			}
			int mx = *max_element(CNT.begin(), CNT.end());
			int mn = *min_element(CNT.begin(), CNT.end());
			if(mx <= 2 && (mn >= 2 || hr)){
				string nr = V[0];
				swap(nr[i], nr[j]);
				cout << nr << endl;
				return 0;
			}
			for (int k = 0; k < N; ++k) {
				if(a != V[k][i])
					CNT[k]--;
				if(b != V[k][j])
					CNT[k]--;
			}
			swap(a, b);
			for (int k = 0; k < N; ++k) {
				if(a != V[k][i])
					CNT[k]++;
				if(b != V[k][j])
					CNT[k]++;
			}
		}
	}
	cout << -1 << endl;*/
	return 0;
}
