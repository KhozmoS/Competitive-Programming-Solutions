#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
 int TA[MAXN];
 bool comp[MAXN + 3];
 vector<int>pri;
  void criba()
  {
	for(int i = 4 ; i < MAXN ; i += 2)
	comp[i] = true;
    for(int i = 3 ; i < MAXN ; i += 2)
    {
      if(!comp[i])
      {
      for(int j = i + i ; j < MAXN ; j += i)
    	  comp[j] = true;
      }
    }
    pri.push_back(2);
    comp[1] = true;
    for(int i = 3 ; i < MAXN ; i += 2)
    {
    	if(!comp[i])
    	 pri.push_back(i);
    }
  }
  void fact ()
  {

	  for(int i = 2; i <= 1000000; i++)
	  {

		  int e = 0;
		  int j = 0;
		  int n = i;
		  bool flag = false;
		  while(comp[n]){
			  e = 0;
		  while(n % pri[j] == 0)
		  {
			e++;
			n /= pri[j]	;
			if(e > 1)
			{
				flag = true;
				break;
			}
		  }
		  j++;
		  if(e > 1)
		  {
			TA[i] = 0;
			break;
		  }
		    if(e == 1){
		    TA[i]++;
		    e = 0;
		    }
		  }
		  if(!comp[n] && n != 1 && e <= 1)
			  TA[i]++;
	  }
  }
  int TA1[MAXN];
  int TA2[MAXN];
  int TA3[MAXN];
  int TA4[MAXN];
  int TA5[MAXN];
  int TA6[MAXN];
  int TA7[MAXN];
  void seven()
  {
    for(int i = 1 ; i < MAXN ; i++)
    {
       TA1[i] += TA1[i-1];
       TA2[i] += TA2[i-1];
       TA3[i] += TA3[i-1];
       TA4[i] += TA4[i-1];
       TA5[i] += TA5[i-1];
       TA6[i] += TA6[i-1];
       TA7[i] += TA7[i-1];
      if(TA[i] == 1)
      TA1[i]++;
      if(TA[i] == 2)
      TA2[i]++;
      if(TA[i] == 3)
      TA3[i]++;
      if(TA[i] == 4)
      TA4[i]++;
      if(TA[i] == 5)
      TA5[i]++;
      if(TA[i] == 6)
      TA6[i]++;
      if(TA[i] == 7)
      TA7[i]++;
    }
  }
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    criba();
    fact();
    seven();
    //cout<<TA[53]<<"this\n";
    int t , a , b , k;
    cin>>t;
    while(t--)
    {
      	cin>>a>>b>>k;
      	int sol = 0;
      	if(k == 1)
      	cout<<TA1[b] - TA1[a - 1]<<"\n";
      	if(k == 2)
      	cout<<TA2[b] - TA2[a - 1]<<"\n";
      	if(k == 3)
      	cout<<TA3[b] - TA3[a - 1]<<"\n";
      	if(k == 4)
      	cout<<TA4[b] - TA4[a - 1]<<"\n";
      	if(k == 5)
      	cout<<TA5[b] - TA5[a - 1]<<"\n";
      	if(k == 6)
      	cout<<TA6[b] - TA6[a - 1]<<"\n";
      	if(k == 7)
      	cout<<TA7[b] - TA7[a - 1]<<"\n";
      	if(k > 7)
      	cout<<0<<"\n";
    }

	return 0;
}
