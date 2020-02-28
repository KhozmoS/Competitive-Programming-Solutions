#include <bits/stdc++.h>

using namespace std;
 int q,i;
 string cad;
  string MT(string cad){
    while(true){
        bool flag = false;
      switch(q){
  case 0 :
    if(cad[i] == 'a'){
        q = 1;
        flag = true;
        }
        break;
  case 1 :
     if(cad[i] == 'a'){
        cad[i] = 'X';
        i ++;
        q = 4;
        flag = true;

     }
     else if(cad[i] == 'Y'){
        i ++;
        q = 2;
        flag = true;
     }
     break;
  case 2 :
     if(cad[i] == 'Y' || cad[i] == 'Z' ){
        i ++;
        flag = true;
        break;
     }
     else if(cad[i] == 'a' || cad[i] == 'b' || cad[i] == 'c'){
        q = 3;
        break;
     }
  case 3 :
    break;
    case 4 :
         if(cad[i] == 'Y' || cad[i] == 'a'){
            i ++;
            flag = true;
         }
         else if(cad[i] == 'b')
         {
            cad[i] = 'Y';
            i ++;
            q = 5;
            flag = true;
         }
         break;
    case 5 :
        if(cad[i] == 'Z' || cad[i] == 'b'){
            i ++;
            flag = true;
        }
        else if(cad[i] == 'c'){
            cad[i] = 'Z';
            i --;
            q = 6;
            flag = true;
        }
        break;
    case 6 :
        if(cad[i] == 'a' || cad[i] == 'b' || cad[i] == 'Y' || cad[i] == 'Z'){
            i --;
            flag = true;
        }
        else if(cad[i] == 'X'){
            i ++;
            q = 1;
            flag = true;
        }
        break;

      }
       if(!flag)
        break;
    }
    return cad;
  }
int t;
int main()
{
    cin>>t;
    for(int j = 0; j < t; j++){
    cin>>cad;
    cad = MT(cad);
     cout<<'q'<<q<<" "<<cad<<endl;
     q = 0;
     i = 0;
    }
        return 0;
}
