#include <bits/stdc++.h>

using namespace std;
 int main()
 {
  string num;
  int n;
  cin>>n;
    for(int j = 0;j < n;j++){
  int suma = 0;
  cin>>num;
  int ta = num.size();
    if(num[0] == '-'){
       for(int i = 1;i < ta ;i++)
          suma += num[i] - '0';
    }
    else{

    for(int i = 0; i < ta;i++)
        suma += num[i] - '0';
    }
        cout<< suma <<endl;
        suma = 0;
    }
    return 0;
}
