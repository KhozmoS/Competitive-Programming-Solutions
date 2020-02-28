#include <bits/stdc++.h>

using namespace std;


int n , data[1005];

bool bsearch(int target){
        int left = 0;
        int right = n-1;
        while (left < right){
            int mid = (left + right) / 2;
            if (data[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return (data[left] == target);
}
bool mk[100005];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i = 0 ; i < n ; i++) cin>>data[i];
    vector <int> ans;
    for(int i = 0 ; i < n ; i++)
    {
        if(bsearch(data[i]) && !mk[data[i]]){
            ans.push_back(data[i]);
            mk[data[i]] = true;
        }
    }
    cout<<ans.size()<<"\n";
    for(int i = 0 ; i < ans.size() ; i++)
        cout<<ans[i]<<"\n";
}
