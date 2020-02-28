#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100005;

int S;string sol;
int ca , cb , na , nb;
vector <int> a, b;

bool flag;

bool ver(int x , int y)
{
    int caz , cbz , naz , nbz;



    caz = x / 9;
    cbz = y / 9;
    naz = x % 9;
    nbz = y % 9;


      ca = caz;
      cb = cbz;
      na = naz;
      nb = nbz;


   return true;
}

int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);


   while(cin>>S){

    if(!S) break;

        flag = false; ca = 0; cb = 0; na = 0; nb = 0;

     for(int i  = 0 ; i <= (S / 2) ; i++)
     {

       if(abs(i - (S - i)) % 11 == 0)
       {
              //cout<<i <<" "  <<(S - i)<<"\n";
             flag = ver(i , (S - i));
       }

     }

   //   cout<<ca<<" "<<cb<<"\n";
             if(!flag)
                cout<<"-1";
             else
             {
               if(ca > cb)
                flag = false;
               if(ca == cb && na < nb)
                flag = false;

             if(flag)
              {
           if(nb){
             a.push_back(nb);
             b.push_back(na);
           }

           while(cb > 0)
           {
             if(cb - ca < 2 && ca){

               a.push_back(9);
               b.push_back(9);
               cb--;
               ca--;
             }
             else if(cb - ca < 2 && !ca){

               a.push_back(9);

               cb--;
              }
             else
             {
              if(!nb && na){
              a.push_back(9);
              b.push_back(na);
              na = 0;
              }
              else{
               a.push_back(9);
               b.push_back(0);
              }

              cb--;
             }
           }
         }
         else
            {
           if(na)
            {
                a.push_back(na);
                b.push_back(nb);
            }

           while(ca > 0)
           {
             if(ca - cb < 2 && cb){
              a.push_back(9);
              b.push_back(9);
               cb--;
               ca--;
             }
             else if(ca - cb < 2 && !cb){
               a.push_back(9);

               ca--;
              }
             else
             {
               if(!na && nb){
                a.push_back(9);
                b.push_back(nb);
                nb = 0;
               }
              else{
              a.push_back(9);
              b.push_back(0);
              }
              ca--;
             }
           }
         }
             }
            sort(a.begin() , a.end());

            sort(b.begin() , b.end());

               int tb = b.size();
             for(int i = 0 ; i < a.size() ; i++)
             {
                 if(i != tb)
                 cout<<a[i]<<b[i];
                 else
                 cout<<a[i];
             }
             cout<<"\n";
             a.clear();
             b.clear();

     }
     int im = 4,  pa = 2;


   /*  for(int i = 0 ; i < sol.size() ; i++)
     if(i % 2 == 0)
      im += 9;
     else
      pa += 9;

     if((im - pa) % 11)
        cout<<"NO";
     else
        cout<<"YeS";*/

    return 0;
}
