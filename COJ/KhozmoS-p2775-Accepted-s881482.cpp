#include<bits/stdc++.h>

using namespace std;
  string cad,cad1;

int main ()
{
    int N;
    cin>>N;
    for(int t = 0 ; t < N ; t++){

  cin>>cad;
  int ta = cad.size();
      if(cad[0] != 'a' && cad[0] != 'e' && cad[0] != 'i' && cad[0] != 'o' && cad[0] != 'u'){
    for(int i = 1 ; i < ta ; i++){
        cad1 += cad[i];
    }
      cad1 += cad[0];
      cad1 +="ow";
       cout<<cad1<<endl;
      }
      else
      {
        cout<<cad + "cow"<<endl;
      }
  cad1 = "";
    }

    return 0;
}
